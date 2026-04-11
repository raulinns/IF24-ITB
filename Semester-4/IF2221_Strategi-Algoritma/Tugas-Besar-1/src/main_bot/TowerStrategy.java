package main_bot;

import battlecode.common.*;

public class TowerStrategy {

    static MapLocation knownEnemyTower = null;
    static int detectedSymmetry = Constants.SYM_UNKNOWN;
    static boolean broadcastedSelf = false;

    static int p1SearcherSpawned = 0;
    static int p1BuilderSpawned = 0;

    static int p2SpawnSlot = 0;

    static final int MAX_KNOWN_RUINS = 16;

    static MapLocation[] knownRuins = new MapLocation[MAX_KNOWN_RUINS];
    static int knownRuinCount = 0;

    static int lastBuilderSpawnRound = -999;

    static final int BUILDER_RESPAWN_COOLDOWN = 45;

    private static final int DEDUP_SIZE = 32;
    private static final int DEDUP_TTL = 5;

    private static final int[] dedupData = new int[DEDUP_SIZE];
    private static final int[] dedupRound = new int[DEDUP_SIZE];
    private static int dedupHead = 0;

    private static final int MAX_RELAY_PER_TURN = 15;

    public static void run(RobotController rc) throws GameActionException {
        if (!broadcastedSelf) {
            broadcastSelf(rc);
            broadcastedSelf = true;
        }

        relayMessages(rc);
        attackEnemies(rc);
        spawnRobots(rc);

        if (rc.getRoundNum() % 10 == 0) {
            broadcastSelf(rc);
        }
    }

    private static void broadcastSelf(RobotController rc) throws GameActionException {
        rc.broadcastMessage(Constants.encodePos(Constants.MSG_ALLY_TOWER, rc.getLocation()));
        if (Constants.isPaintTower(rc.getType())) {
            rc.broadcastMessage(Constants.encodePos(Constants.MSG_PAINT_TOWER, rc.getLocation()));
        }
    }

    private static void addKnownRuin(MapLocation loc) {
        if (loc == null) return;
        for (int i = 0; i < knownRuinCount; i++) {
            if (knownRuins[i].equals(loc)) return;
        }
        if (knownRuinCount < MAX_KNOWN_RUINS) {
            knownRuins[knownRuinCount++] = loc;
        }
    }

    private static void removeKnownRuin(MapLocation loc) {
        if (loc == null) return;
        for (int i = 0; i < knownRuinCount; i++) {
            if (knownRuins[i].equals(loc)) {

                knownRuins[i] = knownRuins[--knownRuinCount];
                knownRuins[knownRuinCount] = null;
                return;
            }
        }
    }

    private static boolean alreadyRelayed(int data, int currentRound) {
        for (int i = 0; i < DEDUP_SIZE; i++) {
            if (dedupData[i] == data && currentRound - dedupRound[i] < DEDUP_TTL) {
                return true;
            }
        }
        return false;
    }

    private static void markRelayed(int data, int currentRound) {
        dedupData[dedupHead] = data;
        dedupRound[dedupHead] = currentRound;
        dedupHead = (dedupHead + 1) % DEDUP_SIZE;
    }

    private static int tryRelay(RobotController rc, int data, int currentRound, int sentCount)
            throws GameActionException {
        if (sentCount >= MAX_RELAY_PER_TURN) return sentCount;
        if (alreadyRelayed(data, currentRound)) return sentCount;
        rc.broadcastMessage(data);
        markRelayed(data, currentRound);
        return sentCount + 1;
    }

    private static int relaySymmetricRuins(
            RobotController rc, MapLocation ruinLoc, int round, int sentCount)
            throws GameActionException {
        int mapW = rc.getMapWidth();
        int mapH = rc.getMapHeight();

        MapLocation symH = Constants.getSymmetric(ruinLoc, Constants.SYM_HORI, mapW, mapH);
        MapLocation symV = Constants.getSymmetric(ruinLoc, Constants.SYM_VERT, mapW, mapH);
        MapLocation symR = Constants.getSymmetric(ruinLoc, Constants.SYM_ROT, mapW, mapH);

        if (!symH.equals(ruinLoc)) {
            addKnownRuin(symH);
            sentCount =
                    tryRelay(
                            rc,
                            Constants.encodePos(Constants.MSG_RUIN_LOC, symH),
                            round,
                            sentCount);
        }

        if (!symV.equals(ruinLoc) && !symV.equals(symH)) {
            addKnownRuin(symV);
            sentCount =
                    tryRelay(
                            rc,
                            Constants.encodePos(Constants.MSG_RUIN_LOC, symV),
                            round,
                            sentCount);
        }

        if (!symR.equals(ruinLoc) && !symR.equals(symH) && !symR.equals(symV)) {
            addKnownRuin(symR);
            sentCount =
                    tryRelay(
                            rc,
                            Constants.encodePos(Constants.MSG_RUIN_LOC, symR),
                            round,
                            sentCount);
        }
        return sentCount;
    }

