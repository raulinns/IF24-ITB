#include <stdio.h>
#include "listkontigu.h"

boolean checkSorted (ListKontigu l, int i, ListKontigu *lNotSorted) {
	boolean before;
	boolean after;
	if (i == firstIdx(l)) {
		before = TRUE;
		after = (ELMT(l, i + 1) >= ELMT(l, i)) ? TRUE : FALSE;
	} else if (i == lastIdx(l)) {
		after = TRUE;
		before = (ELMT(l, i) >= ELMT(l, i - 1)) ? TRUE : FALSE;
	}
	else {
		after = (ELMT(l, i + 1) >= ELMT(l, i)) ? TRUE : FALSE;
		before = (ELMT(l, i) >= ELMT(l, i - 1)) ? TRUE : FALSE;
	}
	if (!(before && after)) insertLast(lNotSorted, i);
	return before && after;
}


int main() {
	ListKontigu l, lNotSorted;
	CreateList(&lNotSorted);
	readList(&l);
	int n = listLength(l);
	if (n == 1) {
		printf("YA\n");
	} else {
		int notSorted = 0;
		for (int i = 0; i < n; i++) {
			notSorted += !checkSorted(l, i, &lNotSorted);
			if (notSorted > 2) {
				break;
			}
		}
		printList(lNotSorted);
		// if (notSorted == 0) printf("YA\n");
		// else if (notSorted == 2) {
		// 	int val;

		// } else if (notSorted > 2) printf("TIDAK\n");

	}
 
	return 0;
}