#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ListDin l;
    int n, k, selisih;
    scanf("%d", &n);
    CreateListDin(&l, n);
    NEFF(l) = n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ELMT(l, i));
    }
    k = abs(ELMT(l, 1) - ELMT(l, 0));
    for (int i = 2; i < n; i++) {
        for (int j = i; j < n; j++) {
            selisih = abs(ELMT(l, j) - ELMT(l, j-i));
            k = gcd(selisih, k);
        }
    }
    dealocateList(&l);
    printf("%d\n", k);
    return 0;
}