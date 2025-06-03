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
	int N, M, subSize, X, sumSub;
	Matrix mMain;
	scanf("%d %d %d %d", &N, &M, &subSize, &X);
	readMatrix(&mMain, N, M);

	int count = 0;
	Matrix subMatrix;
	createMatrix(subSize, subSize, &subMatrix);
	for (int row = 0; row <= N - subSize; row++) {
		for (int col = 0; col <= M - subSize; col++) {
			for (int i = 0; i < subSize; i++) {
				for (int j = 0; j < subSize; j++) {
					ELMT(subMatrix, i, j) = ELMT(mMain, row + i, col + j);
				}
			}
			sumSub = sumMatrix(subMatrix);
			if (sumSub <= X) count++;
		}
	}
	printf("%d\n", count);
	return 0;
}