package alternative_bots_1;

import java.util.Random;

import battlecode.common.Clock;
import battlecode.common.Direction;
import battlecode.common.GameActionException;
import battlecode.common.MapInfo;
import battlecode.common.MapLocation;
import battlecode.common.PaintType;
import battlecode.common.RobotController;
import battlecode.common.RobotInfo;
import battlecode.common.UnitType;

/**
 * RobotPlayer — pragmatic strategy v3
 */
public class RobotPlayer {

    static int turnCount = 0;
    static int spawnCount = 0;
    static MapLocation baseLoc = null;
    static MapLocation exploreTarget = null;
    static int stuckCount = 0;

    static boolean sectorInit = false;
    static int sectorCols = 1;
    static int sectorRows = 1;
    static int sectorCol = 0;
    static int sectorRow = 0;

    static final int SECTOR_SIZE = 6;
    static final int SECTOR_REACH_DIST = 4;
    static final int SPLASH_MIN_SCORE = 3;
    static final int DEFENSIVE_PHASE = 200;

    static final Random rng = new Random(6147);
    static final Direction[] directions = {
            Direction.NORTH, Direction.NORTHEAST, Direction.EAST, Direction.SOUTHEAST,
            Direction.SOUTH, Direction.SOUTHWEST, Direction.WEST, Direction.NORTHWEST
    };

    static void initSectors(RobotController rc) {
        if (sectorInit) return;
        sectorCols = Math.max(1, (rc.getMapWidth() + SECTOR_SIZE - 1) / SECTOR_SIZE);
        sectorRows = Math.max(1, (rc.getMapHeight() + SECTOR_SIZE - 1) / SECTOR_SIZE);
        int id = rc.getID();
        sectorCol = id % sectorCols;
        sectorRow = (id / sectorCols) % sectorRows;
        sectorInit = true;
    }

    static void nextSector() {
        if (sectorRow % 2 == 0) {
            sectorCol++;
            if (sectorCol >= sectorCols) {
                sectorCol = sectorCols - 1;
                sectorRow++;
                if (sectorRow >= sectorRows) sectorRow = 0;
            }
        } else {
            sectorCol--;
            if (sectorCol < 0) {
                sectorCol = 0;
                sectorRow++;
                if (sectorRow >= sectorRows) sectorRow = 0;
            }
        }
    }

    static MapLocation sectorCenter(RobotController rc) {
        int cx = Math.min(sectorCol * SECTOR_SIZE + SECTOR_SIZE / 2, rc.getMapWidth() - 1);
        int cy = Math.min(sectorRow * SECTOR_SIZE + SECTOR_SIZE / 2, rc.getMapHeight() - 1);
        return new MapLocation(cx, cy);
    }

    static boolean moveToward(RobotController rc, MapLocation target) throws GameActionException {
        if (rc.getMovementCooldownTurns() >= 10) return false;
        MapLocation me = rc.getLocation();
        if (me.equals(target)) return false;
        Direction d = me.directionTo(target);
        if (rc.canMove(d)) { rc.move(d); return true; }
        if (rc.canMove(d.rotateLeft())) { rc.move(d.rotateLeft()); return true; }
        if (rc.canMove(d.rotateRight())) { rc.move(d.rotateRight()); return true; }
        if (rc.canMove(d.rotateLeft().rotateLeft())) { rc.move(d.rotateLeft().rotateLeft()); return true; }
        if (rc.canMove(d.rotateRight().rotateRight())) { rc.move(d.rotateRight().rotateRight()); return true; }
        return false;
    }

    static boolean moveRandom(RobotController rc) throws GameActionException {
        if (rc.getMovementCooldownTurns() >= 10) return false;
        int s = rng.nextInt(8);
        for (int i = 0; i < 8; i++) {
            Direction d = directions[(s + i) % 8];
            if (rc.canMove(d)) { rc.move(d); return true; }
        }
        return false;
    }

    static boolean doSectorMove(RobotController rc) throws GameActionException {
        if (rc.getMovementCooldownTurns() >= 10) return false;
        MapLocation me = rc.getLocation();
        if (exploreTarget == null || me.distanceSquaredTo(exploreTarget) <= SECTOR_REACH_DIST) {
            nextSector();
            exploreTarget = sectorCenter(rc);
            stuckCount = 0;
        }
        if (moveToward(rc, exploreTarget)) { stuckCount = 0; return true; }
        stuckCount++;
        if (stuckCount >= 3) {
            nextSector();
            exploreTarget = sectorCenter(rc);
            stuckCount = 0;
        }
        moveRandom(rc);
        return true;
    }

