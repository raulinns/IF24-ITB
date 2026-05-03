public class Pakaian extends Barang {
    private String ukuran;

    public Pakaian(String nama, int harga, String ukuran) {
        super(nama, harga);
        this.ukuran = ukuran;
    }

    public String getUkuran() {
        return this.ukuran;
    }

    @Override
    public String info() {
        // Format: "[Pakaian] nama - harga IDR (ukuran)"
        String info = "[Pakaian] " + this.nama + " - " + this.harga + " IDR (" + this.ukuran + ")";
        return info;
    }
}
