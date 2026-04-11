#include <stdio.h>
#include "listkontigu.h"

int main() {
	int n;
	ListKontigu l;
	do {
		scanf("%d", &n);
	} while (n < 0 || n > CAPACITY - 1);
	
	CreateList(&l);
	int temp, testIndex;
	
	for (int i = 0; i < n; i++) {
		do {
			scanf("%d", &temp);
		} while (temp == MARK);

		if (i == 0) insertFirst(&l, temp);
		else {
			testIndex = IDX_UNDEF;
			for (int j = 0; j < listLength(l); j++) {
				if (ELMT(l, j) > temp) {
					testIndex = j;
					break;
				}
			}

			if (testIndex == IDX_UNDEF) insertLast(&l, temp);
			else {
				insertAt(&l, temp, testIndex);
			}
		}
		printList(l);
		printf("\n");
	}
	return 0;
}