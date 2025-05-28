#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    CreateQueue(&q);
    int N, sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        enqueue(&q, temp);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            int max = q.buffer[j];
            for (int k = j; k < j + i; k++) {
                if (max < q.buffer[k]) max = q.buffer[k];
            }
            sum += max;
        }
    }

    printf("%d\n", sum);
    return 0;
}