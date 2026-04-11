// Soal Nomor 5

#include <stdio.h>

int main() {
    int N, k;
    scanf("%d %d", &N, &k);
    int angka[N], temp[N];
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            scanf("%d ", &angka[i]);
        } else {
            scanf("%d", &angka[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        temp[(i + k) % N] = angka[i];
    }
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            printf("%d ", temp[i]);
        } else {
            printf("%d\n", temp[i]);
        }
    }
    return 0;
}