public class KotakUtils {

    // Upper-bounded wildcard: membaca dari Kotak yang berisi subtype Barang apapun
    public static void tampilkanSemua(Kotak<? extends Barang> kotak) {
        // Cetak info() setiap item, satu per baris
        // Jika kosong, cetak "Kotak kosong"
        if (kotak.kosong()) {
            System.out.println("Kotak kosong");
        } else {
            for (int i = 0; i < kotak.jumlah(); i++) {
                System.out.println(kotak.lihat(i).info());
            }
        }
    }

    // Upper-bounded wildcard: menghitung total harga
    public static int totalHarga(Kotak<? extends Barang> kotak) {
        int total = 0;
        for (int i = 0; i < kotak.jumlah(); i++) {
            total += kotak.lihat(i).getHarga();
        }
        return total;
    }

    // Upper-bounded wildcard: mencari item termahal
    public static Barang termahal(Kotak<? extends Barang> kotak) {
        if (kotak.kosong()) {
            return null;
        } else {
            Barang brgTermahal = kotak.lihat(0);
            for (int i = 1; i < kotak.jumlah(); i++) {
                if (brgTermahal.getHarga() < kotak.lihat(i).getHarga()) {
                    brgTermahal = kotak.lihat(i);
                }
            }
            return brgTermahal;
        }
    }

    // Bounded wildcard dengan type parameter (PECS: Producer Extends, Consumer Super)
    // src menggunakan ? extends T (producer/pembaca), item diambil dari src
    // dst menggunakan ? super T (consumer/penulis), item ditambahkan ke dst
    public static <T extends Barang> int pindahkan(Kotak<? extends T> src, Kotak<? super T> dst) {
        // Pindahkan item dari src ke dst secara LIFO
        // Berhenti jika src kosong atau dst penuh
        // Kembalikan jumlah item yang dipindahkan
        int jumlahPindah = 0;
        while (!src.kosong() && !dst.penuh()) {
            T currentItem = src.ambil();
            dst.tambah(currentItem);
            jumlahPindah++;
        }

        return jumlahPindah;
    }

    // Unbounded wildcard: hanya perlu menghitung jumlah
    public static int hitungItem(Kotak<?> kotak) {
        return kotak.jumlah();
    }
}
