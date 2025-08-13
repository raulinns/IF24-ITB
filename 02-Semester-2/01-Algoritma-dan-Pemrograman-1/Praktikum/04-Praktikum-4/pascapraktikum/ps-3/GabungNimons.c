#include <stdio.h>
#include "tester.h" // Comment this when developing in local

int main () {
    init(); // Comment this when developing in local
    int idA, idB, jumlahpisangA, jumlahpisangB;
    FILE *inputA = fopen("file_a.txt", "r");
    FILE *inputB = fopen("file_b.txt", "r");
    fscanf(inputA, "%d %d", &idA, &jumlahpisangA);
    fscanf(inputB, "%d %d", &idB, &jumlahpisangB);

    while (idA != -1 && idB != -1 && jumlahpisangA != 99 && jumlahpisangB != 99) {
        if (idA < idB) {
            printf("%d %d\n", idA, jumlahpisangA);
            fscanf(inputA, "%d %d", &idA, &jumlahpisangA);
        } else if (idA > idB) {
            printf("%d %d\n", idB, jumlahpisangB);
            fscanf(inputB, "%d %d", &idB, &jumlahpisangB);
        }
    }    
    while (idA != -1 && jumlahpisangA != 99) {
        printf("%d %d\n", idA, jumlahpisangA);
        fscanf(inputA, "%d %d", &idA, &jumlahpisangA);
    }
    while (idB != -1 && jumlahpisangB != 99) {
        printf("%d %d\n", idB, jumlahpisangB);
        fscanf(inputB, "%d %d", &idB, &jumlahpisangB);
    }
    fclose(inputA);
    fclose(inputB);   
    return 0;
}