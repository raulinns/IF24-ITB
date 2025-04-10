// Soal Nomor 2
// skor hanya 76, jika anda menemukan kekurangan pada kode ini, silakan kontak saya di id line: aendraa

#include <stdio.h>
#include "arrayutils.h"

/**
 * @brief Mengurutkan array dalam urutan menaik.
 * @funfact, array pada sebuah parameter sudah di pass berupa pointer ke elemen pertama, sehingga modifikasi pada array akan mengubah nilai aslinya
 * @param arr Array yang akan diurutkan.
 * @param n Jumlah elemen dalam array.
 */
void sort(int arr[], int n) {
    int temp, imax;
    for (int i = n - 1; i >= 0; i--) {
        imax = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[imax]) {
                imax = j;
            }
        }
        temp = arr[imax];
        arr[imax] = arr[i];
        arr[i] = temp;
    }
}

/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 * 
 * @param arr Array yang akan dicari.
 * @param n Jumlah elemen dalam array.
 * @param target Elemen yang dicari.
 * @return Indeks elemen target, atau -1 jika tidak ditemukan.
 */
int find(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Menghitung rata-rata elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Rata-rata elemen.
 */
double calculateAverage(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = sum / n;
    return average;
}

/**
 * @brief Menemukan median dari elemen dalam array (dibulatkan).
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Median dari elemen.
 */
int findMedian(int arr[], int n) {
    int tempArr[n];
    for (int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    sort(tempArr, n);
    int indekstengah = n / 2;
    if (n % 2 == 0) {
        if (tempArr[indekstengah - 1] == tempArr[indekstengah]) {
            return tempArr[indekstengah];
        } else {
            return (((tempArr[indekstengah - 1] + tempArr[indekstengah]) / 2) + 1);
        }
    } else {
        return tempArr[indekstengah];
    }   
}   

/**
 * @brief Menemukan modus dari elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Modus dari elemen, atau elemen pertama jika semua elemen memiliki frekuensi yang sama.
 */
int findMode(int arr[], int n) {
    int max = 0, count, mode = arr[0];
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            mode = arr[i];
        } 
    }
    return mode;
}

/**
 * @brief Menemukan elemen maksimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen maksimum dalam array.
 */
int findMax(int arr[], int n) {
    int tempArr[n];
    for (int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    sort(tempArr, n);
    return tempArr[n - 1];
}

/**
 * @brief Menemukan elemen minimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen minimum dalam array.
 */
int findMin(int arr[], int n) {
    int tempArr[n];
    for (int i = 0; i < n; i++) {
        tempArr[i] = arr[i];
    }
    sort(tempArr, n);
    return tempArr[0];
}

/**
 * @brief Membalikkan elemen dalam array.
 * 
 * @param arr Array yang akan dibalik.
 * @param n Jumlah elemen dalam array.
 */
void reverseArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n/2; i++)  {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}