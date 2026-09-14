// Q43: Write a program to check whether a number is a strong number.
#include <stdio.h>

int factorial(int n) {
    int result = 1;
    while (n > 1) result *= n--;
    return result;
}

int main(void) {
    int n, original, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Not a strong number.\n");
        return 0;
    }

    original = n;
    do {
        digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    } while (n > 0);

    if (sum == original) printf("Strong number.\n");
    else printf("Not a strong number.\n");

    return 0;
}
