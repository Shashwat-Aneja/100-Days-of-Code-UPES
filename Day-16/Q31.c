// Q31: Write a program to take a number as input and print its equivalent binary representation.
#include <stdio.h>

int main(void) {
    int n, binary[32], i = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 0;
    }

    if (n == 0) {
        printf("Binary: 0\n");
        return 0;
    }

    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    printf("Binary: ");
    while (i > 0) {
        printf("%d", binary[--i]);
    }
    printf("\n");

    return 0;
}
