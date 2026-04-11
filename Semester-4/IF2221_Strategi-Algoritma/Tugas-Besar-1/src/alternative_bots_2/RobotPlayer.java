package alternative_bots_2;

import java.util.Arrays;
import java.util.Random;

import battlecode.common.Clock;
import battlecode.common.Direction;
import battlecode.common.GameActionException;
import battlecode.common.MapInfo;
import battlecode.common.MapLocation;
import battlecode.common.Message;
import battlecode.common.PaintType;
import battlecode.common.RobotController;
import battlecode.common.RobotInfo;
import battlecode.common.UnitType;


/**
 * RobotPlayer is the class that describes your main robot strategy.
 * The run() method inside this class is like your main function: this is what we'll call once your robot
 * is created!
 */
public class RobotPlayer {
    /**
     * We will use this variable to count the number of turns this robot has been alive.
     * You can use static variables like this to save any information you want. Keep in mind that even though
     * these variables are static, in Battlecode they aren't actually shared between your robots.
     */
    public static void debug(Object... args){
        System.out.println(Arrays.deepToString(args));
    }
    static int turnCount = 0;
    static int curSpawn = 0; // buat variabel ngatur siapa yg bakal ke spawn per giliran
    static Direction biasDir = null;
    static MapLocation exploreTarget = null;
    static int exploreStuckCount = 0;
    static boolean skip1 = false;
    static Direction myExploreDir = null;
    /**
     * A random number generator.
     * We will use this RNG to make some random moves. The Random class is provided by the java.util.Random
     * import at the top of this file. Here, we *seed* the RNG with a constant number (6147); this makes sure
     * we get the same sequence of numbers every time this code is run. This is very useful for debugging!
     */
    static final Random rng = new Random(6147);

    /** Array containing all the possible movement directions. */
    static final Direction[] directions = {
        Direction.NORTH,
        Direction.NORTHEAST,
        Direction.EAST,
        Direction.SOUTHEAST,
        Direction.SOUTH,
        Direction.SOUTHWEST,
        Direction.WEST,
        Direction.NORTHWEST,
    };

    /**
     * run() is the method that is called when a robot is instantiated in the Battlecode world.
     * It is like the main function for your robot. If this method returns, the robot dies!
     *
     * @param rc  The RobotController object. You use it to perform actions from this robot, and to get
     *            information on its current status. Essentially your portal to interacting with the world.
     **/
    @SuppressWarnings("unused")
    public static void run(RobotController rc) throws GameActionException {
        // Hello world! Standard output is very useful for debugging.
        // Everything you say here will be directly viewable in your terminal when you run a match!
        System.out.println("I'm alive");

        // You can also use indicators to save debug notes in replays.
        rc.setIndicatorString("Hello world!");

        while (true) {
            // This code runs during the entire lifespan of the robot, which is why it is in an infinite
            // loop. If we ever leave this loop and return from run(), the robot dies! At the end of the
            // loop, we call Clock.yield(), signifying that we've done everything we want to do.

            turnCount += 1;  // We have now been alive for one more turn!

            // Try/catch blocks stop unhandled exceptions, which cause your robot to explode.
            try {
                // The same run() function is called for every robot on your team, even if they are
                // different types. Here, we separate the control depending on the UnitType, so we can
                // use different strategies on different robots. If you wish, you are free to rewrite
                // this into a different control structure!
                switch (rc.getType()){
                    case SOLDIER: runSoldier(rc); break; 
                    case MOPPER: runMopper(rc); break;
                    case SPLASHER: runSplasher(rc);break; // Consider upgrading examplefuncsplayer to use splashers!
                    default: runTower(rc); break;
                    }
                }
             catch (GameActionException e) {
                // Oh no! It looks like we did something illegal in the Battlecode world. You should
                // handle GameActionExceptions judiciously, in case unexpected events occur in the game
                // world. Remember, uncaught exceptions cause your robot to explode!
                System.out.println("GameActionException");
                e.printStackTrace();

            } catch (Exception e) {
                // Oh no! It looks like our code tried to do something bad. This isn't a
                // GameActionException, so it's more likely to be a bug in our code.
                System.out.println("Exception");
                e.printStackTrace();

            } finally {
                // Signify we've done everything we want to do, thereby ending our turn.
                // This will make our code wait until the next turn, and then perform this loop again.
                Clock.yield();
            }
            // End of loop: go back to the top. Clock.yield() has ended, so it's time for another turn!
        }

        // Your code should never reach here (unless it's intentional)! Self-destruction imminent...
    }

