#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    int a = input % 10;
    int b = (input / 10) % 10;
    int c = (input / 100) % 10;
    input /= 1000;
    printf("%d, %d, %d, %d\n", input, a, b, c);
    return 0;
}