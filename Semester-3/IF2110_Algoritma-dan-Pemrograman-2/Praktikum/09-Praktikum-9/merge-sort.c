/* File: merge-sort.c */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List merge(List l1, List l2) {
    if (isEmpty(l1)) return l2;
    if (isEmpty(l2)) return l1;

    if (head(l1) <= head(l2)) {
        return konso(head(l1), merge(tail(l1), l2));
    } else {
        return konso(head(l2), merge(l1, tail(l2)));
    }
}

List mergeSort(List l) {
    if (length(l) < 2) {
        return l;
    }

    int len = length(l);
    int mid = len / 2; /* Indeks tengah = floor(L/2) */

    List left = NIL;
    List right = l; 

    for (int i = 0; i < mid; i++) {
        left = konsDot(left, head(right));
        right = tail(right);
    }

    left = mergeSort(left);
    right = mergeSort(right);

    /* --- PROSES MERGE --- */
    List result = merge(left, right);

    /* --- OUTPUT PER STAGE --- */
    /* Menampilkan list setelah setiap stage merging selesai */
    displayList(result);
    printf("\n");

    return result;
}

int main() {
    int n, val, i;
    List l = NIL;

    /* Baca jumlah elemen n (Sesuai format input soal) */
    if (scanf("%d", &n) != 1) return 0;

    /* Baca n bilangan bulat dan masukkan ke list */
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        /* Gunakan konsDot untuk mempertahankan urutan input */
        l = konsDot(l, val);
    }

    /* Jalankan Merge Sort */
    /* Hasil akhir tidak perlu diprint lagi di main karena 
       sudah diprint di dalam fungsi mergeSort (termasuk step terakhir) */
    mergeSort(l);

    return 0;
}
