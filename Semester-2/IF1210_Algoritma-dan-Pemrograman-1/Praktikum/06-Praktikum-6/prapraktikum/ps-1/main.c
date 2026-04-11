#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik l1, l2, lResult;
    readList(&l1);
    printf("Panjang list: %d\n", listLength(l1));
    printf("Indeks pertama: %d\n", getFirstIdx(l1));
    printf("Indeks terakhir: %d\n", getLastIdx(l1));

    printList(l1);
    printf("\n");

    // printf("Search for 5: %d", indexOf(l1, 5));
    // int max, min;
    // extremeValues(l1, &max, &min);
    // printf("\nMax: %d, Min: %d\n", max, min);

    // // insertFirst(&l1, 10);
    // // insertAt(&l1, 10, 2);
    // // insertLast(&l1, 10);
    // int val;
    // // deleteFirst(&l1, &val);
    // // deleteAt(&l1, &val, 2);
    // deleteLast(&l1, &val);
    // printf("Hapus elemen terakhir: %d\n", val);



    sortList(&l1, FALSE);
    printList(l1);
    printf("\n");
    printf("Panjang list: %d\n", listLength(l1));
    return 0;
}