// Soal Nomor 3

#include <stdio.h>

int FPB_duabilangan(int a, int b);
int FPB(int arr[], int n);
int KPK_duabilangan(int a, int b);
int KPK(int arr[], int n);

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long M = (long long)KPK(arr, N) * FPB(arr, N);
    long long M_max = M;
    
    for (int i = 0; i < N; i++) {
        int arr_baru[N-1];
        for (int j = 0, k = 0; j < N; j++) {
            if (j != i) {
                arr_baru[k++] = arr[j];
            }
        }
        long long M_baru = (long long)KPK(arr_baru, N-1) * FPB(arr_baru, N-1);
        if (M_baru > M_max) {
            M_max = M_baru;
        }
    }
    
    printf("%lld\n", M_max);
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
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return arr[0];
    } else {
        int hasil = arr[0];
        for (int i = 1; i < n; i++) {
            hasil = FPB_duabilangan(hasil, arr[i]);
        }
        return hasil;
    }
}

int KPK_duabilangan(int a, int b) {
    return a / FPB_duabilangan(a, b) * b;
}

int KPK(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return arr[0];
    } else {
        int hasil = arr[0];
        for (int i = 1; i < n; i++) {
            hasil = KPK_duabilangan(hasil, arr[i]);
        }
        return hasil;
    }
}