// Soal Nomor 5

#include <stdio.h>

/**
 * Fungsi untuk menghitung kombinasi C(n, k) = n! / (k! * (n - k)!)
 * Note: jangan menggunakan perhitungan faktorial secara langsung, 
 * tetapi sederhanakan bentuk perhitungan kombinasi
 * @param n int
 * @param k int
 * @return Mengembalikan hasil kombinasi C(n, k) dalam bentuk long long
 */
long long kombinasi(int n, int k) {
    long long kombinasi = 1, pembilang = 1, penyebut = 1, bigger, smaller;
    if (k <= (n - k)) {
        bigger = n - k;
        smaller = k;
    } else {
        bigger = k;
        smaller = n - k;
    }
    for (int i = n; i > bigger; i--) {
        pembilang *= i;
    }
    for (int j = 1; j <= smaller; j++) {
        penyebut *= j;
    }
    kombinasi = pembilang / penyebut;
    return kombinasi;
}

/**
 * Fungsi untuk menghitung bilangan Catalan ke-N
 * Catalan(N) = C(2N, N) / (N + 1)
 * @param n int
 * @return Mengembalikan Catalan(n) 
 */
long long catalan(int n) {
    return (kombinasi(2 * n, n) / (n + 1));
}
// Credit to 13524037 - Nicholas Wise Saragih Sumbayak (https://github.com/nicholaswisee/) untuk inspirasinya di fungsi kombinasi