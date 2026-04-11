/* File: driver.c */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* Deklarasi prototype fungsi rotateRight */
/* Pastikan implementasi rotateRight ada di problem.c */
List rotateRight(List l, int k);

/* Fungsi bantuan untuk mempermudah testing: Membuat list [1..n] */
List createList1toN(int n) {
    List l = NIL;
    int i;
    for (i = 1; i <= n; i++) {
        l = konsDot(l, i);
    }
    return l;
}

/* Fungsi untuk menjalankan test case dan mencetak hasil dengan rapi */
void runTest(List l, int k, char* deskripsi) {
    printf("=== Test: %s ===\n", deskripsi);
    printf("List Awal : [ ");
    displayList(l);
    printf("]\n");
    
    printf("Rotasi k  : %d\n", k);
    
    List hasil = rotateRight(l, k);
    
    printf("Hasil     : [ ");
    displayList(hasil);
    printf("]\n");
    printf("----------------------------------------\n");
}

int main() {
    List l1 = NIL;
    List lEmpty = NIL;

    printf("DRIVER UJI COBA ROTATE RIGHT\n");
    printf("========================================\n\n");

    /* Skenario 1: Rotasi Normal */
    /* List: [1, 2, 3, 4, 5], k = 2 -> Ekspektasi: [4, 5, 1, 2, 3] */
    l1 = createList1toN(5);
    runTest(l1, 2, "Normal Rotation (k < length)");

    /* Skenario 2: Rotasi dengan k > panjang list (Uji Modulo) */
    /* List: [1, 2, 3, 4, 5], k = 7 -> 7 % 5 = 2 -> Ekspektasi: [4, 5, 1, 2, 3] */
    runTest(l1, 7, "Modulo Rotation (k > length)");

    /* Skenario 3: Rotasi k = 0 */
    /* List: [1, 2, 3, 4, 5], k = 0 -> Ekspektasi: [1, 2, 3, 4, 5] */
    runTest(l1, 0, "Zero Rotation (k = 0)");

    /* Skenario 4: Rotasi k = panjang list */
    /* List: [1, 2, 3, 4, 5], k = 5 -> Ekspektasi: [1, 2, 3, 4, 5] */
    runTest(l1, 5, "Full Rotation (k = length)");

    /* Skenario 5: List Kosong */
    /* List: [], k = 3 -> Ekspektasi: [] */
    runTest(lEmpty, 3, "Empty List");

    /* Skenario 6: Rotasi 1 elemen */
    /* List: [1, 2, 3, 4, 5], k = 1 -> Ekspektasi: [5, 1, 2, 3, 4] */
    runTest(l1, 1, "Rotate by 1");

    return 0;
}
