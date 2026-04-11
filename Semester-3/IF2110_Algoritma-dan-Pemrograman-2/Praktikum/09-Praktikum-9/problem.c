/* File: problem.c */
/* Implementasi fungsi untuk merotasi linked list ke kanan sebanyak k posisi */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List copyFirstN(List l, int n) {
    if (n <= 0 || isEmpty(l)) {
        return NIL;
    }
    return konso(head(l), copyFirstN(tail(l), n - 1));
}

/*
 * Fungsi untuk merotasi linked list ke kanan sebanyak k posisi.
 * Rotasi ke kanan artinya elemen-elemen terakhir dipindahkan ke depan.
 * 
 * I.S.  : l terdefinisi, mungkin kosong; k >= 0
 * F.S.  : Mengembalikan list baru yang merupakan hasil rotasi l sebanyak k posisi ke kanan.
 *         List asli l tidak dimodifikasi (fungsional approach).
 *         Jika k lebih besar dari panjang list, gunakan k modulo panjang list.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5] dan k=2, maka hasil [4,5,1,2,3]
 * Jika l adalah [1,2,3,4,5] dan k=0, maka hasil [1,2,3,4,5]
 * Jika l adalah [1,2,3,4,5] dan k=7, maka hasil [4,5,1,2,3] (karena 7 % 5 = 2)
 */

List rotateRight(List l, int k) {
    if (isEmpty(l)) {
        return NIL;
    }

    int len = length(l);
    k = k % len;

    if (k == 0) {
        return copy(l);
    }

    int pivot = len - k;

    List p = l;
    int i;
    for (i = 0; i < pivot; i++) {
        p = tail(p);
    }
    List lFront = copyFirstN(l, pivot);
    return concat(p, lFront);
}
