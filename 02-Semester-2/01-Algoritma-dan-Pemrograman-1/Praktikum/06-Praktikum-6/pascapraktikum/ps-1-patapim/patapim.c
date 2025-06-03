#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ListDin l;
    int k, min, max;
    int MAX = 100000;
    CreateListDin(&l, MAX);
    readList(&l);

    extremeValues(l, &max, &min);
    
    k = abs(ELMT(l, 0) - min);
    for (int i = 1; i < listLength(l); i++) {
        if (ELMT(l, i) != min) {
            k = gcd(ELMT(l, i) - min, k);
        }
    }
    dealocateList(&l);
    printf("%d\n", k);
    return 0;
}