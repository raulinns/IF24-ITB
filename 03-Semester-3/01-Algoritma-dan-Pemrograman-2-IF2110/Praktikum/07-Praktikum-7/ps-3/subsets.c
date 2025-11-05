#include <stdio.h>

void printSubset(int subset[], int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", subset[i]);
        if (i < length - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

void generateSubsetsRecursive(int nums[], int n, int subset[], int targetLen, int currentLen, int startIndex) {
    if (currentLen == targetLen) {
        // Kita telah menemukan satu subset yang valid, cetak.
        printSubset(subset, targetLen);
        return;
    }

    for (int i = startIndex; i < n; i++) {
        subset[currentLen] = nums[i];
        generateSubsetsRecursive(nums, n, subset, targetLen, currentLen + 1, i + 1);
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int nums[10];
    int subset[10]; 

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int k = 0; k <= n; k++) {
        generateSubsetsRecursive(nums, n, subset, k, 0, 0);
    }

    return 0;
}
