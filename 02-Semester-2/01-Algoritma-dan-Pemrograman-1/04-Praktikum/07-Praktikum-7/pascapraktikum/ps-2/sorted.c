#include <stdio.h>
#include "listkontigu.h"

void sortList(ListKontigu *l) {
    for (int i = 0; i < listLength(*l) - 1; i++) {
        for (int j = 0; j < listLength(*l) - i - 1; j++) {
			if (ELMT(*l, j) > ELMT (*l, j + 1)) {
				int temp = ELMT(*l, j);
				ELMT(*l, j) = ELMT(*l, j + 1);
				ELMT(*l, j + 1) = temp;
            }
        }
    }
}

int main() {
	ListKontigu l, lSorted, lCopy;

	readList(&l);
	copyList(l, &lSorted);
	sortList(&lSorted);

	int n = listLength(l);
	int firstRevIdx;
	int lastRevIdx = lastIdx(l);
	
	if (n == 0 || n == 1) {
		printf("YA\n");
		return 0;
	}
	if (isListEqual(lSorted, l)) {
		printf("YA\n");
		return 0;
	} 
	
	for (int i = 0; i < n - 1; i++) {
		if (ELMT(l, i) > ELMT(l, i + 1)) {
			firstRevIdx = i;
			break;
		}
	}

	while (firstRevIdx < lastRevIdx) {
		copyList(l, &lCopy);

		int j = lastRevIdx;
		for (int k = firstRevIdx; k <= lastRevIdx; k++) {
			ELMT(lCopy, k) = ELMT(l, j--);
		}
		
		if (isListEqual(lCopy, lSorted)) {
			printf("YA\n");
			printf("%d %d\n", firstRevIdx, lastRevIdx);
			return 0;
		} else lastRevIdx--;
	}

	if (isListEqual(lCopy, lSorted)) {
		printf("YA\n");
		printf("%d %d\n", firstRevIdx, lastRevIdx);
		return 0;
	} else {
		printf("TIDAK\n");
	}

	return 0;
}