// Q33: Write a program to check whether a number is an Armstrong number.
#include <stdio.h>

int power(int base, int exponent) {
    int result = 1;
    while (exponent--) result *= base;
    return result;
}

int main(void) {
    int n, original, digits = 0, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Armstrong numbers are non-negative.\n");
        return 0;
    }

    original = n;
    if (n == 0) digits = 1;
    while (n > 0) {
        digits++;
        n /= 10;
    }

    n = original;
    do {
        digit = n % 10;
        sum += power(digit, digits);
        n /= 10;
    } while (n > 0);

    if (sum == original) printf("Armstrong number.\n");
    else printf("Not an Armstrong number.\n");

    return 0;
}
