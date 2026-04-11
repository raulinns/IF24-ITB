package main_bot;

import battlecode.common.*;

public class MopperStrategy {

    static MapLocation homeTower = null;
    static MapLocation currentRefillTarget = null;
    static int refillStuckTimer = 0;

    static final int MAX_ENEMY_TARGETS = 6;
    static MapLocation[] enemyAreaTargets = new MapLocation[MAX_ENEMY_TARGETS];
    static int enemyTargetCount = 0;

    static MapLocation moppingCenter = null;
    static int moppedTilesCount = 0;
    static int lastMopRound = -1;

    public static void run(RobotController rc) throws GameActionException {
        if (homeTower == null) homeTower = Navigation.findNearestAllyTower(rc);

        readMessages(rc);

        boolean withdrew = Navigation.tryWithdrawFromTower(rc);
        if (withdrew) {
            refillStuckTimer = 0;
            currentRefillTarget = null;
        }

        MapInfo[] nearby = rc.senseNearbyMapInfos();

        if (Constants.paintPersentage(rc) < Constants.PAINT_EMERGENCY) {
            runRefill(rc, true);
            return;
        }

        if (needsRefill(rc)) {
            boolean gaveUp = runRefill(rc, false);
            if (!gaveUp) return;
        } else {
            refillStuckTimer = 0;
        }

        checkAndBroadcastCleared(rc, nearby);

        if (tryTransferToAlly(rc)) return;

        if (tryOptimalMopSwing(rc)) return;

        MapLocation mopTarget = findBestMopTarget(rc, nearby);
        if (mopTarget != null) {
            if (rc.getLocation().distanceSquaredTo(mopTarget) <= 2 && rc.isActionReady()) {
                if (rc.canAttack(mopTarget)) {
                    rc.attack(mopTarget);

                    if (moppingCenter == null) moppingCenter = rc.getLocation();
                    moppedTilesCount++;
                    lastMopRound = rc.getRoundNum();
                    rc.setIndicatorString("Mopping " + mopTarget + " #" + moppedTilesCount);
                }
            } else {

                if (Constants.paintPersentage(rc) < 0.30 && isInEnemyTerritoryDeep(nearby)) {
                    rc.setIndicatorString("Mopper: low paint, avoid deep enemy territory");
                    Navigation.moveAway(rc, mopTarget);
                } else {
                    Navigation.moveTo(rc, mopTarget);
                }
            }
            return;
        }

        MapLocation enemyArea = findBestEnemyAreaTarget(rc, nearby);
        if (enemyArea != null) {
            rc.setIndicatorString("→ enemy area " + enemyArea);
            Navigation.moveTo(rc, enemyArea);

            if (rc.getLocation().distanceSquaredTo(enemyArea) <= 4) {
                removeEnemyTarget(enemyArea);
            }
            return;
        }

        MapLocation nearest = findNearestEnemyPaint(nearby, rc.getLocation());
        if (nearest != null) Navigation.moveTo(rc, nearest);
        else Navigation.moveRandom(rc);
    }

    private static void checkAndBroadcastCleared(RobotController rc, MapInfo[] nearby)
            throws GameActionException {
        if (moppingCenter == null || moppedTilesCount < Constants.MIN_MOP_BEFORE_CLEAR) return;

        if (lastMopRound > 0 && rc.getRoundNum() - lastMopRound > 10) {
            resetMoppingSession();
            return;
        }

        int enemyRemaining = 0;
        for (MapInfo t : nearby) {
            if (!t.isWall()
                    && !t.hasRuin()
                    && t.getPaint().isEnemy()
                    && moppingCenter.distanceSquaredTo(t.getMapLocation()) <= 8) {
                enemyRemaining++;
            }
        }

        if (enemyRemaining <= 2) {

            broadcastClearedArea(rc, moppingCenter);
            rc.setIndicatorString("Area CLEARED @ " + moppingCenter + " → Scout incoming");
            resetMoppingSession();

            removeEnemyTarget(moppingCenter);
        }
    }

    private static void broadcastClearedArea(RobotController rc, MapLocation loc)
            throws GameActionException {
        int msg = Constants.encodePos(Constants.MSG_CLEARED_AREA, loc);
        RobotInfo[] allies = rc.senseNearbyRobots(-1, rc.getTeam());
        for (RobotInfo a : allies) {
            if (a.getType().isTowerType() && rc.canSendMessage(a.getLocation(), msg)) {
                rc.sendMessage(a.getLocation(), msg);
                return;
            }
        }
    }

