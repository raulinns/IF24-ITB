// Soal nomor 1

#include <stdio.h>

int main() {
    int jmlhelemen, jmlhrotator;
    scanf("%d", &jmlhelemen);
    scanf("%d", &jmlhrotator);
    int barisan[jmlhelemen], rotasi[jmlhrotator];
    
    for (int i = 0; i < jmlhelemen; i++) {
        if (i == jmlhelemen - 1) {
            scanf("%d", &barisan[i]);
        } else {
        scanf("%d ", &barisan[i]);
        }
    }

    for (int i = 0; i < jmlhrotator; i++) {
        if (i == jmlhrotator - 1) {
            scanf("%d", &rotasi[i]);
        } else {
            scanf("%d ", &rotasi[i]);
        }
    }
    for (int i = 0; i < jmlhrotator; i++) {
        int barisanbaru[jmlhelemen];
        int rotator = rotasi[i];
        for (int j = 0; j < jmlhelemen; j++) {
            barisanbaru[(j + rotator) % jmlhelemen] = barisan[j];
        }
        printf("[");
        for (int k = 0; k < jmlhelemen; k++) {
            if (k == jmlhelemen- 1) {
                printf("%d]\n", barisanbaru[k]);
            } else {
                printf("%d, ", barisanbaru[k]);
            }
        }
    }
    return 0;
}