    /**
     * Run a single turn for towers.
     * This code is wrapped inside the infinite loop in run(), so it is called once per turn.
     */
    public static void runTower(RobotController rc) throws GameActionException{
        // Pick a direction to build in.
        int robotType = (curSpawn + 1) % 3;
        UnitType typeToBuild = robotType == 0 ? UnitType.SOLDIER
                             : robotType == 1 ? UnitType.MOPPER
                             : UnitType.SPLASHER;
        
        boolean built = false;
        for(Direction dir : directions){
            MapLocation nextLoc = rc.getLocation().add(dir);
            if(rc.canBuildRobot(typeToBuild, nextLoc)){
                rc.buildRobot(typeToBuild, nextLoc);
                curSpawn++;// increment 

                built = true;
                break;
            }
        }
        if(!built) debug("[Tower] FAILED to build", typeToBuild);
        // Direction dir = directions[rng.nextInt(directions.length)];
        // MapLocation nextLoc = rc.getLocation().add(dir);
        // Pick a random robot type to build.
        // int robotType = rng.nextInt(3);
        // if (robotType == 0 && rc.canBuildRobot(UnitType.SOLDIER, nextLoc)){
        //     rc.buildRobot(UnitType.SOLDIER, nextLoc);
        //     System.out.println("BUILT A SOLDIER");
        // }
        // else if (robotType == 1 && rc.canBuildRobot(UnitType.MOPPER, nextLoc)){
        //     rc.buildRobot(UnitType.MOPPER, nextLoc);
        //     System.out.println("BUILT A MOPPER");
        // }
        // else if (robotType == 2 && rc.canBuildRobot(UnitType.SPLASHER, nextLoc)){
        //     // rc.buildRobot(UnitType.SPLASHER, nextLoc);
        //     // System.out.println("BUILT A SPLASHER");
        //     rc.setIndicatorString("SPLASHER NOT IMPLEMENTED YET");
        // }

        // Read incoming messages
        Message[] messages = rc.readMessages(-1);
        for (Message m : messages) {
            System.out.println("Tower received message: '#" + m.getSenderID() + " " + m.getBytes());
        }

        // TODO: can we attack other bots?
        RobotInfo[] enemyRobots = rc.senseNearbyRobots(-1,rc.getTeam().opponent());
        for(RobotInfo enemy : enemyRobots){
            MapLocation enemyLoc = enemy.getLocation(); // locate robot musu
            if(rc.canAttack(enemyLoc)) {rc.attack(enemyLoc); break;}
        }

    }


