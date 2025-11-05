#include <stdio.h>

int lantai(int n) {
    int way;
    if ((n == 1) || (n == 2)) {
        way = n;
    } else {
        way = lantai(n - 1) + lantai(n - 2);
    }
    return way;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", lantai(n));
    return 0;
}
