#include <stdio.h>

int main(){
    int N, a = 0, b = 1, fib;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("%d", a);
        fib = a + b;
        a = b;
        b = fib;
        
        if (i != N - 1){
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}