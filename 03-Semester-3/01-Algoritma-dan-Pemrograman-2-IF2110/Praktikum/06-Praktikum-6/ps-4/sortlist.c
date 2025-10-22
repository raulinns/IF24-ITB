#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

void sort(List *l, boolean asc) {
    Address p, q, pCompare;
    boolean boolCompare;
    ElType temp; 

    if (isEmpty(*l) || NEXT(FIRST(*l)) == NULL) {
        return;
    }

    p = FIRST(*l);
    while (p != NULL) {
        
        pCompare = p;

        q = NEXT(p);
        while (q != NULL) {
            
            if (asc) {
                boolCompare = (INFO(q) < INFO(pCompare));
            } else {
                boolCompare = (INFO(q) > INFO(pCompare));
            }

            if (boolCompare) {
                pCompare = q;
            }

            q = NEXT(q);
        }

        if (pCompare != p) {
            temp = INFO(p);
            INFO(p) = INFO(pCompare);
            INFO(pCompare) = temp;
        }

        p = NEXT(p);
    }
}
