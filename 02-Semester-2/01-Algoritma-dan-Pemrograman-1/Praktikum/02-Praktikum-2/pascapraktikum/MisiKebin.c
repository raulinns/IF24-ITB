// Soal Nomor 1

#include <stdio.h>

int countPrime(int A, int B, int total);

// TODO: Implementasi prosedur untuk menghitung jumlah bilangan prima dalam rentang [A, B]
// Saat ini, total tidak bisa diperbarui karena hanya merupakan salinan dari nilai di main()
int main()
{
    int A, B, total;
    scanf("%d %d", &A, &B);
    // TODO: Baca dua bilangan integer A dan B dalam satu baris
    // Input harus dalam format: "A B"
    // TODO: Perbaiki pemanggilan prosedur dengan menggunakan alamat variabel total
    // Agar perubahan nilai di dalam prosedur juga mempengaruhi nilai di main()
    total = countPrime(A, B, total);
    printf("%d\n", total);
    return 0;
}

// TODO: Perbaiki prosedur agar variabel total bisa diperbarui secara langsung
int countPrime(int A, int B, int total) { // Mengganti void dengan int agar dapat mengembalikan nilai total
    total = 0;
    for (int i = A; i <= B; i++) {
        int temp = 0;
        for (int j = 2; j * j <= i; j++) { // Mengecek apakah i merupakan bilangan prima
            if (i % j == 0) {
                temp = 1; // Jika i bukan bilangan prima, temp diubah menjadi 1
                break;
            } 
        }
        if (temp == 0 && i != 1) { // Jika i merupakan bilangan prima, total ditambah 1
            total++;
        }
    }
    return total;
}
// Hasil kerja sama dengan 13524042 - Suryani Mulia Utami
    