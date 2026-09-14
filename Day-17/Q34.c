// Q34: Write a program to check whether a number is prime or not.
#include <stdio.h>

int main(void) {
    int n, i, prime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2) prime = 0;
    for (i = 2; i <= n / i && prime; i++) {
        if (n % i == 0) prime = 0;
    }

    if (prime) printf("Prime number.\n");
    else printf("Not a prime number.\n");

    return 0;
}
