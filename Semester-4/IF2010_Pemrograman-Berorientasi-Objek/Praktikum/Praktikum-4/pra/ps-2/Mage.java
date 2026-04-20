public class Mage extends Character {
    // Attribute
    int magicalAtk;

    // Constructor
    public Mage (String name, int level, double powerBase, int magicalAtk) {
        super(name, level, powerBase);
        this.magicalAtk = magicalAtk;
    }

    // Method
    public int getMagicalAtk() {
        return this.magicalAtk;
    }

    @Override public double calculatePower() {
        return powerBase + (this.magicalAtk * 0.5);
    }

    @Override public void printInfo() {
        System.out.println("Nama: " + this.getName());
        System.out.println("Nama Kapital: " + this.getName().toUpperCase());
        System.out.println("Inisial: " + this.getName().charAt(0));
        System.out.println("Panjang Nama: " + this.getName().length());
        System.out.println("Level: " + this.getLevel());
        System.out.println("Power Akhir: " + this.calculatePower());
        System.out.println("Jenis: Mage");
    }
}
