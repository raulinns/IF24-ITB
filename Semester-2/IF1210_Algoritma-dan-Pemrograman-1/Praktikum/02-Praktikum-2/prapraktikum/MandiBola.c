// Soal nomor 2
#include <stdio.h>

void SelamatDatang(int input_1) {
    // Memisahkan variabel yang masuk
    // Masukan yang diterima 1, tetapi perlu menjadi variabel jumlah anak, dewasa, dan lansia
    jumlah_anak = input_1 % 10;
    jumlah_dewasa = (input_1 / 10) % 10;
    jumlah_lansia = (input_1 / 100) % 10;
    // Mencetak luaran antarmuka sesuai soal
    printf("----------------------------------------\nSelamat datang di Wahana Mandi Bola!\n\nSilakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\nHarga tiket:\n- Anak-anak (usia 0-12 tahun): Rp 10000\n- Dewasa (usia 13-64 tahun): Rp 20000\n- Lansia (usia 65 tahun ke atas): Rp 15000\n");
    printf("\nJumlah anak: %d\nJumlah dewasa: %d\nJumlah lansia: %d\n", jumlah_anak, jumlah_dewasa, jumlah_lansia);
    PrintTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
}

int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia) {
    return (jumlah_anak * 10000 + jumlah_dewasa * 20000 + jumlah_lansia * 15000);
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia) {
    printf("Tiket berhasil dibeli!\nRincian:\n- Jumlah anak-anak: %d\n- Jumlah dewasa: %d\n- Jumlah lansia: %d\n- Total biaya: %d\n", jumlah_anak, jumlah_dewasa, jumlah_lansia, HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia));
}

void HandleNimonsHunting(long long input) {
    long long opinput = input; // Input yang sudah dioperasikan
    int length;
    printf("%lld\n", input);
    printf("%lld\n", opinput);
    int jumlah_pergerakan, jumlah_lubang, jumlah_harta_karun;
    int langkah, temukan_harta, tutup_lubang;
    int jumlah_lubang_ditutup = 0, total_harta_karun = 0, total_langkah = 0;
    int harga, total_harga_harta_karun, total_biaya_ganti_rugi, total_keuntungan;
    while (input != 0) { // Menghitung panjang input
        input /= 10;
        length++;
    }
    // Memisahkan variabel yang masuk
    jumlah_pergerakan = opinput % 10;
    jumlah_lubang = (opinput / 10) % 10;
    jumlah_harta_karun = (opinput / 100) % 10;
    opinput /= 1000;
    // Mencetak luaran antarmuka sesuai soal
    printf("----------------------------------------\nSelamat datang di Treasure Hunting Nimons!\n\n");
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", jumlah_pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n", jumlah_lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n", jumlah_harta_karun);
    for (int i = 1; i <= jumlah_pergerakan; i++) { // Perulangan sesuai jumlah langkah
        // Memisahkan variabel per pergerakan
        langkah = opinput % 10;
        temukan_harta = (opinput / 10) % 10;
        tutup_lubang = (opinput / 100) % 10;
        opinput /= 1000;
        // Mencetak luaran antarmuka sesuai soal
        printf("Langkah ke-%d\n", i);
        if (langkah == 0) {
            printf("Nimons tidak bergerak\n");
        } else {
            printf("Nimons bergerak sejauh %d langkah\n", langkah);
            if (temukan_harta == 1) {
                printf("Nimons menemukan harta karun!\n");
                total_harta_karun++;
            }
            if (tutup_lubang == 1) {
                printf("Nimons menutup lubang!\n");
                jumlah_lubang_ditutup++;
            }
            total_langkah += langkah;
        }
    }
    harga = opinput;
    total_harga_harta_karun = total_harta_karun * harga * 5;
    total_biaya_ganti_rugi = harga * jumlah_lubang_ditutup;
    total_keuntungan = total_harga_harta_karun - total_biaya_ganti_rugi;
    // Mencetak luaran antarmuka sesuai soal
    printf("Total lubang yang ditutup: %d dari %d lubang\n", jumlah_lubang_ditutup, jumlah_lubang);
    printf("Total harta karun yang ditemukan: %d\n", total_harta_karun);
    printf("Total harga harta karun yang ditemukan: %d\n", total_harga_harta_karun);
    printf("Total langkah yang ditempuh: %d\n", total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %d\n", total_biaya_ganti_rugi);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n", total_keuntungan);
}