    private static void resetMoppingSession() {
        moppingCenter = null;
        moppedTilesCount = 0;
        lastMopRound = -1;
    }

    private static MapLocation findBestEnemyAreaTarget(RobotController rc, MapInfo[] nearby)
            throws GameActionException {
        if (enemyTargetCount == 0) return null;

        MapLocation myLoc = rc.getLocation();
        MapLocation best = null;
        int bestScore = Integer.MIN_VALUE;

        for (int i = 0; i < enemyTargetCount; i++) {
            MapLocation target = enemyAreaTargets[i];
            if (target == null) continue;

            int dist = myLoc.distanceSquaredTo(target);
            int score = -dist / 4;

            if (dist <= Constants.VISION_RADIUS) {
                int enemyCount = 0;
                for (MapInfo t : nearby) {
                    if (!t.isWall()
                            && !t.hasRuin()
                            && t.getPaint().isEnemy()
                            && target.distanceSquaredTo(t.getMapLocation()) <= 8) {
                        enemyCount++;
                    }
                }
                if (enemyCount == 0) {
                    removeEnemyTarget(target);
                    i--;
                    continue;
                }
                score += enemyCount * 5;
            }

            if (score > bestScore) {
                bestScore = score;
                best = target;
            }
        }
        return best;
    }

    private static MapLocation findBestMopTarget(RobotController rc, MapInfo[] nearby)
            throws GameActionException {
        MapLocation myLoc = rc.getLocation();
        Team enemy = rc.getTeam().opponent();
        MapLocation best = null;
        int bestScore = 0;

        for (MapInfo tile : nearby) {
            if (tile.isWall() || tile.hasRuin()) continue;
            if (!tile.getPaint().isEnemy()) continue;

            MapLocation loc = tile.getMapLocation();
            int score = Constants.W_ENEMY_PAINT_MOPPER;

            if (myLoc.distanceSquaredTo(loc) <= 2) {
                RobotInfo ri = rc.senseRobotAtLocation(loc);
                if (ri != null && ri.getTeam() == enemy) score += Constants.W_ENEMY_ROBOT_MOPPER;
            }

            score -= myLoc.distanceSquaredTo(loc);

            if (score > bestScore) {
                bestScore = score;
                best = loc;
            }
        }
        return best;
    }

    private static MapLocation findNearestEnemyPaint(MapInfo[] nearby, MapLocation myLoc) {
        MapLocation best = null;
        int bestDist = Integer.MAX_VALUE;
        for (MapInfo tile : nearby) {
            if (!tile.getPaint().isEnemy()) continue;
            int d = myLoc.distanceSquaredTo(tile.getMapLocation());
            if (d < bestDist) {
                bestDist = d;
                best = tile.getMapLocation();
            }
        }
        return best;
    }

    private static boolean tryOptimalMopSwing(RobotController rc) throws GameActionException {
        if (!rc.isActionReady()) return false;
        Direction bestDir = null;
        int bestCount = 1;
        for (Direction d : Constants.CARDINALS) {
            if (!rc.canMopSwing(d)) continue;
            int count = countEnemiesInSwingPath(rc, d);
            if (count > bestCount) {
                bestCount = count;
                bestDir = d;
            }
        }
        if (bestDir != null) {
            rc.mopSwing(bestDir);
            if (moppingCenter == null) moppingCenter = rc.getLocation();
            moppedTilesCount += bestCount;
            lastMopRound = rc.getRoundNum();
            rc.setIndicatorString("MopSwing " + bestDir + " hits=" + bestCount);
            return true;
        }
        return false;
    }

    private static int countEnemiesInSwingPath(RobotController rc, Direction d)
            throws GameActionException {
        MapLocation cur = rc.getLocation();
        Direction perpL = d.rotateLeft().rotateLeft();
        Direction perpR = d.rotateRight().rotateRight();
        MapLocation step1 = cur.add(d);
        MapLocation step2 = step1.add(d);
        MapLocation[] targets = {
            step1, step1.add(perpL), step1.add(perpR),
            step2, step2.add(perpL), step2.add(perpR)
        };
        int count = 0;
        Team enemy = rc.getTeam().opponent();
        for (MapLocation t : targets) {
            if (!rc.onTheMap(t)) continue;
            RobotInfo ri = rc.senseRobotAtLocation(t);
            if (ri != null && ri.getTeam() == enemy) count++;
        }
        return count;
    }

