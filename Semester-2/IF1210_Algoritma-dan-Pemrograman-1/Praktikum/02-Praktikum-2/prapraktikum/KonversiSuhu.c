// Soal nomor 1
#include <stdio.h>
#include <math.h>

double konversisuhu (double suhuawal, char a, char b);

int main() {
    int x;
    double suhuawal, suhuakhir;
    char a, b;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        scanf("%lf %c %c", &suhuawal, &a, &b); // Input suhuawal, a, b dalam 1 input misal: 100 C F
        suhuakhir = floor(konversisuhu(suhuawal, a, b)); // Menggunakan floor untuk pembulatan ke bawah
        printf("%.2lf\n", suhuakhir);
    }
    return 0;
}

double konversisuhu (double suhuawal, char a, char b) {
    double suhuakhir;
    if (a == 'C' && b == 'F') {
        suhuakhir = (suhuawal * 9/5) + 32;
    } else if (a == 'C' && b == 'K') {
        suhuakhir = suhuawal + 273.15;
    } else if (a == 'F' && b == 'C') {
        suhuakhir = (suhuawal - 32) * 5/9;
    } else if (a == 'F' && b == 'K') {
        suhuakhir = (suhuawal - 32) * 5/9 + 273.15;
    } else if (a == 'K' && b == 'C') {
        suhuakhir = suhuawal - 273.15;
    } else if (a == 'K' && b == 'F') {
        suhuakhir = (suhuawal - 273.15) * 9/5 + 32;
    }
    return suhuakhir;
}