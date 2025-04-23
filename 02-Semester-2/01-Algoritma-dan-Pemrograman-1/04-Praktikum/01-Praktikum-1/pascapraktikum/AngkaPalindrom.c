#include <stdio.h>
#include <math.h>

// Soal Nomor 1
int main() {
    int a, b, N, p, count = 0;
    scanf("%d", &N);
    p = log10(N) + 1; // Menghitung jumlah digit pada N
    int mid = p/2, temp2 = N, temp3 = N; // Menentukan nilai tengah dari N, dan membuat variabel baru untuk dioperasikan
    if (p % 2 == 1) { // Penanganan jika digit berjumlah ganjil
        for (int i = (p - 1); i > mid; i--) { // Looping dari digit terakhir hingga digit tengah
            int div2 = pow(10, i); 
            a = temp2 % 10; // Menyimpan digit terakhir dari N
            temp2 /= 10; // Menghapus digit terakhir dari N yang sudah disimpan
            b = temp3 / div2; // Menyimpan digit pertama dari N
            temp3 %= div2; // Menghapus digit pertama dari N yang sudah disimpan
            if (a == b) {
                count++; // Jika digit pertama dan terakhir sama, maka count bertambah
            }
        }
    }
    if (p % 2 == 0) { // Penanganan jika digit berjumlah genap
        for (int i = (p - 1); i >= mid; i--) { 
            // Sama seperti penanganan jumlah digit ganjil, namun dioptimasi untuk digit genap yang tidak mempunyai digit tengah
            int div2 = pow(10, i); 
            a = temp2 % 10; 
            temp2 /= 10;
            b = temp3 / div2;
            temp3 %= div2;
            if (a == b) {
                count++;
            }
        }
    }
    if (count == mid) {
        printf("1\n");
    } else {
        printf("0\n");
    }
}       