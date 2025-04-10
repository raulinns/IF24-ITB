#include <stdio.h>
#include "arrayutils.h"

int main() {
    int tempArr[] = {4, 2, 3, 1, 5, 6, 7, 8, 9, 10};
    int n = sizeof(tempArr) / sizeof(tempArr[0]);
    for (int i = 0; i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    int min = findMin(tempArr, n);
    int max = findMax(tempArr, n);
    int median = findMedian(tempArr, n);
    int mode = findMode(tempArr, n);

    printf("\nMin: %d\n", min);
    printf("Max: %d\n", max);
    printf("Mode: %d\n", mode);
    printf("Average: %f\n", calculateAverage(tempArr, n));
    printf("Index of 5: %d\n", find(tempArr, n, 5));
    printf("Median: %d\n", median);

    reverseArray(tempArr, n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    return 0;
}   