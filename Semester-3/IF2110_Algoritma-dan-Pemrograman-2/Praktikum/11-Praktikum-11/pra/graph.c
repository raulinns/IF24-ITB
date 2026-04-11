#include "graph.h"
#include <stdlib.h>

Graph NewGraph(int x) {
/* Menghasilkan Graph dengan satu simpul ber-id x jika alokasi berhasil.
   Menghasilkan Graph kosong jika alokasi gagal. */
    Graph g;
    g.first = newGraphNode(x);
    return g;
}

void CreateGraph(int x, Graph *g) {
/* I.S. Sembarang
   F.S. Terbentuk Graph dengan satu simpul dengan Id = x */
    *g = NewGraph(x);
}

AdrNode newGraphNode(int x) {
/* Mengembalikan address hasil alokasi simpul x.
   Jika alokasi berhasil, maka address tidak NULL, misalnya menghasilkan p,
   maka p↑.id = x, p↑.nPred = 0, p↑.trail = NULL, dan p↑.next = NULL.
   Jika alokasi gagal, mengembalikan NULL. */
    AdrNode p = (AdrNode) malloc(sizeof(GraphNode));

    if (p != NULL) {
        ID(p) = x;
        NPRED(p) = 0;
        TRAIL(p) = NULL;
        NEXT(p) = NULL;
    }

    return p;
}

void deallocGraphNode(AdrNode p) {
/* I.S. p terdefinisi
   F.S. p terdealokasi */
    free(p);
}

AdrAdjNode newAdjNode(int succId) {
/* Mengembalikan address hasil alokasi adjacency.
   Jika alokasi berhasil, maka address tidak NULL, misalnya menghasilkan pt,
   maka pt↑.succId = succId dan pt↑.next = NULL.
   Jika alokasi gagal, mengembalikan NULL. */
    AdrAdjNode p = (AdrAdjNode) malloc(sizeof(GraphAdjNode));

    if (p != NULL) {
        p->succId = succId;
        p->next = NULL;
    }
    return p;
}

void deallocAdjNode(AdrAdjNode p) {
/* I.S. p terdefinisi
   F.S. p terdealokasi */
    free(p);
}

AdrNode searchNode(Graph g, int x) {
/* Mengembalikan address simpul dengan id = x jika sudah ada pada graph g,
   NULL jika belum */
    AdrNode p = g.first;
    while (p != NULL) {
        if (p->id == x) {
            return p;
        } else {
            p = p->next;
        }
    }
    return NULL;
}

AdrAdjNode searchEdge(Graph g, int prec, int succ) {
/* Mengembalikan address adjacency yang menyimpan info edge <prec, succ>
   jika sudah ada pada graph g, NULL jika belum */
    AdrNode pLead = searchNode(g, prec);
    if (pLead == NULL) {
        return NULL;
    }
    AdrAdjNode pTrail = pLead->trail;

    while (pTrail != NULL) {
        if (pTrail->succId == succ) {
            return pTrail;
        }

        pTrail = pTrail->next;
    }
    return NULL;
}

void insertNode(Graph *g, int x, AdrNode *pn) {
/* Menambahkan simpul x ke dalam graph g, jika alokasi x berhasil.
   I.S. g terdefinisi, x terdefinisi dan belum ada pada g.
   F.S. Jika alokasi berhasil, x menjadi elemen terakhir g, pn berisi address
   simpul x. Jika alokasi gagal, g tetap, pn berisi NULL. */
    if (searchNode(*g, x) != NULL) {
        *pn = NULL;
        return;
    }

    *pn = newGraphNode(x);
    if (*pn == NULL) {
        return;
    }

    if (g->first == NULL) {
        g->first = *pn;
    } else {
        AdrNode p = g->first;
        while (p->next != NULL) {
            p = p->next;       
        }
        p->next = *pn; 
    }
}

void insertEdge(Graph *g, int prec, int succ) {
/* Menambahkan edge dari prec menuju succ ke dalam g.
   I.S. g, prec, succ terdefinisi.
   F.S. Jika belum ada edge <prec, succ> di g, maka tambahkan edge <prec, succ>
   ke g (NPRED(succ) otomatis bertambah). Jika simpul prec/succ belum ada pada g,
   tambahkan simpul tersebut dahulu. Jika sudah ada edge <prec, succ> di g,
   maka g tetap. */
    if (searchEdge(*g, prec, succ) != NULL) {
        return;
    }
    
    AdrNode ptrNodePrec = searchNode(*g, prec);
    if (ptrNodePrec == NULL) {
        insertNode(g, prec, &ptrNodePrec);
    }

    AdrNode ptrNodeSucc = searchNode(*g, succ);
    if (ptrNodeSucc == NULL) {
        insertNode(g, succ, &ptrNodeSucc);
    }
    
    
    AdrAdjNode succNode = newAdjNode(succ);
    if (succNode == NULL) {
        return;
    }
    
    if (ptrNodePrec->trail == NULL) {
        ptrNodePrec->trail = succNode;
    } else {
        AdrAdjNode pPrec = ptrNodePrec->trail;

        while (pPrec->next != NULL) {
            pPrec = pPrec->next;
        }
        pPrec->next = succNode;
    }
    ptrNodeSucc->nPred += 1;
}

void deleteNode(Graph *g, int x) {
    AdrNode p = g->first;
    AdrNode prevP = NULL;
    AdrNode targetNode = NULL;

    while (p != NULL) {
        if (p->id == x) {
            targetNode = p;
            break;
        }
        prevP = p;
        p = p->next;
    }

    if (targetNode == NULL) {
        return;
    }

    p = g->first;
    while (p != NULL) {
        if (p != targetNode) {
            AdrAdjNode t = p->trail;
            AdrAdjNode prevT = NULL;
            
            while (t != NULL) {
                if (t->succId == x) {
                    if (prevT == NULL) {
                        p->trail = t->next;
                    } else {
                        prevT->next = t->next;
                    }

                    AdrAdjNode temp = t;
                    t = t->next;
                    deallocAdjNode(temp);
                } else {
                    prevT = t;
                    t = t->next;
                }
            }
        }
        p = p->next;
    }

    AdrAdjNode trail = TRAIL(targetNode);
    while (trail != NULL) {
        int succId = SUCC_ID(trail);
        AdrNode destNode = searchNode(*g, succId);
        if (destNode != NULL) {
            NPRED(destNode)--;
        }
        
        AdrAdjNode temp = trail;
        trail = NEXTSUCC(trail);
        deallocAdjNode(temp);
    }

    if (prevP == NULL) {
        g->first = NEXT(targetNode);
    } else {
        NEXT(prevP) = NEXT(targetNode);
    }

    deallocGraphNode(targetNode);

}
/* Menghapus simpul x dari g.
   I.S. g terdefinisi, x terdefinisi dan ada pada g, jumlah simpul pada g
   lebih dari 1.
   F.S. Simpul x dan semua edge yang terhubung ke x dihapus dari g. */
