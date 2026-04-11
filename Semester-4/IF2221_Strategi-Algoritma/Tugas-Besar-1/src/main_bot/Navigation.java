package main_bot;

import battlecode.common.*;

public class Navigation {

    static MapLocation currentTarget = null;
    static boolean tracing = false;
    static Direction traceDir = null;
    static int traceCount = 0;
    static final int MAX_TRACE = 24;

    static final int MAX_PAINT_TOWERS = 8;
    static MapLocation[] knownPaintTowers = new MapLocation[MAX_PAINT_TOWERS];
    static int paintTowerCount = 0;

    static final int MAX_BLACKLIST = 4;
    static MapLocation[] blacklistedTowers = new MapLocation[MAX_BLACKLIST];
    static int[] blacklistExpiry = new int[MAX_BLACKLIST];
    static int blacklistCount = 0;

    public static boolean moveTo(RobotController rc, MapLocation target)
            throws GameActionException {
        if (!rc.isMovementReady() || target == null) return false;
        MapLocation cur = rc.getLocation();
        if (cur.equals(target)) return false;

        if (!target.equals(currentTarget)) {
            currentTarget = target;
            tracing = false;
            traceCount = 0;
        }

        Direction direct = cur.directionTo(target);

        if (!tracing) {
            if (tryMove(rc, direct)) return true;
            if (tryMove(rc, direct.rotateLeft())) return true;
            if (tryMove(rc, direct.rotateRight())) return true;
            tracing = true;
            traceDir = direct.rotateLeft();
            traceCount = 0;
        }

        if (tryMove(rc, cur.directionTo(target))) {
            tracing = false;
            return true;
        }

        for (int i = 0; i < 8; i++) {
            if (tryMove(rc, traceDir)) {
                traceDir = traceDir.rotateLeft();
                traceCount++;
                break;
            }
            traceDir = traceDir.rotateRight();
        }

        if (traceCount > MAX_TRACE) {
            tracing = false;
            traceCount = 0;
        }
        return true;
    }

    public static boolean moveAway(RobotController rc, MapLocation avoid)
            throws GameActionException {
        if (!rc.isMovementReady()) return false;
        Direction away = avoid.directionTo(rc.getLocation());
        if (tryMove(rc, away)) return true;
        if (tryMove(rc, away.rotateLeft())) return true;
        if (tryMove(rc, away.rotateRight())) return true;
        return false;
    }

    public static boolean moveRandom(RobotController rc) throws GameActionException {
        if (!rc.isMovementReady()) return false;
        int offset = rc.getID() % 8;
        for (int i = 0; i < 8; i++) {
            Direction d = Constants.DIRECTIONS[(i + offset) % 8];
            if (rc.canMove(d)) {
                rc.move(d);
                return true;
            }
        }
        return false;
    }

    public static void addKnownPaintTower(MapLocation loc) {
        if (loc == null) return;
        for (int i = 0; i < paintTowerCount; i++) {
            if (knownPaintTowers[i].equals(loc)) return;
        }
        if (paintTowerCount < MAX_PAINT_TOWERS) {
            knownPaintTowers[paintTowerCount++] = loc;
        } else {

            for (int i = 0; i < MAX_PAINT_TOWERS - 1; i++)
                knownPaintTowers[i] = knownPaintTowers[i + 1];
            knownPaintTowers[MAX_PAINT_TOWERS - 1] = loc;
        }
    }

    public static void blacklistTower(MapLocation loc, int currentRound) {
        if (loc == null) return;
        for (int i = 0; i < blacklistCount; i++) {
            if (blacklistedTowers[i].equals(loc)) {
                blacklistExpiry[i] = currentRound + Constants.BLACKLIST_DURATION;
                return;
            }
        }
        if (blacklistCount < MAX_BLACKLIST) {
            blacklistedTowers[blacklistCount] = loc;
            blacklistExpiry[blacklistCount] = currentRound + Constants.BLACKLIST_DURATION;
            blacklistCount++;
        } else {

            int oldestIdx = 0;
            for (int i = 1; i < MAX_BLACKLIST; i++) {
                if (blacklistExpiry[i] < blacklistExpiry[oldestIdx]) oldestIdx = i;
            }
            blacklistedTowers[oldestIdx] = loc;
            blacklistExpiry[oldestIdx] = currentRound + Constants.BLACKLIST_DURATION;
        }
    }

    public static boolean isBlacklisted(MapLocation loc, int currentRound) {
        if (loc == null) return false;
        for (int i = 0; i < blacklistCount; i++) {
            if (blacklistedTowers[i].equals(loc) && currentRound < blacklistExpiry[i]) {
                return true;
            }
        }
        return false;
    }

