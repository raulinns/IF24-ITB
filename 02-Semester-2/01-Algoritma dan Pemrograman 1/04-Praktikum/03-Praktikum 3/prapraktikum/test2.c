#include <stdio.h>

int FPB_duabilangan (int a, int b);
int FPB(int arr[], int n);
int KPK_duabilangan (int a, int b);
int KPK(int arr[], int n);

int main() {
    int N, M;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        if (i != N- 1) {
            scanf("%d ", &arr[i]);
        } else {
            scanf("%d", &arr[i]);
        }
    }
    if (N == 0) {
        M = 0;
    } else if (N == 1) {
        M = arr[0] * arr[0];
    } else {
        M = KPK(arr, N) * FPB(arr, N);
    }
    printf("%d\n", M);
    return 0;
}

int FPB_duabilangan(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int FPB(int arr[], int n) {
    int temp = arr[0], hasil;
    for (int i = 0; i < n; i++)
    {
        hasil = FPB_duabilangan(temp, arr[i]);
        temp = hasil;
    }
    return hasil;
}

int KPK_duabilangan(int a, int b) {
    return a * b / FPB_duabilangan(a, b);
}

int KPK(int arr[], int n) {
    int temp = arr[0], hasil;
    for (int i = 0; i < n; i++)
    {
        hasil = KPK_duabilangan(temp, arr[i]);
        temp = hasil;
    }
    return hasil;
}