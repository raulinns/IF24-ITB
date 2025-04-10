#include <stdio.h>

int main(){
    int A, B, temp, smaller, bigger;
   
    do {
        scanf("%d", &A);
        scanf("%d", &B);
    } while (!((1 <= A <= 1000000000) && (1 <= B <= 1000000000)));

    if (A < B) { // Mencari bilangan yang lebih besar
        smaller = A; 
        bigger = B;
    } else {
        smaller = B;
        bigger = A;
    }
    for (int i = 1; i <= smaller; i++) {
        if ((A % i == 0) && (B % i == 0)) { // Mencari faktor yang sama
            temp = i; // Mencari variabel terbesar melalui for loop dan disimpan di variabel temp
        }
    }
    printf("%d", temp);
    printf("\n");
    return 0;
}