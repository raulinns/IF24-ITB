#include <stdio.h>
#include <stdlib.h>
#include "tester.h" // Perintah soal

int main() {
    init(); // Perintah soal
    FILE *data = fopen("input.txt", "r");
    int totalmisi = 0, berhasil = 0, nilai = 0;
    int id, success, value;
    fscanf(data, "%d %d %d", &id, &success, &value);
    
    while (id != -1 || success != 0 || value != 0) {
        if (success == 1) {
            berhasil++;
            nilai += value;
        }
        totalmisi++;
        id++; success++; value++;
        fscanf(data, "%d %d %d", &id, &success, &value);
    }

    printf("Total Misi: %d\n", totalmisi);
    printf("Misi Berhasil: %d\n", berhasil);
    printf("Total Nilai Misi: %d\n", nilai);
    fclose(data);
    return 0;
}