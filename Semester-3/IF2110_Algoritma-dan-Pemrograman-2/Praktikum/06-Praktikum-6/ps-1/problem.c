/* File: problem.c */
/* Implementasi fungsi untuk membalik linked list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk membalik linked list secara in-place
 * I.S. l terdefinisi, mungkin kosong
 * F.S. Elemen-elemen dalam list l dibalik urutannya
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah reverseList(&l), l menjadi [5,4,3,2,1]
 * Jika l adalah [], maka setelah reverseList(&l), l tetap []
 * Jika l adalah [1], maka setelah reverseList(&l), l tetap [1]
 *
 * Hint: Gunakan 3 pointer (prev, current, next) untuk membalik arah pointer
 *       Jangan lupa update FIRST(l) di akhir!
 */
void reverseList(List *l) {
    if (isEmpty(*l) || length(*l) == 1) {
        return;

    } else {
        List l1;
        ElType prev, val;
        CreateList(&l1);
        int n;
        n = length(*l);

        for (int i = 0; i < n; i++) {
            deleteFirst(l, &prev);
            insertFirst(&l1, prev);
        }

        Address p = FIRST(l1);
        int i = 1;
        while (p != NULL) {
            val = INFO(p);
            p = NEXT(p);
            insertLast(l, val);
        }
    } 
    /* KAMUS LOKAL */
    // TODO: Deklarasikan variabel yang diperlukan

    /* ALGORITMA */
    // TODO: Implementasikan algoritma untuk membalik linked list
}