    private static boolean tryTransferToAlly(RobotController rc) throws GameActionException {
        if (!rc.isActionReady()) return false;
        int myPaint = rc.getPaint();
        int myMaxPaint = rc.getType().paintCapacity;
        if (myPaint < myMaxPaint / 2) return false;

        RobotInfo[] nearby = rc.senseNearbyRobots(2, rc.getTeam());
        for (RobotInfo ally : nearby) {
            if (ally.getType().isTowerType()) continue;
            int give = myPaint / 3;
            if (give < 10) continue;
            if (rc.canTransferPaint(ally.getLocation(), give)) {
                rc.transferPaint(ally.getLocation(), give);
                rc.setIndicatorString("Transferred " + give + " paint");
                return true;
            }
        }
        return false;
    }

    private static boolean isInEnemyTerritoryDeep(MapInfo[] nearby) {
        int enemyCount = 0;
        for (MapInfo t : nearby) {

            if (t.getPaint().isEnemy()) {
                enemyCount++;
                if (enemyCount >= 3) return true;
            }
        }
        return false;
    }

    private static boolean needsRefill(RobotController rc) {
        return Constants.paintPersentage(rc) < Constants.PAINT_REFILL_THRESHOLD;
    }

    private static boolean runRefill(RobotController rc, boolean forceRefill)
            throws GameActionException {
        int round = rc.getRoundNum();

        if (currentRefillTarget == null || Navigation.isBlacklisted(currentRefillTarget, round)) {
            MapLocation t = Navigation.findBestRefillTower(rc, false);
            if (t == null) {
                if (forceRefill) {
                    rc.setIndicatorString("EMERGENCY no tower!");
                    return false;
                }
                return true;
            }
            currentRefillTarget = t;
            refillStuckTimer = 0;
        }

        MapLocation target = currentRefillTarget;
        rc.setIndicatorString(
                "Mopper refill→"
                        + target
                        + " stuck="
                        + refillStuckTimer
                        + " "
                        + (int) (Constants.paintPersentage(rc) * 100)
                        + "%");

        if (rc.getLocation().distanceSquaredTo(target) <= 2) {
            boolean ok = Navigation.tryWithdrawFromTower(rc);
            if (ok) {
                refillStuckTimer = 0;
                currentRefillTarget = null;
                return false;
            }
            refillStuckTimer++;
            if (refillStuckTimer >= Constants.MAX_REFILL_WAIT) {
                Navigation.blacklistTower(target, round);
                currentRefillTarget = null;
                refillStuckTimer = 0;
                MapLocation next = Navigation.findBestRefillTower(rc, false);
                if (next != null && !next.equals(target)) {
                    currentRefillTarget = next;
                    Navigation.moveTo(rc, next);
                    return false;
                }
                if (forceRefill) return false;
                return true;
            }
            return false;
        }

        Navigation.moveTo(rc, target);
        return false;
    }

    private static void readMessages(RobotController rc) throws GameActionException {
        Message[] msgs = rc.readMessages(-1);
        for (Message m : msgs) {
            int data = m.getBytes();

            if (data >= Constants.MSG_CONTESTED_RUIN
                    && data < Constants.MSG_CONTESTED_RUIN + 10000) {

                addEnemyAreaTarget(Constants.decodePos(data, Constants.MSG_CONTESTED_RUIN));

            } else if (data >= Constants.MSG_PAINT_TOWER && data < Constants.MSG_EMPTY_AREA) {
                Navigation.addKnownPaintTower(Constants.decodePos(data, Constants.MSG_PAINT_TOWER));
            }
        }
    }

    private static void addEnemyAreaTarget(MapLocation loc) {
        if (loc == null) return;
        for (int i = 0; i < enemyTargetCount; i++) {
            if (enemyAreaTargets[i].equals(loc)) return;
        }
        if (enemyTargetCount < MAX_ENEMY_TARGETS) {
            enemyAreaTargets[enemyTargetCount++] = loc;
        } else {

            for (int i = 0; i < MAX_ENEMY_TARGETS - 1; i++)
                enemyAreaTargets[i] = enemyAreaTargets[i + 1];
            enemyAreaTargets[MAX_ENEMY_TARGETS - 1] = loc;
        }
    }

    private static void removeEnemyTarget(MapLocation loc) {
        for (int i = 0; i < enemyTargetCount; i++) {
            if (enemyAreaTargets[i] != null && enemyAreaTargets[i].equals(loc)) {
                enemyAreaTargets[i] = enemyAreaTargets[--enemyTargetCount];
                return;
            }
        }
    }
}
