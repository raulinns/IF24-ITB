#include <math.h>
#include <stdio.h>

/**
 * Fungsi untuk mendapatkan panjang angka
 *
 * Hint: gunakan log10
 *
 * kembalikan -1 jika angka == 0
 */
int length(int angka) {
  if (angka == 0)
    return -1;
  else
    return (int)floor(log10((double)angka)) + 1;
}

/**
 * Fungsi untuk mendapatkan digit ke-i dari kanan
 *
 * Contoh:
 * angka = 1234
 *
 * index = 2
 * return -> 2
 *
 * index = 1
 * return -> 3
 *
 * index = 0
 * return -> 4
 *
 * index = 4
 * return -> -1
 *
 * Hint: Gunakan operasi matematika power, module, dan div
 *
 * kembalikan -1 jika index > panjang atau index < 0
 */
int getDigit(int angka, int index) {
  int digit, mod;
  int len = length(angka);
  if (index < 0 || (len != -1 && index >= len)) {
    return -1;
  }

  digit = (angka / (int)pow(10, index)) % 10;
  return digit;
}

/**
 * Fungsi untuk menghapus digit ke-i dari kanan (misal: hapus index ke 2 dari
 * 1234 -> 124)
 *
 *
 * Hint: Gunakan operasi matematika power, module, dan div untuk mendapatkan
 * angka sebelah kiri dan kanan index lalu gabungkan dengan menggunakan
 * perkalian power of 10 dan penjumlahan
 *
 * kembalikan angka yang sama jika index > panjang atau index < 0
 */
int removeDigit(int angka, int index) {
  int len = length(angka);
  if (index < 0 || (len != -1 && index >= len)) {
    return angka;
  } else {
    int tailPow, headPow, left, right;
    tailPow = pow(10, index);
    headPow = pow(10, index + 1);
    left = angka / headPow;
    right = angka % tailPow;

    return left * tailPow + right;
  }
}

/**
 * Fungsi rekursif untuk mencari semua kombinasi angka
 *
 * Hint:
 * - gunakan loop untuk melakukan iterasi ke seluruh digit di angka
 * - gunakan digit yang dipilih (dalam loop diatas) sebagai new current
 *   - current = 1, digit = 2 -> new current = 12
 * - hilangkan digit yang dipilih (dalam loop diatas) sebagai new angka
 *   - angka = 1234, digit yang dipilih = 2 -> new angka = 134
 * - panggil kembali fungsi rekursif
 */
void cariKombinasi(int angka, int current, int panjangAwal) {
  int len = length(angka);
  if (length(current) == panjangAwal) {
    printf("%d\n", current);
  } else {
    for (int i = 0; i < len; i++) {
      int digit = getDigit(angka, i);
      int newCurrent = (current * 10) + digit;
      int newAngka = removeDigit(angka, i);

      cariKombinasi(newAngka, newCurrent, panjangAwal);
    }
  }
}

/**
 * Fungsi untuk menginisialisasi pemanggilan cariKombinasi
 */
void findPassword(int angka) {
  int len = length(angka);
  cariKombinasi(angka, 0, len);
}
