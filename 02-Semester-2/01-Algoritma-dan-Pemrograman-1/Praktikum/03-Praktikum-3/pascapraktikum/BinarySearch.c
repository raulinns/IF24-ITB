// Soal Nomor 4

#include <stdio.h>

int BinarySearch(int arr[], int left, int right, int target);

int main() {
    int N, Q;
    scanf("%d", &N);
    int angka[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &angka[i]);
    }
    scanf("%d", &Q);
    int target[Q], founded[Q];

    for (int i = 0; i < Q; i++) {
        scanf("%d", &target[i]);
    }
    for(int i = 0; i < Q; i++) {
        founded[i] = BinarySearch(angka, 0, N - 1, target[i]);
    }
    printf("[");
    for (int i = 0; i < Q; i++) {
        printf("%d", founded[i]);
        if (i != Q - 1) {
            printf(", ", founded[i]);
        }
    }
    printf("]\n");
    return 0;
}

int BinarySearch(int arr[], int left, int right, int target) { // Mencari angka target pada tengah-tengah array, mengurangi array sebanyak separuhnya secara rekursif sampai menemukan target
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}