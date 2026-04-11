#include <stdio.h>
#include "listkontigu.h"

int main() {
	int n, K, max;
	ListKontigu l, lMax;
	CreateList(&lMax);
	readList(&l);
	scanf("%d", &K);

	for (int i = 0; i < listLength(l) - K + 1; i++) {
		max = ELMT(l, i);
		for (int j = i; j < i + K ; j++) {
			if (max <= ELMT(l, j)) {
				max = ELMT(l, j);
			}
		}
		insertLast(&lMax, max);
	}
	printList(lMax);
	printf("\n");
	return 0;
}