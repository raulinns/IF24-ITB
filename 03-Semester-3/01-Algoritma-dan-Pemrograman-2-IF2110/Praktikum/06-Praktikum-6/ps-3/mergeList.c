#include "listlinier.h"
#include <stdlib.h>

/*
 * Fungsi untuk menggabungkan nilai-nilai di antara dua node bernilai 0
 * menjadi satu node dengan nilai hasil penjumlahan, dan menghapus seluruh node 0.
 *
 * I.S.  l terdefinisi, berisi minimal tiga elemen, dengan ketentuan:
 *      - Elemen pertama dan terakhir bernilai 0
 *      - Tidak ada dua node 0 yang bersebelahan
 *
 * F.S.  Setiap rentang elemen di antara dua 0 dijumlahkan menjadi satu node baru,
 *       dan list hasil tidak mengandung nilai 0 sama sekali.
 *
 * Contoh:
 * Jika l = [0,3,1,0,4,5,2,0], maka setelah mergeList(&l), l menjadi [4,11]
 * Jika l = [0,1,0,3,0,2,2,0], maka setelah mergeList(&l), l menjadi [1,3,4]
 *
 * Hint:
 * - Gunakan variabel untuk menampung hasil penjumlahan sementara
 * - Jangan lupa update FIRST(l) di akhir!
 */
void mergeList(List *l) {
    Address iter, tempDel, tempHead;
    Address newHead, newTail;
    int current_sum;
    ElType val; 

    if (isEmpty(*l)) {
        return;
    }

    newHead = NULL;
    newTail = NULL;

    deleteFirst(l, &val);
    iter = FIRST(*l); 

    while (iter != NULL) {
        tempHead = iter;
        current_sum = 0;

        while (iter != NULL && INFO(iter) != 0) {
            current_sum += INFO(iter);
            iter = NEXT(iter);
        }

        INFO(tempHead) = current_sum;

        if (newHead == NULL) {
            newHead = tempHead; 
        } else {
            NEXT(newTail) = tempHead; 
        }
        newTail = tempHead; 

        tempDel = NEXT(tempHead);
        while (tempDel != iter) {
            Address p_temp_del = tempDel;
            tempDel = NEXT(tempDel);
            free(p_temp_del);
        }

        if (iter != NULL) {
            tempDel = iter;
            iter = NEXT(iter); 
            free(tempDel);
        }
    }

    if (newTail != NULL) {
        NEXT(newTail) = NULL;
    }

    FIRST(*l) = newHead;
    /* KAMUS LOKAL */
    // TODO: Deklarasikan variabel yang diperlukan

    /* ALGORITMA */
    // TODO: Implementasikan algoritma untuk menjumlahkan elemen di antara dua nol
}

