#include <stdio.h>
#include "listlinier.h"

/* * Deklarasikan prototipe fungsi yang akan diuji.
 * Fungsi ini didefinisikan di 'problem.c'
 */
void oddEvenLinkedList(List *l);

int main() {
    List l;
    int n, i;
    ElType val;

    /* 1. Inisialisasi list kosong */
    CreateList(&l);

    /* 2. Minta input dari pengguna untuk mengisi list */
    printf("Masukkan jumlah elemen list: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Masukkan %d elemen (dipisah spasi atau enter):\n", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &val);
            /* Menggunakan insertLast agar urutan list sesuai input */
            insertLast(&l, val); 
        }
    }

    /* 3. Tampilkan list awal */
    printf("\nList Awal          : ");
    displayList(l);
    printf("\n");

    /* 4. Panggil fungsi yang akan diuji */
    oddEvenLinkedList(&l);

    /* 5. Tampilkan list setelah diubah */
    printf("List Ganjil-Genap  : ");
    displayList(l);
    printf("\n");

    /* * Catatan: Program ini tidak melakukan dealokasi memori 
     * karena 'listlinier.h' tidak menyediakan fungsi destroyList.
     * Untuk program sederhana, memori akan dikembalikan oleh OS.
     */
    return 0;
}
