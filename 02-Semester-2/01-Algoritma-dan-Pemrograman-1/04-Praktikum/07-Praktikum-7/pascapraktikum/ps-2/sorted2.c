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
	ListKontigu l, lSorted;
	CreateList(&lSorted);
	readList(&l);
	copyList(l, &lSorted);
	int n = listLength(l);
	if (n == 1) {
		printf("YA\n");
	} else {
		sortList(&lSorted);
		printList(lSorted);
		
	}
 
	return 0;
}