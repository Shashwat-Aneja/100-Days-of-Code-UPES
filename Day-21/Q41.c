// Q41: Write a program to swap the first and last digit of a number.
#include <stdio.h>

int main(void) {
    int n, original, last, first, divisor = 1, middle, result;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 0) n = -n;
    original = n;

    if (n < 10) {
        printf("After swapping: %d\n", n);
        return 0;
    }

    last = n % 10;
    while (n >= 10) {
        divisor *= 10;
        n /= 10;
    }
    first = n;
    middle = original % divisor;
    middle /= 10;
    result = last * divisor + middle * 10 + first;

    printf("After swapping: %d\n", result);
    return 0;
}
