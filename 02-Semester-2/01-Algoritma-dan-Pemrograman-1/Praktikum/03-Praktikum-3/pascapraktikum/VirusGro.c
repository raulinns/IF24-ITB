#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]); // Gunakan %lld untuk long long
    }
    long long max_k = 0;
    for (int akhir = 1; akhir <= n; akhir++) { // Iterasi kemungkinan titik persebaran akhir
        for (int d = 1; d <= k; d++) { // Iterasi kemungkinan jumlah titik persebaran awal
            long long temp[n + 1];
            for (int i = 1; i <= n; i++) { // Salin nilai ke array agar tidak melakukan modifikasi pada array asli
                temp[i] = a[i];
            }
            
            temp[akhir] = -999999; // Tandai rumah akhir agar tidak terpilih
            long long sum_selected = 0;
            
            for (int awal = 0; awal < d; awal++) { // Iterasi kemungkinan titik awal persebaran dengan nilai k terbesar
                long long max_val = -999999;
                int max_idx = -1;
                
                for (int i = 1; i <= n; i++) { // Cari rumah dengan nilai terbesar yang belum terpilih
                    if (temp[i] > max_val) {
                        max_val = temp[i];
                        max_idx = i;
                    }
                }
                sum_selected += max_val;
                temp[max_idx] = -999999;
            }
            long long eff_k = sum_selected + a[akhir];
            if (eff_k > max_k) {
                max_k = eff_k;
            }
        }
    }
    printf("%lld\n", max_k);
    return 0;
}