    public static MapLocation findBestRefillTower(RobotController rc, boolean preferPaintOnly)
            throws GameActionException {

        RobotInfo[] nearby = rc.senseNearbyRobots(-1, rc.getTeam());
        return findBestRefillTower(rc, preferPaintOnly, nearby);
    }

    public static MapLocation findBestRefillTower(
            RobotController rc, boolean preferPaintOnly, RobotInfo[] nearby)
            throws GameActionException {
        int round = rc.getRoundNum();
        MapLocation myLoc = rc.getLocation();

        for (RobotInfo ri : nearby) {
            if (Constants.isPaintTower(ri.getType())) {
                addKnownPaintTower(ri.getLocation());
            }
        }

        MapLocation bestPaint = null;
        MapLocation bestPaintExpired = null;
        MapLocation bestAny = null;
        int distBestPaint = Integer.MAX_VALUE;
        int distBestPaintExpired = Integer.MAX_VALUE;
        int distBestAny = Integer.MAX_VALUE;

        for (int i = 0; i < paintTowerCount; i++) {
            MapLocation loc = knownPaintTowers[i];
            if (loc == null) continue;
            int d = myLoc.distanceSquaredTo(loc);

            if (!isBlacklisted(loc, round)) {
                if (d < distBestPaint) {
                    distBestPaint = d;
                    bestPaint = loc;
                }
            } else {
                for (int j = 0; j < blacklistCount; j++) {
                    if (blacklistedTowers[j].equals(loc) && round >= blacklistExpiry[j]) {
                        if (d < distBestPaintExpired) {
                            distBestPaintExpired = d;
                            bestPaintExpired = loc;
                        }
                        break;
                    }
                }
            }
        }

        for (RobotInfo ri : nearby) {
            if (!ri.getType().isTowerType()) continue;
            MapLocation loc = ri.getLocation();
            int d = myLoc.distanceSquaredTo(loc);

            if (Constants.isPaintTower(ri.getType()) && !isBlacklisted(loc, round)) {
                if (d < distBestPaint) {
                    distBestPaint = d;
                    bestPaint = loc;
                }
            }
            if (!isBlacklisted(loc, round) && d < distBestAny) {
                distBestAny = d;
                bestAny = loc;
            }
        }

        if (bestPaint != null) return bestPaint;
        if (bestPaintExpired != null) return bestPaintExpired;
        if (!preferPaintOnly && bestAny != null) return bestAny;
        return null;
    }

    public static MapLocation findNearestAllyTower(RobotController rc) throws GameActionException {
        RobotInfo[] nearby = rc.senseNearbyRobots(-1, rc.getTeam());
        return findNearestAllyTower(rc, nearby);
    }

    public static MapLocation findNearestAllyTower(RobotController rc, RobotInfo[] nearby) {
        MapLocation best = null;
        int bestDist = Integer.MAX_VALUE;
        MapLocation myLoc = rc.getLocation();
        for (RobotInfo ri : nearby) {
            if (!ri.getType().isTowerType()) continue;
            if (Constants.isPaintTower(ri.getType())) {
                addKnownPaintTower(ri.getLocation());
            }
            int d = myLoc.distanceSquaredTo(ri.getLocation());
            if (d < bestDist) {
                bestDist = d;
                best = ri.getLocation();
            }
        }
        return best;
    }

    public static boolean tryWithdrawFromTower(RobotController rc) throws GameActionException {
        if (!rc.isActionReady()) return false;
        int needed = rc.getType().paintCapacity - rc.getPaint();
        if (needed <= 0) return false;

        RobotInfo[] nearby = rc.senseNearbyRobots(2, rc.getTeam());

        for (RobotInfo ri : nearby) {
            if (!Constants.isPaintTower(ri.getType())) continue;
            if (rc.canTransferPaint(ri.getLocation(), -needed)) {
                rc.transferPaint(ri.getLocation(), -needed);
                return true;
            }
        }

        for (RobotInfo ri : nearby) {
            if (!ri.getType().isTowerType()) continue;
            if (rc.canTransferPaint(ri.getLocation(), -needed)) {
                rc.transferPaint(ri.getLocation(), -needed);
                return true;
            }
        }
        return false;
    }

    private static boolean tryMove(RobotController rc, Direction dir) throws GameActionException {
        if (rc.canMove(dir)) {
            rc.move(dir);
            return true;
        }
        return false;
    }
}

