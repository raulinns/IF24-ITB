package main_bot;

import battlecode.common.*;

public class Constants {

    public static final int PHASE1 = 150;
    public static final int PHASE2 = PHASE1 + 1;

    public static final int ROLE_SEARCHER = 0;
    public static final int ROLE_BUILDER = 1;
    public static final int ROLE_SCOUT = 2;
    public static final int ROLE_CONNECTOR = 3;

    public static final int MAX_SEARCHER = 3;
    public static final int MAX_BUILDER = 2;
    public static final int[] P1_SPAWN_PATTERN = {
        ROLE_SEARCHER, ROLE_SEARCHER, ROLE_BUILDER, ROLE_BUILDER, ROLE_SEARCHER
    };

    public static final double PAINT_REFILL_THRESHOLD = 0.20;
    public static final double PAINT_EMERGENCY = 0.08;
    public static final int TOWER_PAINT_RESERVE = 120;

    public static final int MAX_REFILL_WAIT = 6;
    public static final int BLACKLIST_DURATION = 40;

    public static final int EMPTY_CLUSTER_THRESHOLD = 8;

    public static final int ENEMY_CLUSTER_THRESHOLD = 5;

    public static final int MIN_MOP_BEFORE_CLEAR = 4;

    public static final int W_EXTEND = 14; // Prioritas untuk Extend path yang sudah dibuat
    public static final int W_ADJACENT =
            6; // Nilai tambahan untuk mewarnai petak di dekat cat teman
    public static final int W_ENEMY = 7; // Nilai tambahan untuk menimpa cat musuh
    public static final int P_HISTORY = 20; // Penalti untuk mengecat lokasi yang sama

    public static final int W_RUIN_SCOUT = 20; // Prioritas scout ke lokasi ruin
    public static final int W_CLEARED_AREA_SCOUT =
            25; // Prioritas scout pergi ke daerah yang baru dibersihkan mopper

    public static final int W_ENEMY_PAINT_MOPPER =
            9; // Prioritas mopper menargetkan petak yang diwarnai musuh
    public static final int W_ENEMY_ROBOT_MOPPER =
            49; // Prioritas mopper mengambil cat dari robot musuh

    public static final int W_ENEMY_CORE = 30; // Prioritas mewarnai petak musuh
    public static final int W_SPLASH_EMPTY = 9; // Nilai tambahan untuk mewarnai petak kosong
    public static final int W_SPLASH_ALLY = 4;
    // Nilai kecil untuk mewarnai petak yang sudah diwarnai (JANGAN DINAIKKAN!! nanti
    // splasher stuck kalau dikelilingi cat kita)

    public static final int HISTORY_SIZE = 50;

    public static final int MSG_ALLY_TOWER = 0;
    public static final int MSG_ENEMY_TOWER = 10000;
    public static final int MSG_RUIN_LOC = 20000;
    public static final int MSG_BUILD_TARGET = 30000;
    public static final int MSG_PAINT_TOWER = 40000;

    public static final int MSG_EMPTY_AREA = 60000;

    public static final int MSG_CLEARED_AREA = 62000;
    public static final int MSG_SOLDIER_POS = 50000;
    public static final int MSG_ROLE_ASSIGN = 70000;
    public static final int MSG_SYM_HORI = 80000;
    public static final int MSG_SYM_VERT = 80001;
    public static final int MSG_SYM_ROT = 80002;
    public static final int MSG_CONTESTED_RUIN = 90000;

    public static final int SYM_UNKNOWN = -1;
    public static final int SYM_HORI = 0;
    public static final int SYM_VERT = 1;
    public static final int SYM_ROT = 2;

    public static final int VISION_RADIUS = 20; // Radius penglihatan bot dalam kuadrat
    public static final int SPAWN_RADIUS = 4; // Jarak maksimal spawn dari tower dalam kuadrat

    public static final Direction[] DIRECTIONS = {
        Direction.NORTH, Direction.NORTHEAST, Direction.EAST, Direction.SOUTHEAST,
        Direction.SOUTH, Direction.SOUTHWEST, Direction.WEST, Direction.NORTHWEST,
    };
    public static final Direction[] CARDINALS = {
        Direction.NORTH, Direction.EAST, Direction.SOUTH, Direction.WEST,
    };

    public static boolean isPhase1(RobotController rc) {
        return rc.getRoundNum() <= PHASE1;
    }

    public static boolean isPhase2(RobotController rc) {
        return rc.getRoundNum() > PHASE1;
    }

    public static double paintPersentage(RobotController rc) {
        return (double) rc.getPaint() / rc.getType().paintCapacity;
    }

    public static boolean isPaintTower(UnitType t) {
        return t == UnitType.LEVEL_ONE_PAINT_TOWER
                || t == UnitType.LEVEL_TWO_PAINT_TOWER
                || t == UnitType.LEVEL_THREE_PAINT_TOWER;
    }

    public static boolean isPaintTowerAt(RobotController rc, MapLocation loc)
            throws GameActionException {
        if (loc == null) return false;
        if (rc.getLocation().distanceSquaredTo(loc) > VISION_RADIUS) return false;
        RobotInfo ri = rc.senseRobotAtLocation(loc);
        return ri != null && isPaintTower(ri.getType());
    }

    public static MapLocation getSymmetric(MapLocation loc, int sym, int mapW, int mapH) {
        switch (sym) {
            case SYM_HORI:
                return new MapLocation(mapW - 1 - loc.x, loc.y);
            case SYM_VERT:
                return new MapLocation(loc.x, mapH - 1 - loc.y);
            case SYM_ROT:
                return new MapLocation(mapW - 1 - loc.x, mapH - 1 - loc.y);
            default:
                return new MapLocation(mapW - 1 - loc.x, mapH - 1 - loc.y);
        }
    }

    public static int encodePos(int base, MapLocation loc) {
        return base + loc.x * 100 + loc.y;
    }

    public static MapLocation decodePos(int data, int base) {
        int raw = data - base;
        return new MapLocation(raw / 100, raw % 100);
    }
}
