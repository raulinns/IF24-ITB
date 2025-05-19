#include <stdio.h>
#include "matrix.h"

int main() {
	int nRow, nCol, greater;
	Matrix m, lRow, lCol;
	scanf("%d %d", &nRow, &nCol);
	readMatrix(&m, nRow, nCol);
	int minBaris[nRow];
	int maxKolom[nCol];

	for (int i = 0; i < nRow; i++) {
		minBaris[i] = ELMT(m, i, 0);
		for (int j = 1; j < nCol; j++) {
			if (ELMT(m, i, j) < minBaris[i]) {
				minBaris[i] = ELMT(m, i, j);
			}
		}
 	}

	for (int j = 0; j < nCol; j++) {
		maxKolom[j] = ELMT(m, 0, j);
		for (int i = 1; i < nRow; i++) {
			if (ELMT(m, i, j) > maxKolom[j]) {
				maxKolom[j] = ELMT(m, i, j);
			}
		}
 	}

	int count = 0;
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			if ((ELMT(m, i, j) == minBaris[i]) && (ELMT(m, i, j) == maxKolom[j])) {
				printf("(%d,%d,%d)\n", i, j, ELMT(m, i, j));
				count++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}