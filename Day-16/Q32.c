// Q32: Write a program to check whether a given number is a palindrome.
#include <stdio.h>

int main(void) {
    int n, original, reversed = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);
    original = n;

    if (n < 0) n = -n;
    while (n > 0) {
        digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    if (reversed == (original < 0 ? -original : original))
        printf("Palindrome number.\n");
    else
        printf("Not a palindrome number.\n");

    return 0;
}