    static MapLocation findBestEmptyCluster(RobotController rc) throws GameActionException {
        MapInfo[] all = rc.senseNearbyMapInfos();
        MapLocation best = null;
        int bestCount = 0;
        for (MapInfo center : all) {
            if (!center.isPassable() || center.hasRuin()) continue;
            if (center.getPaint().isAlly()) continue;
            MapLocation cloc = center.getMapLocation();
            int count = 0;
            for (MapInfo n : all) {
                if (!n.isPassable() || n.hasRuin()) continue;
                if (n.getPaint() == PaintType.EMPTY && cloc.distanceSquaredTo(n.getMapLocation()) <= 8) count++;
            }
            if (count > bestCount) { bestCount = count; best = cloc; }
        }
        return best;
    }

    @SuppressWarnings("unused")
    public static void run(RobotController rc) throws GameActionException {
        while (true) {
            turnCount++;
            try {
                switch (rc.getType()) {
                    case SOLDIER: runSoldier(rc); break;
                    case MOPPER: runMopper(rc); break;
                    case SPLASHER: runSplasher(rc); break;
                    default: runTower(rc); break;
                }
            } catch (GameActionException e) {
                System.out.println("GameActionException");
                e.printStackTrace();
            } catch (Exception e) {
                System.out.println("Exception");
                e.printStackTrace();
            } finally {
                Clock.yield();
            }
        }
    }

