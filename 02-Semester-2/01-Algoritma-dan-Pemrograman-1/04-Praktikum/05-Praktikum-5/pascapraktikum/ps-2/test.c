#include <stdio.h>
#include <math.h>
#include "polynomial.h"

int main() {
    Polynomial p1, p2, p3, p4, result1, result2;
    int coeffArray1[] = {-4, 2, 3, 1};
    int coeffArray2[] = {-3, 2, 1, 0};
    CreatePolynomialFromArray(&p1, coeffArray1, 3);
    CreatePolynomialFromArray(&p2, coeffArray2, 3);
    CreatePolynomialFromArray(&p4, coeffArray1, 3);
    printf("Coefficient 3: %d, Degree: %d\n", GetCoefficient(&p2, 3), GetDegree(&p2));
    ReadPolynomial(&p3);
    PrintPolynomial(&p1);   
    PrintPolynomial(&p2);
    PrintPolynomial(&p3);
    printf("Is Equal = %d\n", IsEqual(&p1, &p4));
    SetCoefficient(&p1, 3, 5);
    PrintPolynomial(&p1);
    AddPolynomials(&p1, &p2, &result1);
    PrintPolynomial(&result1);
    SubtractPolynomials(&p1, &p2, &result2);
    PrintPolynomial(&result2);
    printf("Is Equal = %d\n", IsEqual(&p1, &p2));

}