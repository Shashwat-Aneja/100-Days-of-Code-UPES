// Q39: Write a program to find the product of all odd digits in a number.
#include <stdio.h>

int main(void) {
    int n, digit, product = 1, found = 0;

    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) n = -n;

    do {
        digit = n % 10;
        if (digit % 2 != 0) {
            product *= digit;
            found = 1;
        }
        n /= 10;
    } while (n > 0);

    printf("Product of odd digits = %d\n", found ? product : 0);
    return 0;
}
