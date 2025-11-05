/* File: driver.c */
#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

// Deklarasi ulang variabel eksternal (state)
extern char currentChar;
extern boolean EOP;
extern Word currentWord;
extern boolean EndWord;

// Asumsi MARK didefinisikan di mesinkarakter.h
#define MARK_CHAR '.'

// --- FUNGSI UJI 1: MESIN KARAKTER ---
void testMesinKarakter() {
    int count = 0;
    
    printf("==========================================\n");
    printf("   UJI COBA 1: MESIN KARAKTER (dari pita.txt)\n");
    printf("==========================================\n");

    START();

    if (EOP) {
        printf("Pita kosong (hanya berisi MARK).\n");
    } else {
        printf("Karakter yang dibaca:\n");
        while (!EOP) {
            // Kita tidak perlu mencetak MARK di sini karena loop berhenti saat ADV membaca MARK
            printf("  [%d] Char: '%c'\n", count, currentChar);
            ADV(); 
            count++;
        }
    }
    
    printf("\n--- Status Akhir Mesin Karakter ---\n");
    printf("Total karakter non-MARK dibaca: %d\n", count);
    printf("EOP = %s, currentChar = '%c' (MARK)\n", EOP ? "TRUE" : "FALSE", currentChar);
}

// --- FUNGSI UJI 2: MESIN KATA ---
void testMesinKata() {
    int wordCount = 0;
    
    printf("\n==========================================\n");
    printf("   UJI COBA 2: MESIN KATA (dari pita.txt)\n");
    printf("==========================================\n");

    // Catatan: STARTWORD akan memanggil START Mesin Karakter lagi
    STARTWORD(); 

    while (!EndWord) {
        wordCount++;
        
        // Tampilkan currentWord
        printf("Kata ke-%d: ", wordCount);
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf(" (Panjang: %d)\n", currentWord.Length);

        ADVWORD();
    }
    
    printf("\n--- Status Akhir Mesin Kata ---\n");
    printf("Total kata diakuisisi: %d\n", wordCount);
    printf("EndWord = TRUE. Akuisisi selesai.\n");
    printf("Status Mesin Karakter Akhir: currentChar = '%c'\n", currentChar);
}

// --- MAIN DRIVER ---
int main() {
    // Anda harus memastikan file pita.txt ada dan berisi data
    
    // Uji coba 1
    testMesinKarakter();
    
    // Ulangi START Mesin Karakter untuk menguji Mesin Kata
    // (Ini karena testMesinKarakter menutup file pita)
    
    // Uji coba 2
    testMesinKata();
}
