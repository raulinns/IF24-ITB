public class Makanan extends Barang {
    private int kalori;

    public Makanan(String nama, int harga, int kalori) {
        super(nama, harga);
        this.kalori = kalori;
    }

    public int getKalori() {
        return this.kalori;
    }

    @Override
    public String info() {
        // Format: "[Makanan] nama - harga IDR (kalori kal)"
        String info = "[Makanan] " + this.nama + " - " + this.harga + " IDR (" + this.kalori + " kal)";
        return info;
    }
}
