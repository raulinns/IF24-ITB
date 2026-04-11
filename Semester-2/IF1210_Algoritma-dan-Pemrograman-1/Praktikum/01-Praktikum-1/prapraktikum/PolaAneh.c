#include <stdio.h>

int main(){
    int N;
    do
    {
        scanf("%d", &N);
    } while (!((1 <= N && N <= 25) && (N % 2 == 1)));
    char code[N][N];
    int half = N / 2;
    int p = 0, q = half;

    for (int i = 0; i <= half; i++) {
        for (int j = 0; j < N; j++) {
            code[i][j] = '.';
        }
        code[i][half - p] = '*';
        code[i][half + p] = '*';
        if (p < half) {
            p++;
        }
    }
    p = 0;
    for (int i = (N - 1); i > half; i--) {
        for (int j = 0; j < N; j++) {
            code[i][j] = '.';
        }
        code[i][half - p] = '*';
        code[i][half + p] = '*';
        if (p >= 0) {
            p++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", code[i][j]);
        }
        printf("\n");
    }
    return 0;
}