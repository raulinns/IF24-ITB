#include <stdio.h>
#include "queue.h"
#include "stack.h"

int main() {
    int N;
    scanf("%d", &N);
    
    Queue q;
    CreateQueue(&q);
    Stack s;
    CreateEmpty(&s);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        enqueue(&q, temp);
    }

    while (!isEmpty(q)) {
        int current;
        dequeue(&q, &current);
        while (!(IsEmpty(s)) && InfoTop(s) > current) {
            int topValue;
            Pop(&s, &topValue);
            enqueue(&q, topValue);
        }
        Push(&s, current);
    }    // Transfer elements from stack to queue in reverse order (sorted)
    while (!IsEmpty(s)) {
        int topValue;
        Pop(&s, &topValue);
        enqueue(&q, topValue);
    }

    displayQueue(q);
    return 0;
}