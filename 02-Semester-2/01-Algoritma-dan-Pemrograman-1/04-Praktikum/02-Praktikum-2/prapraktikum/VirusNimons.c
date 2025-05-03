// Soal nomor 3
#include <stdio.h>

int main() {
    int N = 0, T = 0, X = 0;
    do {
        scanf("%d", &N);// Variabel mula-mula
    } while (N < 1 || N > 1000);
    do {
        scanf("%d", &T); // Variabel durasi pembelahan
    } while (T < 1 || T > 30);
    int arr[T];
    arr[0] = N;
    do {
        scanf("%d", &X); // Variabel pengali
    } while (X < 1 || X > 10);
    for (int i = 0; i <= T; i++) {
        arr[i + 1] = arr[i] * X + N;
        printf("Jam ke-%d: %d\n", T, arr[i]);
    }
    return 0;
}