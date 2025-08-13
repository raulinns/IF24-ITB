#include <stdio.h>
#include "liststatik.h"

int main() {
    int N, M;
    ListStatik lKebin, lStewart, lGab;

    scanf("%d", &N);
    CreateListStatik(&lKebin);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ELMT(lKebin, i));
    }

    scanf("%d", &M);
    CreateListStatik(&lStewart);
    for (int i = 0; i < M; i++) {
        scanf("%d", &ELMT(lStewart, i));
    }

    CreateListStatik(&lGab);
    int nEffGab = N + M;
    for (int i = 0; i < N; i++) {
        ELMT(lGab, i) = ELMT(lKebin, i);
    }
    
    for (int i = N; i < nEffGab; i++) {
        ELMT(lGab, i) = ELMT(lStewart, i - N);
    }
    sortList(&lGab, TRUE);
    printList(lGab);
    printf("\n");
}