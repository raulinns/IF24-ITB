#include <stdio.h>
#include <math.h>
#include "polynomial.h"

int main() {
    Polynomial p1, p2, p3, p4, result1, result2;
    int coeffArray1[] = {-4, 2, 3, 1};
    int coeffArray2[] = {-3, 2, 1, 1};
    CreatePolynomialFromArray(&p1, coeffArray1, sizeof(coeffArray1) / sizeof(coeffArray1[0]));
    CreatePolynomialFromArray(&p2, coeffArray2, sizeof(coeffArray2) / sizeof(coeffArray2[0]));
    
    PrintPolynomial(&p1);
    printf("%d\n", GetDegree(&p1));
    PrintPolynomial(&p2);
    printf("%d\n", GetDegree(&p2));

    AddPolynomials(&p1, &p2, &result1);
    PrintPolynomial(&result1);
    printf("%d\n", GetDegree(&result1));

    SubtractPolynomials(&p1, &p2, &result2);
    PrintPolynomial(&result2);
    printf("%d\n", GetDegree(&result2));

    ReadPolynomial(&p3);
    PrintPolynomial(&p3);

    printf("Evaluate 1: %d\n", Evaluate(&p3, 1));
    printf("Degree: %d\n", GetDegree(&p3));

    SetCoefficient(&p1, 0, 0);
    PrintPolynomial(&p1);
    printf("%d\n", GetDegree(&p1));
}