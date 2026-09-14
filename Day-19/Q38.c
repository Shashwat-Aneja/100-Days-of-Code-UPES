// Q38: Write a program to find the sum of digits of a number.
#include <stdio.h>

int main(void) {
    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) n = -n;

    do {
        sum += n % 10;
        n /= 10;
    } while (n > 0);

    printf("Sum of digits = %d\n", sum);
    return 0;
}
