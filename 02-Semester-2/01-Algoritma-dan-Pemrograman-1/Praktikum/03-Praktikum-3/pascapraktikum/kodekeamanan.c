// Soal Nomor 2

#include <stdio.h>

int main() {
    int N, target;
    scanf("%d", &N);
    int angka[N];
    for (int i = 0; i < N; i++) {
        if (i != N) {
            scanf("%d ", &angka[i]);
        } else {
            scanf("%d", &angka[i]);
        }
    }
    scanf("%d", &target);
    int min_i = N, min_j = N;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if ((angka[i] + angka[j] == target) && (i != j)) {
                if (i < min_i || (i == min_i && j < min_j)) {
                    min_i = i;
                    min_j = j;
                }
            }
        }
    }
    if (min_i < N) {
        printf("[%d, %d]\n", min_i, min_j);
        return 0;
    }
    return 0;
}