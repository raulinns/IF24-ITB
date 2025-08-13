// Soal Nomor 5
#include <stdio.h>

int main() {
    int N, diagonal, maxterisi, nilai;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxterisi = 0;
            diagonal = i + j;
            for (int d = 0; d < diagonal; d++) { // Mengecek seberapa banyak angka yang dapat diisi dalam suatu diagonal
                if (d < N) {
                    maxterisi += d + 1;
                } else {
                    maxterisi += 2 * N - d - 1;
                }
            }
            nilai = 0;
            for (int k = 0; k <= i; k++) { // Mengecek seberapa banyak angka yang sebelumnya sudah diisi dalam suatu posisi
                int l = diagonal - k;
                if (k < N && l >= 0 && l < N && k <= i) {
                    nilai++;
                }
            }
            nilai += maxterisi; // Menambahkan angka yang sudah diisi sebelumnya
            printf("%d", nilai);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

// Big thanks to Copilot AI dan Claude AI yang membantu dalam pembuatan kode ini
// Disclaimer: Ide pembuatan murni dari pemikiran saya sendiri, implementasi kode menggunakan bantuan AI
