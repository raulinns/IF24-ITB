class Human implements CanSwim, CanRun {
    @Override
    public void swim() {
        System.out.print("Manusia berenang.\n");
    }

    public void run() {
        System.out.print("Manusia berlari.\n");
    }
}