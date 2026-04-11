#include "listlinier.h"
#include <stdio.h>
#include "ui.h"

int main() {
    List l;
    CreateList(&l);
    int N, x, temp;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        
        for (int j = 0; j < x; j++) {
            scanf("%d", &temp);
            insertLast(&l, temp);
        }
    }
    return 0;
}