    /**
     * Run a single turn for a Soldier.
     * This code is wrapped inside the infinite loop in run(), so it is called once per turn.
     */
    static int countTow = 0;
    static boolean skipfirst = false;
    public static void runSoldier(RobotController rc) throws GameActionException{

        // Sense information about all visible nearby tiles.
        if(rc.getRoundNum() > 500) skipfirst = true;
        MapInfo[] nearbyTiles = rc.senseNearbyMapInfos();
        MapLocation myLoc = rc.getLocation();
        if(biasDir == null){
            biasDir = directions[rc.getID() % 8];
            exploreTarget = mapEdgeTarget(rc,myLoc, biasDir);
            exploreStuckCount = 0;
        }
        // Search for a nearby ruin to complete.
        MapInfo curRuin = null;
        for (MapInfo tile : nearbyTiles){
            if (tile.hasRuin()){
                MapLocation ruinLoc = tile.getMapLocation();

                RobotInfo sudahAda = null;
                if(rc.canSenseRobotAtLocation(ruinLoc)) sudahAda = rc.senseRobotAtLocation(ruinLoc);
                // curRuin = tile;

                if(sudahAda == null){
                    curRuin = tile;
                    break;
                }
            }
        }
        // MapInfo curRuin = null;
        // // Prioritas skrg :: menanganai ruins dulu
        if (curRuin != null && myLoc.distanceSquaredTo(curRuin.getMapLocation()) <= 8 && rc.getPaint() != 0 && !skipfirst)  {
            MapLocation targetLoc = curRuin.getMapLocation();
            Direction dir = rc.getLocation().directionTo(targetLoc);
            if (rc.canMove(dir))
                rc.move(dir);
            MapLocation shouldBeMarked = curRuin.getMapLocation().subtract(dir);
            if (rc.senseMapInfo(shouldBeMarked).getMark() == PaintType.EMPTY
                    && rc.canMarkTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, targetLoc)) {
                rc.markTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, targetLoc);
                System.out.println("Trying to build tower at " + targetLoc);
            }
            for (MapInfo patternTile : rc.senseNearbyMapInfos(targetLoc, 8)) {
                if (patternTile.getMark() != patternTile.getPaint()
                        && patternTile.getMark() != PaintType.EMPTY) {
                    boolean useSecondaryColor = patternTile.getMark() == PaintType.ALLY_SECONDARY;
                    if (rc.canAttack(patternTile.getMapLocation()))
                        rc.attack(patternTile.getMapLocation(), useSecondaryColor);
                }
            }
            if (rc.canCompleteTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, targetLoc)) {
                rc.completeTowerPattern(UnitType.LEVEL_ONE_PAINT_TOWER, targetLoc);
                rc.setTimelineMarker("Tower built", 0, 255, 0);
                System.out.println("Built a tower at " + targetLoc + "!");
            }
            // Cat petak saat ini jika aksi masih tersedia
            myLoc = rc.getLocation();
            if (rc.getActionCooldownTurns() < 10 && rc.getPaint() > 0) {
                MapInfo cur = rc.senseMapInfo(myLoc);
                if (!cur.getPaint().isAlly() && rc.canAttack(myLoc))
                    rc.attack(myLoc);
            }
            rc.setIndicatorString("Ruin mode target=" + targetLoc);
            // return;
        }
        // Prioritas 2: Fase Sebar, taktik KAMIKAZEEE 
        // Target adalah titik tepi peta searah biasDir.
        // Refresh hanya kalau null atau sudah dekat target (dist^2 <= 8).
        if (exploreTarget == null || myLoc.distanceSquaredTo(exploreTarget) <= 8) {
            biasDir = biasDir.rotateLeft(); // geser sektor sedikit supaya coverage lebih luas
            exploreTarget = mapEdgeTarget(rc, myLoc, biasDir);
            exploreStuckCount = 0;
        }

        // Gerak menuju target eksplorasi
        if (rc.getMovementCooldownTurns() < 10) {
            Direction moveDir = null;
            if (exploreTarget != null) {
                Direction preferred = myLoc.directionTo(exploreTarget);
                if (rc.canMove(preferred)) {
                    moveDir = preferred;
                    exploreStuckCount = 0;
                } else {
                    Direction left = preferred.rotateLeft();
                    Direction right = preferred.rotateRight();
                    if (rc.canMove(left)) { moveDir = left; exploreStuckCount = 0; }
                    else if (rc.canMove(right)) { moveDir = right; exploreStuckCount = 0; }
                    else {
                        exploreStuckCount++;
                        if (exploreStuckCount >= 3) {
                            exploreTarget = null;
                            exploreStuckCount = 0;
                        }
                    }
                }
            }
            // Fallback: coba arah bias dulu, baru acak
            if (moveDir == null) {  
                if (rc.canMove(biasDir)) {
                    moveDir = biasDir;
                } else {
                    int start = rng.nextInt(directions.length);
                    for (int i = 0; i < directions.length; i++) {
                        Direction d = directions[(start + i) % directions.length];
                        if (rc.canMove(d)) { moveDir = d; break; }
                    }
                }
            }
            if (moveDir != null) rc.move(moveDir);
        }

        // Cat:utamakan petak yang baru diinjak,baru non-ally terdekat
        myLoc = rc.getLocation();
        if (rc.getActionCooldownTurns() < 10 && rc.getPaint() > 0) {
            MapInfo cur = rc.senseMapInfo(myLoc);
            if (!cur.getPaint().isAlly() && rc.canAttack(myLoc)) {
                rc.attack(myLoc);
            } else {
                MapLocation attackTarget = findNearestNonAllyTile(rc);
                if (attackTarget != null && rc.canAttack(attackTarget))
                    rc.attack(attackTarget);
            }
        }

        rc.setIndicatorString("Spread bias=" + biasDir + " target=" + exploreTarget);

    }
    public static MapLocation mapEdgeTarget(RobotController rc, MapLocation from, Direction dir) {
        int far = Math.max(rc.getMapWidth(), rc.getMapHeight());
        int tx = Math.max(0, Math.min(rc.getMapWidth()  - 1, from.x + dir.dx * far));
        int ty = Math.max(0, Math.min(rc.getMapHeight() - 1, from.y + dir.dy * far));
        return new MapLocation(tx, ty);
    }
    public static MapLocation findNearestNonAllyTile(RobotController rc) throws GameActionException {
        MapLocation myLoc = rc.getLocation();
        MapLocation nearest = null;
        int minDist = Integer.MAX_VALUE;
        for (MapInfo tile : rc.senseNearbyMapInfos()) {
            if (!tile.getPaint().isAlly()) {
                int dist = myLoc.distanceSquaredTo(tile.getMapLocation());
                if (dist < minDist) {
                    minDist = dist;// update nilai min
                    nearest = tile.getMapLocation();
                }
            }
        }
        return nearest;
    }
    public static void runSplasher(RobotController rc) throws GameActionException {
        MapLocation myLoc = rc.getLocation();

        // Fase Serangan
        // syarat: ction cooldown < 10 dan cat >= 50.
        if (rc.getActionCooldownTurns() < 10 && rc.getPaint() >= 50) {
            MapLocation bestTarget = null;
            int maxScore = 0;
            // Kandidat: semua petak dalam jarak^2 <= 4 (maksimal 2 petak) dari posisi Splasher.
            for (MapInfo tile : rc.senseNearbyMapInfos(myLoc, 4)) {
                MapLocation loc = tile.getMapLocation();
                if (!rc.canAttack(loc)) continue;
                int score = 0;
                // Evaluasi setiap petak dalam radius sqrt(2) krn d^2 <= 2 dari titik pusat.
                for (MapInfo splash : rc.senseNearbyMapInfos(loc, 2)) {
                    PaintType paint = splash.getPaint();
                    if (paint == PaintType.EMPTY) {
                        score += 1;   // Petak kosong: +1
                    } else if (paint.isEnemy()) {
                        score += 2;   // Petak musuh: +2
                    }
                }
                // Menara musuh dalam area splash: +50
                for (RobotInfo robot : rc.senseNearbyRobots(loc, 2, rc.getTeam().opponent())) {
                    UnitType rType = robot.getType();
                    if (rType != UnitType.SOLDIER && rType != UnitType.MOPPER && rType != UnitType.SPLASHER) {
                        score += 50;
                    }
                }
                if (score > maxScore) {
                    maxScore = score;
                    bestTarget = loc;
                }
            }
            if (bestTarget != null) {
                rc.attack(bestTarget);
                rc.setIndicatorString("Splasher attacking, score=" + maxScore);
            }
        }

        // Fase Pergerakan 
        // Bergerak independen dari action cooldown
        if (rc.getMovementCooldownTurns() < 10) {
            if (rc.getPaint() < 20) {
                // Cat kurang: dekati ally tower atau Mopper terdekat untuk isi ulang.
                MapLocation refill = findRefillTarget(rc);
                if (refill != null) {
                    Direction dir = myLoc.directionTo(refill);
                    if (rc.canMove(dir)) {
                        rc.move(dir);
                        rc.setIndicatorString("Splasher heading to refill");
                        return;
                    }
                }
            } else {
                // cek apakah ada musuh di sekitar
                RobotInfo[] enemiesNearby = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
                if (enemiesNearby.length > 0) {
                    MapLocation enemyLoc = enemiesNearby[0].getLocation();
                    Direction dir = myLoc.directionTo(enemyLoc);
                    // Jangan terlalu dekat, jaga jarak buat splash
                    if (myLoc.distanceSquaredTo(enemyLoc) > 4 && rc.canMove(dir)) {
                         rc.move(dir);
                         rc.setIndicatorString("Splasher hunting enemies!");
                         return;
                    }
                }

                // kalo gaada musuh, cari petak buat dicat
                MapLocation target = findNearestNonAllyTile(rc);
                if (target != null) {
                    Direction dir = myLoc.directionTo(target);
                    if (rc.canMove(dir)) {
                        rc.move(dir);
                        rc.setIndicatorString("Splasher moving to non-ally tile");
                        return;
                    }
                }
            }
            if (myExploreDir == null) {
                // Tentukan arah acak saat baru lahir
                myExploreDir = directions[rc.getID() % 8]; 
            }

            // Coba jalan ke arah kompas
            if (rc.canMove(myExploreDir)) {
                rc.move(myExploreDir);
                rc.setIndicatorString("Splasher exploring: " + myExploreDir);
            } else {
                // Kalau nabrak, coba belok
                if (rc.canMove(myExploreDir.rotateLeft())) {
                    myExploreDir = myExploreDir.rotateLeft();
                    rc.move(myExploreDir);
                } else if (rc.canMove(myExploreDir.rotateRight())) {
                    myExploreDir = myExploreDir.rotateRight();
                    rc.move(myExploreDir);
                } else {
                    // Kalau mentok parah, putar balik
                    myExploreDir = myExploreDir.opposite();
                }
            }
            // gerak acak.
            Direction dir = directions[rng.nextInt(directions.length)];
            if (rc.canMove(dir)) rc.move(dir);
        }
    }
     
    // mencari paint tower ally paling deket atau mopper untuk refill paint
    public static MapLocation findRefillTarget(RobotController rc) throws GameActionException {
        MapLocation myLoc = rc.getLocation();
        MapLocation nearest = null;
        int minDist = Integer.MAX_VALUE;
        for (RobotInfo ally : rc.senseNearbyRobots(-1, rc.getTeam())) {
            UnitType type = ally.getType();
            if (type != UnitType.SOLDIER && type != UnitType.MOPPER && type != UnitType.SPLASHER) {
                int dist = myLoc.distanceSquaredTo(ally.getLocation());
                if (dist < minDist) {
                    minDist = dist;
                    nearest = ally.getLocation();
                }
            }
        }
        return nearest;
    }

    /**
     * Run a single turn for a Mopper.
     * This code is wrapped inside the infinite loop in run(), so it is called once per turn.
     */
    public static void runMopper(RobotController rc) throws GameActionException{
        // Move and attack randomly.
        // Direction dir = directions[rng.nextInt(directions.length)];
        // MapLocation nextLoc = rc.getLocation().add(dir);
        // if (rc.canMove(dir)){
        //     rc.move(dir);
        // }
        // if (rc.canMopSwing(dir)){
        //     rc.mopSwing(dir);
        //     System.out.println("Mop Swing! Booyah!");
        // }
        // else if (rc.canAttack(nextLoc)){
        //     rc.attack(nextLoc);
        // }
        // // We can also move our code into different methods or classes to better organize it!
        // updateEnemyRobots(rc);
        MapLocation myLoc = rc.getLocation();
        RobotInfo[] enemiesNearby = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
        boolean actionTaken = false;

        // FASE 1: Serangan & Support)
        if (rc.getActionCooldownTurns() < 10) { // Cek apakah siap melakukan aksi
            
            // Coba Mop Swing (Hanya 4 arah utama)
            Direction[] cardinalDirs = {Direction.NORTH, Direction.SOUTH, Direction.EAST, Direction.WEST};
            for (Direction dir : cardinalDirs) {
                if (rc.canMopSwing(dir) && isEnemyInSwingPath(rc, myLoc, dir, enemiesNearby)) {
                    rc.mopSwing(dir);
                    System.out.println("Mop Swing Dieksekusi ke arah: " + dir);
                    actionTaken = true;
                    break;
                }
            }

            // Coba Mop biasa ke robot musuh
            if (!actionTaken) {
                for (RobotInfo enemy : enemiesNearby) {
                    MapLocation enemyLoc = enemy.getLocation();
                    if (myLoc.distanceSquaredTo(enemyLoc) <= 2) {
                        if (rc.canAttack(enemyLoc)) { // Asumsi attack() merujuk ke Mop petak
                            rc.attack(enemyLoc);
                            System.out.println("Mop Steal! Curi 5 cat dari musuh di " + enemyLoc);
                            actionTaken = true;
                            break;
                        }
                    }
                }
            }

            // Coba Transfer Cat ke sekutu (Jika cat sendiri udah cukup aman)
            if (!actionTaken && rc.getPaint() > 40) {
                RobotInfo[] alliesNearby = rc.senseNearbyRobots(2, rc.getTeam());
                for (RobotInfo ally : alliesNearby) {
                    if (ally.getType() == UnitType.SPLASHER || ally.getType().isTowerType()) {
                        // panggill metode buat tf cat
                        if (rc.canTransferPaint(ally.getLocation(), 20)) {
                            rc.transferPaint(ally.getLocation(), 20);
                            actionTaken = true;
                            break;
                        }
                    }
                }
            }
        }

        // Fase movement
        if (rc.getMovementCooldownTurns() < 10) {
            Direction moveDir = null;

            if (enemiesNearby.length > 0) {
                // Kejar musuh terdekat
                MapLocation targetEnemy = enemiesNearby[0].getLocation();
                moveDir = myLoc.directionTo(targetEnemy);
            } else {
                // Bersihkan lantai musuh atau jalan acak
                MapLocation dirtyTile = findNearestNonAllyTile(rc);
                if (dirtyTile != null) {
                    moveDir = myLoc.directionTo(dirtyTile);
                } else {
                    moveDir = directions[rng.nextInt(directions.length)];
                }
            }

            // Eksekusi jalan
            if (moveDir != null && rc.canMove(moveDir)) {
                rc.move(moveDir);
            } else if (moveDir != null) {
                // Kalau terhalang, coba belok sedikit 
                if (rc.canMove(moveDir.rotateLeft())) rc.move(moveDir.rotateLeft());
                else if (rc.canMove(moveDir.rotateRight())) rc.move(moveDir.rotateRight());
            }
        }
        updateEnemyRobots(rc);
    }
    public static boolean isEnemyInSwingPath(RobotController rc, MapLocation myLoc, Direction dir, RobotInfo[] enemies) {
        MapLocation step1 = myLoc.add(dir);
        MapLocation step2 = step1.add(dir);
        
        for (RobotInfo enemy : enemies) {
            MapLocation eloc = enemy.getLocation();
            // Swing mengenai target di step 1, step 2, dan sisi-sisinya (total 6 petak)
            // Deteksi sederhana: Jika musuh berjarak sangat dekat dengan arah vektor serangan
            if (eloc.distanceSquaredTo(step1) <= 2 || eloc.distanceSquaredTo(step2) <= 2) {
                return true;
            }
        }
        return false;
    }
    public static void updateEnemyRobots(RobotController rc) throws GameActionException{
        // Sensing methods can be passed in a radius of -1 to automatically 
        // use the largest possible value.
        RobotInfo[] enemyRobots = rc.senseNearbyRobots(-1, rc.getTeam().opponent());
        if (enemyRobots.length != 0){
            rc.setIndicatorString("There are nearby enemy robots! Scary!");
            // Save an array of locations with enemy robots in them for possible future use.
            MapLocation[] enemyLocations = new MapLocation[enemyRobots.length];
            for (int i = 0; i < enemyRobots.length; i++){
                enemyLocations[i] = enemyRobots[i].getLocation();
            }
            RobotInfo[] allyRobots = rc.senseNearbyRobots(-1, rc.getTeam());
            // Occasionally try to tell nearby allies how many enemy robots we see.
            if (rc.getRoundNum() % 20 == 0){
                for (RobotInfo ally : allyRobots){
                    if (rc.canSendMessage(ally.location, enemyRobots.length)){
                        rc.sendMessage(ally.location, enemyRobots.length);
                    }
                }
            }
        }
    }
}
