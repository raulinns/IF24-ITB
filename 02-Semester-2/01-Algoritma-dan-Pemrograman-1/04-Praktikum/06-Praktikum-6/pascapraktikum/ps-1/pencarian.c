#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listdin.h"

int main() {
    int N;
     do {
         scanf("%d", &N);
    } while (N < 2 || N > 100000);
        
    ListDin lAwal, lAkhir, waktuTempuh, lSelisih;
    CreateListDin(&lAwal, 5);
    CreateListDin(&lAkhir, 5);
    CreateListDin(&waktuTempuh, 5);
    CreateListDin(&lSelisih, 5);
    NEFF(lAwal) = 5;
    NEFF(lAkhir) = 5;
    NEFF(waktuTempuh) = 5;
    NEFF(lSelisih) = 5;
    
    for (int i = 0; i < 5; i++) {
        ELMT(waktuTempuh, i) = 0;
        ELMT(lSelisih, i) = 0;
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            scanf("%d %d %d %d %d", &ELMT(lAkhir, 0), &ELMT(lAkhir, 1), &ELMT(lAkhir, 2), &ELMT(lAkhir, 3), &ELMT(lAkhir, 4));
        } else {
            scanf("%d %d %d %d %d", &ELMT(lAwal, 0), &ELMT(lAwal, 1), &ELMT(lAwal, 2), &ELMT(lAwal, 3), &ELMT(lAwal, 4));
            lSelisih = plusMinusList(lAwal, lAkhir, FALSE);
            waktuTempuh = plusMinusList(lSelisih, waktuTempuh, TRUE);
            copyList(lAwal, &lAkhir);
            dealocateList(&lSelisih);
        }
    }

    int min = ELMT(waktuTempuh, 0);
    for (int i = 0; i < NEFF(waktuTempuh); i++) {
        if (ELMT(waktuTempuh, i) < min) {
            min = ELMT(waktuTempuh, i);
        }
    }
    IdxType minIndex = indexOf(waktuTempuh, min);

    if (minIndex == 0) printf("Kebin\n");
    else if (minIndex == 1) printf("Stewart\n");
    else if (minIndex == 2) printf("Pop\n");
    else if (minIndex == 3) printf("Luiy\n");
    else if (minIndex == 4) printf("Toto\n");
    
    dealocateList(&lAwal);
    dealocateList(&lAkhir);
    dealocateList(&waktuTempuh);
    return 0;
}