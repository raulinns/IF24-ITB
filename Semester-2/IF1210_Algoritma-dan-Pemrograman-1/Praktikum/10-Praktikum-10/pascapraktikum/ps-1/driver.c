#include <stdio.h>
#include "listlinier.h"
#include "moveon.h"

int main() {
    int n, temp, val;
    List l;
    CreateList(&l);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        insertLast(&l, temp);
    }
    scanf("%d", &val);

    removeAll(&l, val);
    return 0;
}