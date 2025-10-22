/* File: problem.c */
/* Implementasi fungsi untuk menyusun ulang linked list berdasarkan posisi ganjil dan genap */

#include "listlinier.h"
#include <stdlib.h>

/*
 * Fungsi untuk menyusun ulang elemen-elemen linked list sehingga
 * semua elemen pada posisi ganjil (1, 3, 5, ...) muncul lebih dulu,
 * diikuti oleh elemen pada posisi genap (2, 4, 6, ...).
 * Urutan relatif antar elemen ganjil maupun antar elemen genap
 * harus tetap dipertahankan.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : Elemen-elemen dalam list l diubah urutannya secara in-place
 *          tanpa alokasi/dealokasi node baru.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah oddEvenLinkedList(&l), l menjadi [1,3,5,2,4]
 * Jika l adalah [10,20,30,40,50,60], maka hasilnya [10,30,50,20,40,60]
 * Jika l adalah [7], maka tetap [7]
 * Jika l adalah [], maka tetap []

*/

void oddEvenLinkedList(List *l) {
    if (*l != NULL) {
       Address oddTail = FIRST(*l);
        Address evenHead = NEXT(oddTail);
        Address evenTail = evenHead;

        while (evenTail != NULL && NEXT(evenTail) != NULL) {
            NEXT(oddTail) = NEXT(evenTail);
            oddTail = NEXT(oddTail);
            NEXT(evenTail) = NEXT(oddTail);
            evenTail = NEXT(evenTail);
        }

        NEXT(oddTail) = evenHead;
    }
}

