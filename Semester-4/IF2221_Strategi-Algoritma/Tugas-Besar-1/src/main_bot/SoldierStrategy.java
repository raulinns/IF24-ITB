package main_bot;

import battlecode.common.*;

public class SoldierStrategy {

    static MapLocation homeTower = null;
    static MapLocation knownEnemyTower = null;
    static int myRole = -1;
    static int birthRound = -1;
    static boolean phaseTransitioned = false;

    static MapLocation[] ruinTargets = new MapLocation[10];
    static int ruinCount = 0;
    static MapLocation activeBuilderRuin = null;

    static int searcherWaypointIdx = 0;
    static int searcherReportCooldown = 0;

    static final int MAX_CLEARED = 4;
    static MapLocation[] clearedTargets = new MapLocation[MAX_CLEARED];
    static int clearedCount = 0;

    static int scoutPhase = 0;
    static int scoutPhaseRound = 0;
    static MapLocation[] history = new MapLocation[Constants.HISTORY_SIZE];
    static int historyIdx = 0;

    static MapLocation currentRefillTarget = null;
    static int refillStuckTimer = 0;

    static RobotInfo[] cachedAllyRobots = new RobotInfo[0];
    static int cachedAllyRound = -1;

    public static void run(RobotController rc) throws GameActionException {
        if (birthRound == -1) birthRound = rc.getRoundNum();

        int round = rc.getRoundNum();
        if (cachedAllyRound != round) {
            cachedAllyRobots = rc.senseNearbyRobots(-1, rc.getTeam());
            cachedAllyRound = round;
        }

        if (homeTower == null) homeTower = Navigation.findNearestAllyTower(rc, cachedAllyRobots);

        if (!assignRole(rc)) {
            Navigation.moveRandom(rc);
            return;
        }

        readMessages(rc);

        boolean withdrew = Navigation.tryWithdrawFromTower(rc);
        if (withdrew) {
            refillStuckTimer = 0;
            currentRefillTarget = null;
        }

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

        switch (myRole) {
            case Constants.ROLE_SEARCHER:
                runSearcher(rc);
                break;
            case Constants.ROLE_BUILDER:
                runBuilder(rc);
                break;
            case Constants.ROLE_SCOUT:
                runScout(rc);
                break;
            case Constants.ROLE_CONNECTOR:
                runConnector(rc);
                break;
            default:
                Navigation.moveRandom(rc);
        }

        if (rc.getRoundNum() % 5 == 0) broadcastPosition(rc);
    }

