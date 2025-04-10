// Soal Nomor 3
#include <stdio.h>

int main() {
    int N = 0;
    do
    {
        scanf("%d", &N);
    } while (N < 0 || N > 60);
    for (int i = 0; i < N; i++) {
        long long C = 1; // Menggunakan long untuk mengakomodasi angka sampai baris segitiga pascal ke 60
        for (int k = (N - i - 2); k >= 0; k--) { // Membuat spasi sebelum angka yang dicetak agar berbentuk segitiga
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%lld", C);
            C = C * (i - j) / (j + 1); // Rumus kombinatorika untuk mencari angka segitiga pascal (Cek soal)
            if (j < i) {
                printf(" "); // Membuat spasi antar angka yang dicetak
            }
        }
        printf("\n");
    }
    return 0;
}