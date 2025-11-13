/* File: telegram.c */
/* Implementasi fungsi untuk memproses dan menghitung biaya telegram */

#include "boolean.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

/*
 * Fungsi untuk membandingkan apakah sebuah Word sama dengan string tertentu
 * Dua kata dikatakan sama jika panjang dan urutan karakternya identik
 * I.S. K1 dan str terdefinisi
 * F.S. Mengembalikan true jika K1 sama dengan str, false jika tidak
 *
 * Contoh:
 * - K1 = "KOMA", str = "KOMA" -> return true
 * - K1 = "TITIK", str = "KOMA" -> return false
 * - K1 = "", str = "" -> return true
 */
boolean IsKataSama(Word K1, char *str) {
  /* KAMUS LOKAL */
  // TODO: Deklarasikan variabel yang diperlukan
  int len1, len2;
  len1 = K1.Length;
  len2 = strlen(str);
  /* ALGORITMA */
  // TODO: Implementasikan pengecekan kesamaan antara Word dan string
  if (len1 != len2) {
    return false;
  } else {
    for (int i = 0; i < len1; i++) {
      if (K1.TabWord[i] != str[i]) {
        return false;
      }
    }
    return true;
  }
}

/*
 * Fungsi utama untuk memproses telegram
 * Program membaca input telegram, menampilkan hasil konversi,
 * dan menghitung biaya berdasarkan aturan berikut:
 *
 * Aturan penulisan telegram:
 * - Setiap kata dipisahkan oleh satu atau lebih spasi.
 * - Tanda baca dituliskan dalam bentuk kata: "KOMA" dan "TITIK".
 * - Pita karakter diakhiri dengan karakter titik '.'.
 *
 * Aturan biaya telegram:
 * - Perhitungan biaya didasarkan pada jumlah kata yang dikirim (tanda baca
 * tidak dihitung).
 * - Kata reguler (< 10 karakter) → biaya Rp1000
 * - Kata panjang (>= 10 karakter) → biaya Rp1500
 * - Jika jumlah kata (termasuk tanda baca) > 10 → potongan 10%.
 *
 * Output yang harus ditampilkan:
 * - Isi telegram setelah dikonversi ("KOMA" → ',', "TITIK" → '.')
 * - Jumlah kata reguler
 * - Jumlah kata panjang
 * - Total biaya yang harus dibayar
 *
 * Contoh:
 * Input  : SEGERA PULANG KOMA ADIK SAKIT TITIK.
 * Output :
 * SEGERA PULANG, ADIK SAKIT.
 * 4
 * 0
 * 4000
 *
 * Input  : APA KABAR TITIK SAYA SENANG MENERIMA TAWARANNYA KOMA SEGERA KIRIM
 * PROPOSAL KE KANTOR BANDUNG TITIK. Output : APA KABAR. SAYA SENANG MENERIMA
 * TAWARANNYA, SEGERA KIRIM PROPOSAL KE KANTOR BANDUNG. 11
 * 1
 * 11250
 */
void processTelegram() {
  /* KAMUS LOKAL */
  // TODO: Deklarasikan variabel yang dibutuhkan
  int totalCost = 0;
  int countRegular = 0;
  int countLong = 0;
  int countTotal = 0;
  /* ALGORITMA */
  // TODO: Implementasikan langkah-langkah berikut:
  // Hint: Gunakan STARTWORD() untuk memulai pembacaan kata
  STARTWORD();
  boolean firstWord = true;

  while (!EndWord) {
    if (IsKataSama(currentWord, "KOMA")) {
      printf(",");
      firstWord = false;
      countTotal++;

    } else if (IsKataSama(currentWord, "TITIK")) {
      printf(".");
      firstWord = false;
      countTotal++;
    } else {
      if (!firstWord) {
        printf(" ");
      }

      for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
      }
      countTotal++;

      if (currentWord.Length >= 10) {
        countLong++;
      } else {
        countRegular++;
      }

      firstWord = false;
    }
    ADVWORD();
  }

  printf("\n");

  totalCost = countRegular * 1000 + countLong * 1500;
  double finalCost = (double)totalCost;

  if (countTotal > 10) {
    finalCost = 0.9 * totalCost;
  }

  printf("%d\n", countRegular);
  printf("%d\n", countLong);
  printf("%d\n", (int)finalCost);

  // 1. Selama belum EndWord:
  //    - Jika kata adalah "KOMA" → cetak ','
  //    - Jika kata adalah "TITIK" → cetak '.'
  //    - Jika bukan tanda baca → cetak kata (dengan 1 spasi antar kata)
  //      serta tambahkan ke hitungan kata reguler/panjang
  // 2. Hitung total biaya berdasarkan aturan:
  //      totalCost = countRegular*1000 + countLong*1500
  //      Jika countTotal > 10 → beri potongan 10%
  // 3. Cetak hasil akhir sesuai format contoh.
}

// int main() {
//   processTelegram();
//   return 0;
// }
