#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

int main() {
    Matrix M1, M2;
    ReadMatrix(&M1);
    // ReadMatrix(&M2);
    // Matrix *M3 = AddMatrix(M1, M2);
    // Matrix *M4 = SubtractMatrix(M1, M2);
    // Matrix M5 = MultiplyScalar(M1, 2.0);
    Matrix M6 = GetTranspose(M1);
    // Matrix *M7 = MultiplyMatrix(M1, M2);
    // PrintMatrix(M1); printf("\n");
    // PrintMatrix(M2); printf("\n");
    // PrintMatrix(*M3); printf("\n");
    // PrintMatrix(*M4); printf("\n");
    // PrintMatrix(M5); printf("\n");
    PrintMatrix(M6); printf("\n");
    printf("%d %d\n", GetRows(M6), GetCols(M6));
    // PrintMatrix(*M7); printf("\n");
}