    // Tower
    public static void runTower(RobotController rc) throws GameActionException {
        int round = rc.getRoundNum();
        UnitType toBuild;
        if (round <= DEFENSIVE_PHASE) {
            toBuild = (spawnCount % 5 == 2) ? UnitType.SPLASHER : UnitType.SOLDIER;
        } else {
            int idx = spawnCount % 5;
            toBuild = (idx == 1) ? UnitType.SPLASHER : (idx == 3) ? UnitType.MOPPER : UnitType.SOLDIER;
        }

        boolean built = false;
        for (Direction d : directions) {
            MapLocation next = rc.getLocation().add(d);
            if (rc.canBuildRobot(toBuild, next)) {
                rc.buildRobot(toBuild, next);
                spawnCount++;
                built = true;
                break;
            }
        }
        if (!built) System.out.println("[Tower] build blocked round=" + round + " type=" + toBuild);

        for (RobotInfo e : rc.senseNearbyRobots(-1, rc.getTeam().opponent())) {
            if (rc.canAttack(e.getLocation())) { rc.attack(e.getLocation()); break; }
        }

        for (MapInfo tile : rc.senseNearbyMapInfos()) {
            if (!tile.hasRuin()) continue;
            MapLocation r = tile.getMapLocation();
            if (rc.canCompleteTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, r))
                rc.completeTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, r);
            else if (rc.canCompleteTowerPattern(UnitType.LEVEL_ONE_MONEY_TOWER, r))
                rc.completeTowerPattern(UnitType.LEVEL_ONE_MONEY_TOWER, r);
        }

        rc.setIndicatorString("[Tower] rnd=" + round + " next=" + toBuild + " total=" + spawnCount);
    }

    // Soldier
    public static void runSoldier(RobotController rc) throws GameActionException {
        MapLocation me = rc.getLocation();
        if (baseLoc == null) {
            baseLoc = me;
            initSectors(rc);
            exploreTarget = sectorCenter(rc);
        }

        for (MapInfo tile : rc.senseNearbyMapInfos()) {
            if (tile.hasRuin()) {
                MapLocation r = tile.getMapLocation();
                if (rc.canCompleteTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, r))
                    rc.completeTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, r);
            }
        }

        soldierMove(rc);
        soldierAction(rc);
        rc.setIndicatorString("[Soldier] sec=(" + sectorCol + "," + sectorRow + ") tgt=" + exploreTarget);
    }

    static void soldierMove(RobotController rc) throws GameActionException {
        if (rc.getMovementCooldownTurns() >= 10) return;
        MapLocation me = rc.getLocation();

        RobotInfo closest = findClosestEnemy(rc, me);
        if (closest != null && moveToward(rc, closest.getLocation())) return;

        MapLocation enemyPaint = findNearestEnemyPaintTile(rc, me);
        if (enemyPaint != null && moveToward(rc, enemyPaint)) return;

        MapLocation emptyCluster = findBestEmptyCluster(rc);
        if (emptyCluster != null && moveToward(rc, emptyCluster)) return;

        doSectorMove(rc);
    }

    static void soldierAction(RobotController rc) throws GameActionException {
        if (rc.getActionCooldownTurns() >= 10 || rc.getPaint() <= 0) return;
        MapLocation me = rc.getLocation();
        MapInfo[] nearby = rc.senseNearbyMapInfos(me, 9);

        RobotInfo[] enemies = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
        for (RobotInfo e : enemies) {
            if (rc.canAttack(e.getLocation())) { rc.attack(e.getLocation()); return; }
        }

        MapLocation enemyTile = findNearestEnemyPaintInRange(nearby, me, rc);
        if (enemyTile != null && rc.canAttack(enemyTile)) { rc.attack(enemyTile); return; }

        MapInfo cur = rc.senseMapInfo(me);
        if (!cur.getPaint().isAlly() && rc.canAttack(me)) { rc.attack(me); return; }

        MapLocation gap = findGapTile(nearby, me, rc);
        if (gap != null && rc.canAttack(gap)) { rc.attack(gap); return; }

        MapLocation fb = findNearestPaintableNonAlly(nearby, me, rc);
        if (fb != null && rc.canAttack(fb)) { rc.attack(fb); return; }
    }

    // Splasher
    public static void runSplasher(RobotController rc) throws GameActionException {
        MapLocation me = rc.getLocation();
        if (baseLoc == null) {
            baseLoc = me;
            initSectors(rc);
            exploreTarget = sectorCenter(rc);
        }

        if (rc.getActionCooldownTurns() < 10 && rc.getPaint() >= 50) {
            MapLocation best = null;
            int max = SPLASH_MIN_SCORE - 1;
            for (MapInfo tile : rc.senseNearbyMapInfos(me, 4)) {
                MapLocation loc = tile.getMapLocation();
                if (!rc.canAttack(loc) || !tile.isPassable() || tile.hasRuin()) continue;
                int score = 0;
                for (MapInfo s : rc.senseNearbyMapInfos(loc, 2)) {
                    if (!s.isPassable() || s.hasRuin()) continue;
                    PaintType p = s.getPaint();
                    if (p == PaintType.EMPTY) score++;
                    else if (p.isEnemy()) score += 5;
                    else if (p.isAlly()) score -= 3;
                }
                for (RobotInfo r : rc.senseNearbyRobots(loc, 2, rc.getTeam().opponent())) {
                    UnitType t = r.getType();
                    if (t != UnitType.SOLDIER && t != UnitType.MOPPER && t != UnitType.SPLASHER) score += 50;
                }
                if (score > max) { max = score; best = loc; }
            }
            if (best != null) { rc.attack(best); rc.setIndicatorString("[Splasher] ATK score=" + max); }
            else rc.setIndicatorString("[Splasher] no worthy target");
        }

        if (rc.getMovementCooldownTurns() >= 10) return;
        if (rc.getPaint() < 50) {
            MapLocation refill = findRefillTarget(rc);
            if (refill != null) moveToward(rc, refill);
            else moveRandom(rc);
            return;
        }

        MapLocation cluster = findBestEnemyPaintCluster(rc, me);
        if (cluster != null && moveToward(rc, cluster)) return;

        RobotInfo closest = findClosestEnemy(rc, me);
        if (closest != null && moveToward(rc, closest.getLocation())) return;

        MapLocation ec = findBestEmptyCluster(rc);
        if (ec != null && moveToward(rc, ec)) return;

        doSectorMove(rc);
    }

    // Mopper
    public static void runMopper(RobotController rc) throws GameActionException {
        MapLocation me = rc.getLocation();
        if (baseLoc == null) {
            baseLoc = me;
            initSectors(rc);
            exploreTarget = sectorCenter(rc);
        }

        RobotInfo closest = findClosestEnemy(rc, me);
        if (closest != null) {
            int d = me.distanceSquaredTo(closest.getLocation());
            if (rc.getMovementCooldownTurns() < 10 && d > 2) moveToward(rc, closest.getLocation());
            me = rc.getLocation();
            Direction dirToE = me.directionTo(closest.getLocation());
            if (rc.getActionCooldownTurns() < 10) {
                if (rc.canMopSwing(dirToE)) { rc.mopSwing(dirToE); rc.setIndicatorString("[Mopper] swing"); return; }
                if (rc.canAttack(closest.getLocation())) { rc.attack(closest.getLocation()); rc.setIndicatorString("[Mopper] attack"); return; }
            }
        }

        MapLocation ep = findNearestEnemyPaintTile(rc, me);
        if (ep != null) {
            if (rc.getMovementCooldownTurns() < 10) { moveToward(rc, ep); me = rc.getLocation(); }
            Direction toEP = me.directionTo(ep);
            if (rc.getActionCooldownTurns() < 10) {
                if (rc.canMopSwing(toEP)) { rc.mopSwing(toEP); return; }
                if (rc.canAttack(ep)) { rc.attack(ep); return; }
            }
        }

        if (rc.getMovementCooldownTurns() < 10) doSectorMove(rc);
        rc.setIndicatorString("[Mopper] sweep sec=(" + sectorCol + "," + sectorRow + ")");
    }

    // Utilities
    static MapLocation findBestEnemyPaintCluster(RobotController rc, MapLocation me) throws GameActionException {
        MapInfo[] all = rc.senseNearbyMapInfos();
        MapLocation best = null;
        int bestCount = 0;
        for (MapInfo center : all) {
            if (!center.isPassable() || center.hasRuin() || !center.getPaint().isEnemy()) continue;
            MapLocation cloc = center.getMapLocation();
            int count = 0;
            for (MapInfo n : all)
                if (n.isPassable() && !n.hasRuin() && n.getPaint().isEnemy() && cloc.distanceSquaredTo(n.getMapLocation()) <= 8)
                    count++;
            if (count > bestCount) { bestCount = count; best = cloc; }
        }
        if (best == null) return findNearestEnemyPaintTile(rc, me);
        return best;
    }

    static MapLocation findNearestEnemyPaintTile(RobotController rc, MapLocation me) throws GameActionException {
        MapLocation nearest = null;
        int min = Integer.MAX_VALUE;
        for (MapInfo t : rc.senseNearbyMapInfos())
            if (t.getPaint().isEnemy()) {
                int d = me.distanceSquaredTo(t.getMapLocation());
                if (d < min) { min = d; nearest = t.getMapLocation(); }
            }
        return nearest;
    }

    static MapLocation findNearestEnemyPaintInRange(MapInfo[] nearby, MapLocation me, RobotController rc) {
        MapLocation nearest = null;
        int min = Integer.MAX_VALUE;
        for (MapInfo t : nearby)
            if (t.getPaint().isEnemy() && rc.canAttack(t.getMapLocation())) {
                int d = me.distanceSquaredTo(t.getMapLocation());
                if (d < min) { min = d; nearest = t.getMapLocation(); }
            }
        return nearest;
    }

    static MapLocation findGapTile(MapInfo[] nearby, MapLocation me, RobotController rc) {
        MapLocation best = null;
        int bestDist = Integer.MAX_VALUE;
        for (MapInfo tile : nearby) {
            if (tile.getPaint().isAlly() || !tile.isPassable() || tile.hasRuin()) continue;
            MapLocation loc = tile.getMapLocation();
            if (!rc.canAttack(loc)) continue;
            boolean nextToAlly = false;
            for (MapInfo other : nearby)
                if (other.getPaint().isAlly() && loc.distanceSquaredTo(other.getMapLocation()) <= 2) { nextToAlly = true; break; }
            if (!nextToAlly) continue;
            int d = me.distanceSquaredTo(loc);
            if (d < bestDist) { bestDist = d; best = loc; }
        }
        return best;
    }

    static MapLocation findNearestPaintableNonAlly(MapInfo[] nearby, MapLocation me, RobotController rc) {
        MapLocation nearest = null;
        int min = Integer.MAX_VALUE;
        for (MapInfo t : nearby) {
            if (t.getPaint().isAlly() || !t.isPassable() || t.hasRuin()) continue;
            MapLocation loc = t.getMapLocation();
            if (!rc.canAttack(loc)) continue;
            int d = me.distanceSquaredTo(loc);
            if (d < min) { min = d; nearest = loc; }
        }
        return nearest;
    }

    static MapLocation findRefillTarget(RobotController rc) throws GameActionException {
        MapLocation me = rc.getLocation();
        MapLocation nearest = null;
        int min = Integer.MAX_VALUE;
        for (RobotInfo ally : rc.senseNearbyRobots(-1, rc.getTeam())) {
            UnitType t = ally.getType();
            if (t == UnitType.SOLDIER || t == UnitType.MOPPER || t == UnitType.SPLASHER) continue;
            int d = me.distanceSquaredTo(ally.getLocation());
            if (d < min) { min = d; nearest = ally.getLocation(); }
        }
        return nearest;
    }

    static RobotInfo findClosestEnemy(RobotController rc, MapLocation me) throws GameActionException {
        RobotInfo[] enemies = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
        if (enemies.length == 0) return null;
        RobotInfo closest = enemies[0];
        int min = me.distanceSquaredTo(closest.getLocation());
        for (RobotInfo e : enemies) {
            int d = me.distanceSquaredTo(e.getLocation());
            if (d < min) { min = d; closest = e; }
        }
        return closest;
    }
}