    private static boolean assignRole(RobotController rc) throws GameActionException {
        if (Constants.isPhase2(rc) && myRole >= 0 && !phaseTransitioned) {
            if (myRole == Constants.ROLE_SEARCHER || myRole == Constants.ROLE_BUILDER) {
                myRole = (rc.getID() % 2 == 0) ? Constants.ROLE_SCOUT : Constants.ROLE_CONNECTOR;
                MapLocation near = Navigation.findNearestAllyTower(rc);
                if (near != null) homeTower = near;
                Navigation.currentTarget = null;
                Navigation.tracing = false;
                currentRefillTarget = null;
                refillStuckTimer = 0;
            }
            phaseTransitioned = true;
            return true;
        }

        if (myRole >= 0) return true;

        Message[] msgs = rc.readMessages(-1);
        for (Message m : msgs) {
            int data = m.getBytes();
            if (data >= Constants.MSG_ROLE_ASSIGN && data < Constants.MSG_ROLE_ASSIGN + 10) {
                myRole = data - Constants.MSG_ROLE_ASSIGN;
                MapLocation near = Navigation.findNearestAllyTower(rc);
                if (near != null) homeTower = near;
                return true;
            }
        }

        if (rc.getRoundNum() - birthRound >= 3) {
            myRole = (rc.getID() % 2 == 0) ? Constants.ROLE_SEARCHER : Constants.ROLE_BUILDER;
            if (Constants.isPhase2(rc))
                myRole = (rc.getID() % 2 == 0) ? Constants.ROLE_SCOUT : Constants.ROLE_CONNECTOR;
            return true;
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

            MapLocation t = Navigation.findBestRefillTower(rc, false, cachedAllyRobots);
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
                "Refill→"
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

    private static void runSearcher(RobotController rc) throws GameActionException {
        rc.setIndicatorString("Searcher wp=" + searcherWaypointIdx);

        MapInfo[] nearby = rc.senseNearbyMapInfos();
        scanAndReport(rc, nearby);

        MapLocation[] waypoints = getSearcherWaypoints(rc);
        MapLocation wp = waypoints[searcherWaypointIdx];

        if (rc.getLocation().distanceSquaredTo(wp) <= 9) {
            searcherWaypointIdx = (searcherWaypointIdx + 1) % waypoints.length;
            wp = waypoints[searcherWaypointIdx];
        }

        Navigation.moveTo(rc, wp);
    }

    private static MapLocation[] getSearcherWaypoints(RobotController rc) {
        int w = rc.getMapWidth(), h = rc.getMapHeight();
        int sector = rc.getID() % 3;

        int yMin = (h * sector) / 3;
        int yMax = (h * (sector + 1)) / 3;
        int yMid = (yMin + yMax) / 2;

        return new MapLocation[] {
            new MapLocation(w / 5, yMid),
            new MapLocation(2 * w / 5, yMid),
            new MapLocation(3 * w / 5, yMid),
            new MapLocation(4 * w / 5, yMid),
        };
    }

    private static void scanAndReport(RobotController rc, MapInfo[] nearby)
            throws GameActionException {

        if (searcherReportCooldown > 0) {
            searcherReportCooldown--;
            return;
        }

        MapLocation myLoc = rc.getLocation();
        int emptyCount = 0, enemyCount = 0;
        MapLocation bestEmptyCenter = null, bestEnemyCenter = null;
        int bestEmptyScore = 0, bestEnemyScore = 0;

        for (MapInfo tile : nearby) {
            if (!tile.hasRuin()) continue;
            MapLocation ruinLoc = tile.getMapLocation();
            RobotInfo r = rc.senseRobotAtLocation(ruinLoc);
            if (r != null && r.getType().isTowerType()) {

                if (Constants.isPaintTower(r.getType())) {
                    Navigation.addKnownPaintTower(ruinLoc);
                }
                continue;
            }

            reportToTower(rc, Constants.encodePos(Constants.MSG_RUIN_LOC, ruinLoc));
            addRuinTarget(ruinLoc);
        }

        final int MAX_CENTERS = 20;
        int centersChecked = 0;

        for (MapInfo center : nearby) {
            if (centersChecked >= MAX_CENTERS) break;
            if (center.isWall() || center.hasRuin()) continue;
            MapLocation cLoc = center.getMapLocation();
            if (center.getPaint().isAlly()) continue;

            centersChecked++;
            emptyCount = 0;
            enemyCount = 0;

            for (MapInfo tile : nearby) {
                if (tile.isWall() || tile.hasRuin()) continue;
                int dSq = cLoc.distanceSquaredTo(tile.getMapLocation());
                if (dSq > 4) continue;
                PaintType p = tile.getPaint();
                if (p == PaintType.EMPTY) emptyCount++;
                else if (p.isEnemy()) enemyCount++;

                if (emptyCount > bestEmptyScore + 8) break;
            }

            if (emptyCount > bestEmptyScore) {
                bestEmptyScore = emptyCount;
                bestEmptyCenter = cLoc;
            }
            if (enemyCount > bestEnemyScore) {
                bestEnemyScore = enemyCount;
                bestEnemyCenter = cLoc;
            }
        }

        if (bestEmptyScore >= Constants.EMPTY_CLUSTER_THRESHOLD && bestEmptyCenter != null) {
            reportToTower(rc, Constants.encodePos(Constants.MSG_EMPTY_AREA, bestEmptyCenter));
        }

        if (bestEnemyScore >= Constants.ENEMY_CLUSTER_THRESHOLD && bestEnemyCenter != null) {
            reportToTower(rc, Constants.encodePos(Constants.MSG_CONTESTED_RUIN, bestEnemyCenter));
        }

        searcherReportCooldown = 3;
    }

    private static void runBuilder(RobotController rc) throws GameActionException {
        rc.setIndicatorString(
                "Builder ruins="
                        + ruinCount
                        + (activeBuilderRuin != null ? " active=" + activeBuilderRuin : ""));

        MapInfo[] nearby = rc.senseNearbyMapInfos();
        scanAndAddLocalRuins(rc, nearby);

        if (activeBuilderRuin != null) {
            if (rc.getLocation().distanceSquaredTo(activeBuilderRuin)
                    <= Constants.VISION_RADIUS) {
                RobotInfo r = rc.senseRobotAtLocation(activeBuilderRuin);
                if (r != null && r.getType().isTowerType()) {
                    if (Constants.isPaintTower(r.getType())) {

                        reportToTower(
                                rc,
                                Constants.encodePos(Constants.MSG_PAINT_TOWER, activeBuilderRuin));
                        Navigation.addKnownPaintTower(activeBuilderRuin);
                    }
                    removeRuinTarget(activeBuilderRuin);
                    activeBuilderRuin = null;
                }
            }
        }

        if (activeBuilderRuin == null && ruinCount > 0) {
            activeBuilderRuin = findNearestRuin(rc);
        }

        if (activeBuilderRuin != null) {

            if (rc.getLocation().distanceSquaredTo(activeBuilderRuin) <= 2) {
                tryBuildPaintTower(rc, activeBuilderRuin);
            } else {

                Navigation.moveTo(rc, activeBuilderRuin);
            }
        } else {

            Navigation.moveTo(rc, getExplorationTarget(rc));
        }
    }

    private static MapLocation findNearestRuin(RobotController rc) {
        MapLocation myLoc = rc.getLocation();
        MapLocation best = null;
        int bestDist = Integer.MAX_VALUE;
        for (int i = 0; i < ruinCount; i++) {
            int d = myLoc.distanceSquaredTo(ruinTargets[i]);
            if (d < bestDist) {
                bestDist = d;
                best = ruinTargets[i];
            }
        }
        return best;
    }

    private static void scanAndAddLocalRuins(RobotController rc, MapInfo[] nearby)
            throws GameActionException {
        for (MapInfo tile : nearby) {
            if (!tile.hasRuin()) continue;
            MapLocation ruinLoc = tile.getMapLocation();
            RobotInfo r = rc.senseRobotAtLocation(ruinLoc);
            if (r != null && r.getType().isTowerType()) {
                if (Constants.isPaintTower(r.getType())) Navigation.addKnownPaintTower(ruinLoc);
                continue;
            }
            addRuinTarget(ruinLoc);
        }
    }

    private static void scanAndAddLocalRuins(RobotController rc) throws GameActionException {
        scanAndAddLocalRuins(rc, rc.senseNearbyMapInfos());
    }

    private static void tryBuildPaintTower(RobotController rc, MapLocation ruinLoc)
            throws GameActionException {
        UnitType towerType = UnitType.LEVEL_ONE_PAINT_TOWER;

        if (rc.canMarkTowerPattern(towerType, ruinLoc)) {
            rc.markTowerPattern(towerType, ruinLoc);
        }

        if (rc.canCompleteTowerPattern(towerType, ruinLoc)) {
            rc.completeTowerPattern(towerType, ruinLoc);
            reportToTower(rc, Constants.encodePos(Constants.MSG_PAINT_TOWER, ruinLoc));
            Navigation.addKnownPaintTower(ruinLoc);
            removeRuinTarget(ruinLoc);
            activeBuilderRuin = null;
            rc.setIndicatorString("BUILT Paint Tower @ " + ruinLoc);
            return;
        }

        if (!rc.isActionReady()) {
            rc.setIndicatorString("Builder: waiting cooldown @ " + ruinLoc);
            return;
        }

        MapInfo[] nearRuin = rc.senseNearbyMapInfos(ruinLoc, 8);
        for (MapInfo p : nearRuin) {
            MapLocation pLoc = p.getMapLocation();
            if (p.isWall() || p.hasRuin()) continue;

            PaintType mark = p.getMark();
            if (mark == PaintType.EMPTY) continue;

            boolean needSecondary = (mark == PaintType.ALLY_SECONDARY);
            PaintType cur = p.getPaint();

            boolean correct =
                    needSecondary
                            ? (cur == PaintType.ALLY_SECONDARY)
                            : (cur == PaintType.ALLY_PRIMARY);

            if (!correct) {

                if (rc.canAttack(pLoc)) {
                    rc.attack(pLoc, needSecondary);
                    rc.setIndicatorString(
                            "Builder: painting " + pLoc + (needSecondary ? "(sec)" : "(pri)"));
                    return;
                }

                Navigation.moveTo(rc, pLoc);
                rc.setIndicatorString("Builder: repositioning → " + pLoc);
                return;
            }
        }

        rc.setIndicatorString("Builder: all visible tiles ok, waiting @ " + ruinLoc);
    }

    private static void runScout(RobotController rc) throws GameActionException {

        MapInfo[] nearby = rc.senseNearbyMapInfos();

        if (clearedCount > 0) {
            MapLocation clearTarget = findBestClearedTarget(rc);
            if (clearTarget != null) {
                rc.setIndicatorString("Scout→Cleared " + clearTarget);
                if (rc.getLocation().distanceSquaredTo(clearTarget) <= 4) {
                    paintNearbyEmpty(rc, nearby);
                    if (countEmptyNearby(nearby) < 3) removeClearedTarget(clearTarget);
                } else {
                    Navigation.moveTo(rc, clearTarget);
                    paintCurrentTileIfEmpty(rc);
                }
                return;
            }
        }

        rc.setIndicatorString("Scout phase=" + scoutPhase);

        if (attackEnemyTower(rc)) return;

        scanAndAddLocalRuins(rc, nearby);
        if (ruinCount > 0) {
            MapLocation ruinLoc = findNearestRuin(rc);
            if (ruinLoc != null
                    && rc.getLocation().distanceSquaredTo(ruinLoc) <= Constants.VISION_RADIUS) {
                if (rc.getLocation().distanceSquaredTo(ruinLoc) <= 2) {
                    tryBuildPaintTower(rc, ruinLoc);
                } else {
                    Navigation.moveTo(rc, ruinLoc);
                }
                paintCurrentTileIfEmpty(rc);
                return;
            }
        }

        int round = rc.getRoundNum();
        MapLocation scoutTarget = getScoutCyclingTarget(rc);

        boolean atTarget = rc.getLocation().distanceSquaredTo(scoutTarget) <= 4;
        if (atTarget || round - scoutPhaseRound >= 25) {
            scoutPhase = (scoutPhase + 1) % 8;
            scoutPhaseRound = round;
            scoutTarget = getScoutCyclingTarget(rc);
        }

        Navigation.moveTo(rc, scoutTarget);
        paintCurrentTileIfEmpty(rc);
    }

    private static MapLocation getScoutCyclingTarget(RobotController rc) {
        int w = rc.getMapWidth(), h = rc.getMapHeight();
        int qx = w / 3, qy = h / 3;

        int offset = rc.getID() % 4;
        int phase = (scoutPhase + offset) % 8;
        switch (phase) {
            case 0:
                return new MapLocation(qx, qy);
            case 1:
                return new MapLocation(2 * qx, qy);
            case 2:
                return new MapLocation(2 * qx, 2 * qy);
            case 3:
                return new MapLocation(qx, 2 * qy);
            case 4:
                return new MapLocation(w / 2, h / 2);
            case 5:
                return new MapLocation(w - qx - 1, qy);
            case 6:
                return new MapLocation(w - qx - 1, h - qy - 1);
            default:
                return new MapLocation(qx, h - qy - 1);
        }
    }

    private static MapLocation findBestClearedTarget(RobotController rc) {
        MapLocation myLoc = rc.getLocation();
        MapLocation best = null;
        int bestDist = Integer.MAX_VALUE;
        for (int i = 0; i < clearedCount; i++) {
            if (clearedTargets[i] == null) continue;
            int d = myLoc.distanceSquaredTo(clearedTargets[i]);
            if (d < bestDist) {
                bestDist = d;
                best = clearedTargets[i];
            }
        }
        return best;
    }

    private static void paintNearbyEmpty(RobotController rc) throws GameActionException {
        paintNearbyEmpty(rc, rc.senseNearbyMapInfos(2));
    }

    private static void paintNearbyEmpty(RobotController rc, MapInfo[] nearby)
            throws GameActionException {
        if (!rc.isActionReady()) return;
        MapLocation cur = rc.getLocation();

        for (MapInfo tile : nearby) {
            if (tile.getMapLocation().equals(cur)) {
                if (tile.getPaint() == PaintType.EMPTY && rc.canAttack(cur)) {
                    rc.attack(cur, false);
                    addToHistory(cur);
                    return;
                }
                break;
            }
        }

        for (MapInfo tile : nearby) {
            if (tile.isWall() || tile.hasRuin()) continue;
            if (tile.getPaint() != PaintType.EMPTY) continue;
            MapLocation loc = tile.getMapLocation();

            if (cur.distanceSquaredTo(loc) > 4) continue;
            if (rc.canAttack(loc)) {
                rc.attack(loc, false);
                addToHistory(loc);
                return;
            }
        }
    }

    private static int countEmptyNearby(RobotController rc) throws GameActionException {
        return countEmptyNearby(rc.senseNearbyMapInfos(4));
    }

    private static int countEmptyNearby(MapInfo[] nearby) {
        int count = 0;
        for (MapInfo t : nearby) {
            if (!t.isWall() && !t.hasRuin() && t.getPaint() == PaintType.EMPTY) count++;
        }
        return count;
    }

    private static void removeClearedTarget(MapLocation loc) {
        for (int i = 0; i < clearedCount; i++) {
            if (clearedTargets[i] != null && clearedTargets[i].equals(loc)) {
                clearedTargets[i] = clearedTargets[--clearedCount];
                return;
            }
        }
    }

    static int connectorPhase = 0;
    static int connectorPhaseRound = 0;

    private static void runConnector(RobotController rc) throws GameActionException {
        if (attackEnemyTower(rc)) return;

        MapInfo[] nearby = rc.senseNearbyMapInfos();
        MapLocation target = findConnectorTarget(rc, nearby);

        if (target != null && !target.equals(rc.getLocation())) {
            Navigation.moveTo(rc, target);
            rc.setIndicatorString("Connector→" + target);
        } else {

            int round = rc.getRoundNum();
            MapLocation frontier = getConnectorFrontier(rc);
            boolean atFrontier = rc.getLocation().distanceSquaredTo(frontier) <= 4;
            if (atFrontier || round - connectorPhaseRound >= 25) {
                connectorPhase = (connectorPhase + 1) % 6;
                connectorPhaseRound = round;
                frontier = getConnectorFrontier(rc);
            }
            Navigation.moveTo(rc, frontier);
            rc.setIndicatorString("Connector frontier→" + frontier);
        }

        paintCurrentTileIfEmpty(rc);
    }

    private static MapLocation getConnectorFrontier(RobotController rc) {
        int w = rc.getMapWidth(), h = rc.getMapHeight();
        int offset = (rc.getID() + 2) % 4;
        int phase = (connectorPhase + offset) % 6;
        switch (phase) {
            case 0:
                return new MapLocation(w / 4, h / 2);
            case 1:
                return new MapLocation(3 * w / 4, h / 2);
            case 2:
                return new MapLocation(w / 2, h / 4);
            case 3:
                return new MapLocation(w / 2, 3 * h / 4);
            case 4:
                return new MapLocation(w / 4, h / 4);
            default:
                return new MapLocation(3 * w / 4, 3 * h / 4);
        }
    }

    private static MapLocation findConnectorTarget(RobotController rc, MapInfo[] nearby)
            throws GameActionException {
        MapLocation myLoc = rc.getLocation();
        MapLocation best = null;
        int bestScore = Integer.MIN_VALUE;

        RobotInfo[] allyRobots = cachedAllyRobots;

        for (MapInfo tile : nearby) {
            if (tile.isWall() || tile.hasRuin()) continue;
            MapLocation loc = tile.getMapLocation();
            PaintType paint = tile.getPaint();
            int score = 0;

            if (paint == PaintType.EMPTY) {

                if (isAdjacentToAllyPaintInArray(loc, nearby)) score += Constants.W_EXTEND;
            } else if (paint.isAlly()) {
                score += Constants.W_ADJACENT;
            } else if (paint.isEnemy()) {
                score += Constants.W_ENEMY;
            }

            if (isInHistory(loc)) score -= Constants.P_HISTORY;

            for (RobotInfo ri : allyRobots) {
                if (ri.getLocation().equals(loc)) {
                    score -= 50;
                    break;
                }
            }

            score -= myLoc.distanceSquaredTo(loc) / 4;

            if (score > bestScore) {
                bestScore = score;
                best = loc;
            }
        }
        return best;
    }

    private static void paintCurrentTileIfEmpty(RobotController rc) throws GameActionException {
        if (!rc.isActionReady()) return;
        MapLocation cur = rc.getLocation();
        if (!rc.canAttack(cur)) return;
        if (rc.senseMapInfo(cur).getPaint() == PaintType.EMPTY) {
            rc.attack(cur, false);
            addToHistory(cur);
        }
    }

    private static boolean attackEnemyTower(RobotController rc) throws GameActionException {
        if (!rc.isActionReady()) return false;
        RobotInfo[] enemies = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
        for (RobotInfo e : enemies) {
            if (e.getType().isTowerType() && rc.canAttack(e.getLocation())) {
                rc.attack(e.getLocation(), false);
                return true;
            }
        }
        return false;
    }

    private static boolean isInEnemyTerritory(RobotController rc) throws GameActionException {
        return rc.senseMapInfo(rc.getLocation()).getPaint().isEnemy();
    }

    private static MapLocation getExplorationTarget(RobotController rc) {
        int w = rc.getMapWidth(), h = rc.getMapHeight();
        int qx = w / 4, qy = h / 4;
        switch (rc.getID() % 4) {
            case 0:
                return new MapLocation(qx, qy);
            case 1:
                return new MapLocation(w - qx - 1, qy);
            case 2:
                return new MapLocation(qx, h - qy - 1);
            default:
                return new MapLocation(w - qx - 1, h - qy - 1);
        }
    }

    private static boolean isAdjacentToAllyPaintInArray(MapLocation loc, MapInfo[] nearby) {
        for (MapInfo t : nearby) {
            if (t.getPaint().isAlly() && loc.isAdjacentTo(t.getMapLocation())) {
                return true;
            }
        }
        return false;
    }

    private static boolean isAdjacentToAllyPaint(RobotController rc, MapLocation loc)
            throws GameActionException {
        for (Direction d : Constants.DIRECTIONS) {
            MapLocation adj = loc.add(d);
            if (rc.onTheMap(adj) && rc.senseMapInfo(adj).getPaint().isAlly()) return true;
        }
        return false;
    }

    private static void addToHistory(MapLocation loc) {
        if (loc == null) return;
        history[historyIdx] = loc;
        historyIdx = (historyIdx + 1) % Constants.HISTORY_SIZE;
    }

    private static boolean isInHistory(MapLocation loc) {
        if (loc == null) return false;
        for (MapLocation h : history) {
            if (h != null && h.equals(loc)) return true;
        }
        return false;
    }

    private static void addRuinTarget(MapLocation loc) {
        if (loc == null) return;
        for (int i = 0; i < ruinCount; i++) if (ruinTargets[i].equals(loc)) return;
        if (ruinCount < ruinTargets.length) ruinTargets[ruinCount++] = loc;
    }

    private static void removeRuinTarget(MapLocation loc) {
        for (int i = 0; i < ruinCount; i++) {
            if (ruinTargets[i].equals(loc)) {
                ruinTargets[i] = ruinTargets[--ruinCount];
                return;
            }
        }
    }

    private static void readMessages(RobotController rc) throws GameActionException {
        Message[] msgs = rc.readMessages(-1);
        for (Message m : msgs) {
            int data = m.getBytes();

            if (data >= Constants.MSG_RUIN_LOC && data < Constants.MSG_BUILD_TARGET) {
                addRuinTarget(Constants.decodePos(data, Constants.MSG_RUIN_LOC));

            } else if (data >= Constants.MSG_ENEMY_TOWER && data < Constants.MSG_RUIN_LOC) {
                knownEnemyTower = Constants.decodePos(data, Constants.MSG_ENEMY_TOWER);

            } else if (data >= Constants.MSG_PAINT_TOWER && data < Constants.MSG_EMPTY_AREA) {
                Navigation.addKnownPaintTower(Constants.decodePos(data, Constants.MSG_PAINT_TOWER));

            } else if (data >= Constants.MSG_CLEARED_AREA
                    && data < Constants.MSG_CLEARED_AREA + 6000) {

                MapLocation cleared = Constants.decodePos(data, Constants.MSG_CLEARED_AREA);
                addClearedTarget(cleared);
            }
        }
    }

    private static void addClearedTarget(MapLocation loc) {
        if (loc == null) return;
        for (int i = 0; i < clearedCount; i++) {
            if (clearedTargets[i].equals(loc)) return;
        }
        if (clearedCount < MAX_CLEARED) {
            clearedTargets[clearedCount++] = loc;
        } else {

            MapLocation myLoc = clearedTargets[0];
            int farthestIdx = 0;

            clearedTargets[0] = loc;
        }
    }

    private static void reportToTower(RobotController rc, int data) throws GameActionException {
        for (RobotInfo a : cachedAllyRobots) {
            if (a.getType().isTowerType() && rc.canSendMessage(a.getLocation(), data)) {
                rc.sendMessage(a.getLocation(), data);
                return;
            }
        }
    }

    private static void broadcastPosition(RobotController rc) throws GameActionException {
        int encoded = Constants.encodePos(Constants.MSG_SOLDIER_POS, rc.getLocation());
        for (RobotInfo a : cachedAllyRobots) {
            if (a.getType().isTowerType() && rc.canSendMessage(a.getLocation(), encoded)) {
                rc.sendMessage(a.getLocation(), encoded);
                return;
            }
        }
    }
}
