public class Fighter extends Character {
    // Attribute
    int physicalAtk;

    // Constructor
    public Fighter (String name, int level, double powerBase, int physicalAtk) {
        super(name, level, powerBase);
        this.physicalAtk = physicalAtk;
    }

    // Method
    public int getPhysicalAtk() {
        return this.physicalAtk;
    }

    @Override public double calculatePower() {
        return this.powerBase + (this.physicalAtk * 0.7);
    }

    @Override public void printInfo() {
        System.out.println("Nama: " + this.getName());
        System.out.println("Nama Kapital: " + this.getName().toUpperCase());
        System.out.println("Inisial: " + this.getName().charAt(0));
        System.out.println("Panjang Nama: " + this.getName().length());
        System.out.println("Level: " + this.getLevel());
        System.out.println("Power Akhir: " + this.calculatePower());
        System.out.println("Jenis: Fighter");
    }
}