    private static void relayMessages(RobotController rc) throws GameActionException {
        Message[] msgs = rc.readMessages(-1);
        int round = rc.getRoundNum();
        int sent = 0;

        for (Message m : msgs) {
            if (sent >= MAX_RELAY_PER_TURN) break;

            int data = m.getBytes();
            int senderID = m.getSenderID();

            if (senderID == rc.getID()) continue;

            if (data >= Constants.MSG_ENEMY_TOWER && data < Constants.MSG_RUIN_LOC) {

                knownEnemyTower = Constants.decodePos(data, Constants.MSG_ENEMY_TOWER);
                sent = tryRelay(rc, data, round, sent);

            } else if (data >= Constants.MSG_RUIN_LOC && data < Constants.MSG_BUILD_TARGET) {

                MapLocation ruinLoc = Constants.decodePos(data, Constants.MSG_RUIN_LOC);

                addKnownRuin(ruinLoc);

                sent = tryRelay(rc, data, round, sent);

                if (sent < MAX_RELAY_PER_TURN - 3) {
                    sent = relaySymmetricRuins(rc, ruinLoc, round, sent);
                }

            } else if (data >= Constants.MSG_BUILD_TARGET && data < Constants.MSG_PAINT_TOWER) {

                sent = tryRelay(rc, data, round, sent);

            } else if (data >= Constants.MSG_PAINT_TOWER && data < Constants.MSG_EMPTY_AREA) {

                MapLocation towerLoc = Constants.decodePos(data, Constants.MSG_PAINT_TOWER);
                Navigation.addKnownPaintTower(towerLoc);
                removeKnownRuin(towerLoc);
                sent = tryRelay(rc, data, round, sent);

            } else if (data >= Constants.MSG_EMPTY_AREA && data < Constants.MSG_EMPTY_AREA + 6000) {
                sent = tryRelay(rc, data, round, sent);

            } else if (data >= Constants.MSG_CLEARED_AREA
                    && data < Constants.MSG_CLEARED_AREA + 6000) {
                sent = tryRelay(rc, data, round, sent);

            } else if (data >= Constants.MSG_SYM_HORI && data <= Constants.MSG_SYM_ROT) {

                int newSym = data - Constants.MSG_SYM_HORI;
                if (detectedSymmetry == Constants.SYM_UNKNOWN) {
                    detectedSymmetry = newSym;
                }
                sent = tryRelay(rc, data, round, sent);

            } else if (data >= Constants.MSG_CONTESTED_RUIN
                    && data < Constants.MSG_CONTESTED_RUIN + 10000) {
                sent = tryRelay(rc, data, round, sent);
            }
        }

        scanNearbyRuins(rc);

        rc.setIndicatorString("Tower relay=" + sent + " ruins=" + knownRuinCount + " r=" + round);
    }

    private static void scanNearbyRuins(RobotController rc) throws GameActionException {
        MapLocation[] ruins = rc.senseNearbyRuins(-1);
        for (MapLocation ruinLoc : ruins) {
            RobotInfo ri = rc.senseRobotAtLocation(ruinLoc);
            if (ri != null && ri.getType().isTowerType() && ri.getTeam() == rc.getTeam()) {

                removeKnownRuin(ruinLoc);
            } else if (ri == null) {

                addKnownRuin(ruinLoc);
            }
        }
    }

    private static void attackEnemies(RobotController rc) throws GameActionException {
        RobotInfo[] enemies = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
        if (enemies.length == 0) return;
        RobotInfo target = enemies[0];
        for (RobotInfo e : enemies) {
            if (e.getHealth() < target.getHealth()) target = e;
        }
        if (rc.canAttack(target.getLocation())) rc.attack(target.getLocation());
    }

