// Soal Nomor 4
#include <stdio.h>

int main() {
    int N, count = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) { // Looping dari 1 hingga N
        if (N % i == 0) { // Mengecek apakah i merupakan faktor dari N
            for (int j = 1; j <= i; j++) {
                if (j * j == i) { // Mengecek apakah i merupakan bilangan kuadrat
                    count++;
                }
            }
        }
    }
    printf("%d\n", count); 
    return 0;
}