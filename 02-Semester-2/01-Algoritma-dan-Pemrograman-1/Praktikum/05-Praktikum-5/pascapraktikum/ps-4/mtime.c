#include <stdio.h>
#include "boolean.h"
#include "time.h"

int main() {
    int N;
    TIME T1, T2, TAwal, TAkhir, TMin, TMax;
    scanf("%d", &N);
    CreateTime(&TMin, 23, 59, 59);
    CreateTime(&TMax, 0, 0, 0);
    for (int i = 1; i <= N; i++) {
        
        printf("[%d]\n", i);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if (TLT(T1, T2) == true) {
            TAwal = T1; TAkhir = T2;
        } else {
            TAwal = T2; TAkhir = T1;
        }
        long detikAw = TIMEToDetik(TAwal);
        long detikAkh = TIMEToDetik(TAkhir);
        long durasi = detikAkh - detikAw;

        printf("%ld\n", durasi);
        if (TLT(TAwal, TMin) == true) {
            TMin = TAwal;
        }
        if (TGT(TAkhir, TMax) == true) {
            TMax = TAkhir;
        }
    }
    TulisTIME(TMin);
    printf("\n");
    TulisTIME(TMax);
    printf("\n");
}