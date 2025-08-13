#include "queue.h"

void prioritizeValue(Queue *q, int x) {
    Queue qTemp1, qTemp2;
    CreateQueue(&qTemp1);
    CreateQueue(&qTemp2);
    int val;

    while (!isEmpty(*q)) {
        dequeue(q, &val);
        if (val == x) {
            enqueue(&qTemp1, val);
        } else {
            enqueue(&qTemp2, val);
        }
    }
    
    while (!isEmpty(qTemp1)) {
        dequeue(&qTemp1, &val);
        enqueue(q, val);
    }

    while (!isEmpty(qTemp2)) {
        dequeue(&qTemp2, &val);
        enqueue(q, val);
    }
}