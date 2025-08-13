#include <stdio.h>
#include "matrix.h"

int sumMatrix(Matrix m) {
	int sum = 0;
	for (int i = 0; i < ROW_EFF(m); i++) {
		for (int j = 0; j < COL_EFF(m); j++) {
			sum += ELMT(m, i, j);
		}
	}
	return sum;
}
int main() {
	int n, sum, failedCount = 0, sumCol, sumRow;
	Matrix m, mCol, mRow;
	scanf("%d", &n);
	readMatrix(&m, n, n);
	createMatrix(n, 1, &mCol);
	createMatrix(1, n, &mRow);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ELMT(mCol, j, 0) =  ELMT(m, j, i);
			ELMT(mRow, 0, j) = ELMT(m, i, j);
			sumCol = sumMatrix(mCol);
			sumRow = sumMatrix(mRow);
			if (sumCol == n && sumRow == 1) {
				printf("%d\n", i);
				return 0;
			} else {
				failedCount++;
			}
		}
	}
	printf("-1\n");
	return 0;
}