#include "moveon.h"
#include <stdio.h>

void removeAll(List *l, ElType val) {
    Address p = FIRST(*l);
    while (p != NULL) {
        if (INFO(p) == val) {
            int delIdx = indexOf(*l, val); int temp;
            deleteAt(l, delIdx, &temp);
        }
        p = NEXT(p);
    }
    displayList(*l);
    printf("\n");
}