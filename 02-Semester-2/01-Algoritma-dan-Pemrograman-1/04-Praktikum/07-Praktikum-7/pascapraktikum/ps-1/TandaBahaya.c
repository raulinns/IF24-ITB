#include <stdio.h>
#include "listkontigu.h"

int main() {
	ListKontigu l;
	readList(&l);
	boolean syarat1 = FALSE;
	boolean syarat2 = FALSE;


	for (int i = 0; i < lastIdx(l) - 1; i++) {
		syarat1 = FALSE;
		syarat2 = FALSE;

		if (ELMT(l, i) < ELMT(l, i + 2)) syarat1 = TRUE;
		if (ELMT(l, i + 2) < ELMT(l, i + 1)) syarat2 = TRUE;

		if (syarat1 && syarat2) break;
	}

	if (syarat1 && syarat2) printf("Nyalakan\n");
	else printf("Santai\n");

	return 0;
}