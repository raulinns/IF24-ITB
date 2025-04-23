// Soal Nomor 2
#include <stdio.h>


int main() {
    int N = 0, count, urutan = 0;
    scanf("%d", &N);
    int temp = N;
    while (temp % 2 == 0) { // Mengecek apakah 2 merupakan faktor dari N
        count = 0;
        while (temp % 2 == 0) { // Mengecek seberapa banyak i merupakan faktor dari N
            temp = temp / 2;
            count += 1; 
        }
        if (count > 1) { // Program luaran sesuai keinginan soal
            printf("2^%d", count);
            urutan = 1;
        } else {
            printf("2");
            urutan = 1;
        }
    }
    for (int i = 3; i <= temp; i+= 2) { // Mengecek apakah i merupakan faktor dari N dengan i adalah bilangan ganjil positif kecuali 1
        count = 0;
        if (temp % i == 0) {
            while (temp % i == 0) { // Mengecek seberapa banyak i merupakan faktor dari N
                temp = temp / i;
                count += 1; 
            }
            if (urutan == 0) { // Program luaran sesuai keinginan soal
                if (count > 1) {
                    printf("%d^%d", i, count);
                    urutan = 1;
                } else {
                    printf("%d", i);
                    urutan = 1;
                }
            } else {
                if (count > 1) {
                    printf(" * %d^%d", i, count);
                } else {
                    printf(" * %d", i);
                }
            }
        }
    }
    printf("\n");
    return 0;
}