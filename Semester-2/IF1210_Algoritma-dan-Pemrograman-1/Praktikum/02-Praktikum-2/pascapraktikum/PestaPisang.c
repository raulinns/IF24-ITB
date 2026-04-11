// Soal Nomor 2

#include <stdio.h>

const int jumlah_nimons = 5; // Parameter tetap yaitu 5
int Hitung_Total_Pisang(int a, int b, int c, int d, int e);
double Hitung_RataRata_Pisang(int a, int b, int c, int d, int e, int jumlah_nimons);
void Pesan(int a, int b, int c, int d, int e, int jumlah_nimons);

int main() {
    int a, b, c, d, e;
    scanf("%d\n%d\n%d\n%d\n%d", &a ,&b, &c, &d, &e);
    printf("%d\n", Hitung_Total_Pisang(a, b, c, d, e));
    printf("%lf\n", Hitung_RataRata_Pisang(a, b, c, d, e, jumlah_nimons));
    Pesan(a, b, c, d, e, jumlah_nimons);
    return 0;
}

int Hitung_Total_Pisang(int a, int b, int c, int d, int e) {
    return (a + b + c + d + e); // Total pisang yang dikumpulkan
}
double Hitung_RataRata_Pisang(int a, int b, int c, int d, int e, int jumlah_nimons) {
    return (Hitung_Total_Pisang(a, b, c, d, e) / jumlah_nimons); // Rata-rata pisang yang dikumpulkan
}
void Pesan(int a, int b, int c, int d, int e, int jumlah_nimons){
    if (Hitung_RataRata_Pisang(a, b, c, d, e, jumlah_nimons) >= 10) { // Luaran sesuai perintah soal
        printf("Pesta Nimons Sukses!\n");
    } else {
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}
// Hasil kerja sama dengan 13524042 - Suryani Mulia Utami
