#include "graph.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

Graph searchCommonNeighbours(Graph *g, int A, int B) {
    AdrNode pNode = searchNode(*g, A);
    AdrAdjNode pAdjNode = pNode->trail;
    Graph cn = NewGraph(A);

    while (pAdjNode != NULL) {
        int val = pAdjNode->succId;
        if ((searchEdge(*g, A, val) != NULL) && (searchEdge(*g, B, val))) {
            AdrNode pn;
            insertNode(&cn, val, &pn);
        }
        pAdjNode = pAdjNode->next;
    }
    return cn;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    Graph g; AdrNode pn;
    g = NewGraph(0);
    for (int i = 0; i < m; i++) {
        insertNode(&g, i + 1, &pn);
        AdrNode bool1  = searchNode(g, (i+1));
        // if (bool1 != NULL) {
        //     printf("1, Node: %d\n", (i + 1));
        // } else {
        //     printf("0, Node: %d\n", (i+1));
        // }
    }
    

    for (int i = 0; i < n; i++) {
        int tempPrec, tempSucc;
        scanf("%d %d", &tempPrec, &tempSucc);
        insertEdge(&g, tempPrec, tempSucc);
        AdrAdjNode bool1  = searchEdge(g, tempPrec, tempSucc);
        // if (bool1 != NULL) {
        //     printf("1, Node: %d %d\n", tempPrec, tempSucc);
        // } else {
        //     printf("0, Node: %d %d\n", tempPrec, tempSucc);
        // }
    }

    int A, B;
    scanf("%d %d", &A, &B);
    Graph cn = searchCommonNeighbours(&g, A, B);

    AdrNode pCn = cn.first->next;
    if (pCn->id == 0) {
        printf("0\n");
        return 0;
    }

    while (pCn != NULL) {
        printf("%d",pCn->id);
        if (pCn->next != NULL) {
            printf(" ");
        }
        pCn = pCn->next;
    }
    printf("\n");
    return 0;
}