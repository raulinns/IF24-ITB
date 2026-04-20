public class Character {
    // Attribute
    String name;
    int level;
    double powerBase;

    // Konstruktor
    public Character(String name, int level, double powerBase) {
        this.name = name;
        this.level = level;
        this.powerBase = powerBase;
    }

    // Method
    public String getName() {
        return this.name;
    }

    public int getLevel() {
        return this.level;
    }

    public double getPowerBase() {
        return this.powerBase;
    }

    public double calculatePower() {
        return this.powerBase;
    }

    public void printInfo() { 
        System.out.println("Nama: " + this.getName());
        System.out.println("Nama Kapital: " + this.getName().toUpperCase());
        System.out.println("Inisial: " + this.getName().charAt(0));
        System.out.println("Panjang Nama: " + this.getName().length());
        System.out.println("Level: " + this.getLevel());
        System.out.println("Power Akhir: " + this.calculatePower());
    }
}
