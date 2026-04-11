/* File: main.c */
/* Driver untuk menguji ADT Graph Multilist */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/* =============================================================
   Fungsi Bantuan Visualisasi (Bukan bagian dari ADT)
   Digunakan untuk melihat struktur graf di terminal
   Format: [ID_Simpul | nPred] -> (Tujuan1) -> (Tujuan2) ...
   ============================================================= */
void printGraph(Graph g) {
    printf("\n=== VISUALISASI GRAF ===\n");
    if (g.first == NULL) {
        printf("Graf Kosong.\n");
        return;
    }

    AdrNode P = g.first;
    while (P != NULL) {
        // Cetak Leader Node (Simpul Utama)
        printf("[Node %d | nPred=%d]", ID(P), NPRED(P));

        // Cetak Trailer List (Busur Keluar)
        AdrAdjNode trail = TRAIL(P);
        if (trail == NULL) {
            printf(" -> (tidak punya successor)");
        }
        while (trail != NULL) {
            printf(" -> (%d)", SUCC_ID(trail));
            trail = NEXTSUCC(trail);
        }
        printf("\n");
        
        P = NEXT(P);
    }
    printf("========================\n\n");
}

int main() {
    Graph G;
    AdrNode P;

    /* 1. Inisialisasi Graf dengan simpul awal 1 */
    printf(">> Membuat Graf baru dengan simpul awal 1...\n");
    CreateGraph(1, &G);
    printGraph(G);

    /* 2. Menambahkan Simpul Manual */
    printf(">> Menambahkan Simpul 2 dan 3...\n");
    insertNode(&G, 2, &P);
    insertNode(&G, 3, &P);
    printGraph(G);

    /* 3. Menambahkan Busur (Edge) 
       Skenario: 
       1 -> 2
       1 -> 3
       2 -> 3
    */
    printf(">> Menambahkan Busur: 1->2, 1->3, 2->3...\n");
    insertEdge(&G, 1, 2);
    insertEdge(&G, 1, 3);
    insertEdge(&G, 2, 3);
    printGraph(G);

    /* 4. Menambahkan Busur dengan Node yang belum ada (Auto-create) 
       Skenario: 3 -> 4 (Simpul 4 belum ada, harusnya otomatis dibuat)
    */
    printf(">> Menambahkan Busur 3->4 (Node 4 otomatis dibuat)...\n");
    insertEdge(&G, 3, 4);
    printGraph(G);

    /* 5. Tes Search */
    printf(">> Test Searching...\n");
    if (searchNode(G, 3) != NULL) printf("   - Node 3 ditemukan [OK]\n");
    else printf("   - Node 3 TIDAK ditemukan [FAIL]\n");

    if (searchEdge(G, 1, 2) != NULL) printf("   - Edge 1->2 ditemukan [OK]\n");
    else printf("   - Edge 1->2 TIDAK ditemukan [FAIL]\n");

    if (searchEdge(G, 4, 1) == NULL) printf("   - Edge 4->1 (tidak ada) benar NULL [OK]\n");
    else printf("   - Edge 4->1 ditemukan (seharusnya tidak ada) [FAIL]\n");

    /* 6. Tes Penghapusan (Delete) 
       Kita akan menghapus Node 3.
       Dampak yang diharapkan:
       - Node 3 hilang dari daftar.
       - Busur 1->3 harus hilang dari trail Node 1.
       - Busur 2->3 harus hilang dari trail Node 2.
       - Busur 3->4 hilang, sehingga nPred Node 4 harus berkurang (dari 1 jadi 0).
    */
    printf("\n>> MENGHAPUS NODE 3...\n");
    deleteNode(&G, 3);
    printGraph(G);

    printf("Cek Validasi Penghapusan:\n");
    // Cek apakah 1->3 masih ada?
    if (searchEdge(G, 1, 3) == NULL) printf("   - Edge 1->3 sukses terhapus dari trail Node 1 [OK]\n");
    
    // Cek nPred Node 4 (seharusnya 0 karena 3->4 dihapus)
    AdrNode node4 = searchNode(G, 4);
    if (node4 != NULL && NPRED(node4) == 0) {
        printf("   - nPred Node 4 benar menjadi 0 [OK]\n");
    } else {
        printf("   - nPred Node 4 Salah! [FAIL]\n");
    }

    return 0;
}
