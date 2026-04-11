package main_bot;

import battlecode.common.*;

public class RobotPlayer {

    static int turnCount = 0;

    public static void run(RobotController rc) throws GameActionException {
        while (true) {
            turnCount++;
            try {
                dispatch(rc);
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

    private static void dispatch(RobotController rc) throws GameActionException {
        switch (rc.getType()) {
            case SOLDIER:
                SoldierStrategy.run(rc);
                break;
            case SPLASHER:
                SplasherStrategy.run(rc);
                break;
            case MOPPER:
                MopperStrategy.run(rc);
                break;
            default:
                TowerStrategy.run(rc);
                break;
        }
    }
}