    private static void spawnRobots(RobotController rc) throws GameActionException {
        if (!rc.isActionReady()) return;
        if (Constants.isPhase1(rc)) spawnPhase1(rc);
        else spawnPhase2(rc);
    }

    private static void spawnPhase1(RobotController rc) throws GameActionException {
        int total = p1SearcherSpawned + p1BuilderSpawned;
        if (total >= Constants.P1_SPAWN_PATTERN.length) return;

        int nextRole = Constants.P1_SPAWN_PATTERN[total];
        if (nextRole == Constants.ROLE_SEARCHER && p1SearcherSpawned >= Constants.MAX_SEARCHER)
            return;
        if (nextRole == Constants.ROLE_BUILDER && p1BuilderSpawned >= Constants.MAX_BUILDER)
            return;

        MapLocation spawnLoc = findSpawnLocation(rc, UnitType.SOLDIER);
        if (spawnLoc == null) return;

        rc.buildRobot(UnitType.SOLDIER, spawnLoc);

        int roleMsg = Constants.MSG_ROLE_ASSIGN + nextRole;
        if (rc.canSendMessage(spawnLoc, roleMsg)) rc.sendMessage(spawnLoc, roleMsg);

        if (nextRole == Constants.ROLE_SEARCHER) p1SearcherSpawned++;
        else p1BuilderSpawned++;
    }

    private static void spawnPhase2(RobotController rc) throws GameActionException {
        int round = rc.getRoundNum();

        boolean needBuilder =
                (knownRuinCount > 0) && (round - lastBuilderSpawnRound >= BUILDER_RESPAWN_COOLDOWN);

        if (needBuilder) {
            int builderPaintCost = UnitType.SOLDIER.paintCost + Constants.TOWER_PAINT_RESERVE;
            if (rc.getPaint() >= builderPaintCost) {
                MapLocation spawnLoc = findSpawnLocation(rc, UnitType.SOLDIER);
                if (spawnLoc != null) {
                    rc.buildRobot(UnitType.SOLDIER, spawnLoc);

                    int roleMsg = Constants.MSG_ROLE_ASSIGN + Constants.ROLE_BUILDER;
                    if (rc.canSendMessage(spawnLoc, roleMsg)) {
                        rc.sendMessage(spawnLoc, roleMsg);
                    }

                    int ruinMsg = Constants.encodePos(Constants.MSG_RUIN_LOC, knownRuins[0]);
                    if (rc.canSendMessage(spawnLoc, ruinMsg)) {
                        rc.sendMessage(spawnLoc, ruinMsg);
                    }

                    lastBuilderSpawnRound = round;
                    rc.setIndicatorString(
                            "Spawned BUILDER→ruin@" + knownRuins[0] + " ruins=" + knownRuinCount);

                    return;
                }
            } else {

                rc.setIndicatorString(
                        "Tower: saving for BUILDER"
                                + " ruins="
                                + knownRuinCount
                                + " paint="
                                + rc.getPaint()
                                + "/"
                                + builderPaintCost);
                return;
            }
        }

        UnitType desired = slotToUnitType(p2SpawnSlot);

        if (rc.getPaint() < desired.paintCost + Constants.TOWER_PAINT_RESERVE) {
            rc.setIndicatorString(
                    "Tower: saving for "
                            + desired
                            + " paint="
                            + rc.getPaint()
                            + "/"
                            + (desired.paintCost + Constants.TOWER_PAINT_RESERVE));
            return;
        }

        MapLocation spawnLoc = findSpawnLocation(rc, desired);
        if (spawnLoc == null) {
            rc.setIndicatorString("Tower: no spawn slot for " + desired);
            return;
        }

        rc.buildRobot(desired, spawnLoc);
        p2SpawnSlot = (p2SpawnSlot + 1) % 3;

        rc.setIndicatorString("Spawned " + desired + " → next=" + slotToUnitType(p2SpawnSlot));
    }

    private static UnitType slotToUnitType(int slot) {
        if (slot == 0) return UnitType.SOLDIER;
        if (slot == 1) return UnitType.SPLASHER;
        return UnitType.MOPPER;
    }

    private static MapLocation findSpawnLocation(RobotController rc, UnitType type)
            throws GameActionException {
        for (Direction dir : Constants.DIRECTIONS) {
            MapLocation c = rc.getLocation().add(dir);
            if (rc.canBuildRobot(type, c)) return c;
        }
        return null;
    }
}

