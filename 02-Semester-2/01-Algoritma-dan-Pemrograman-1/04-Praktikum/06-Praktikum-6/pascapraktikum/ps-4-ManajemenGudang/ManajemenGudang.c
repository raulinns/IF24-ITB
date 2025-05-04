#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

int main() {
    int N, berat, idx;
    ListStatik l;
    CreateListStatik(&l);
    do {
        scanf("%d", &N);
        if (N == 1) {
            scanf("%d %d", &berat, &idx);
            if (idx >= 0 && idx <= listLength(l) && !isFull(l)) {
                insertAt(&l, berat, idx); 
            } else {
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
        } else if (N == 0) {
            scanf("%d", &idx);
            if (idx >= 0 &&  idx <= listLength(l) && !isEmpty(l)) {
                deleteAt(&l, &berat, idx);
            } else {
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
        } else if (N != -1) {
            printf("Aw, gabisa ngelakuin aksi itu\n");
        }
        if (N != -1) {
            printList(l);
            printf("\n");
        }
    } while (N != -1);
}