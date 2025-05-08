#include <stdio.h>
#include "listkontigu.h"

int main() {
	int n;
	ListKontigu l;
	scanf("%d", &n);
	CreateList(&l);
	int j;
	for (int i = 0; i < n; i++) {
		int temp = MARK;
		scanf("%d", &temp);
		j = 0;

		if (isEmpty(l)) insertFirst(&l, temp);
		while (i > j) {
			if (temp >= ELMT(l, j)) {
				j++;
			} else if (temp < ELMT(l, j)) {
				break;
			} 
		}

		if (i != 0) insertAt(&l, temp, j);
		printList(l);
		printf("\n");
	}
	if (n == 0) {
		printList(l);
		printf("\n");
	}
	return 0;
}