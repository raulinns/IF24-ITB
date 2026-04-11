#include "graph.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    Graph g; AdrNode pn;
    int tempId;
    scanf("%d", &tempId);
    g = NewGraph(tempId);
    for (int i = 1; i < m; i++) {
        scanf("%d", &tempId);
        insertNode(&g, tempId, &pn);
    }

    for (int i = 0; i < n; i++) {
        int tempPrec, tempSucc;
        scanf("%d %d", &tempPrec, &tempSucc);
        insertEdge(&g, tempPrec, tempSucc);
    }

    AdrNode p = g.first;

    while (p != NULL) {
        printf("%d %d\n", p->id, p->nPred);
        p = p->next;
    }
    return 0;
}
