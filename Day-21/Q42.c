// Q42: Write a program to check whether a number is a perfect number.
#include <stdio.h>

int main(void) {
    int n, i, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Not a perfect number.\n");
        return 0;
    }

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) sum += i;
    }

    if (sum == n) printf("Perfect number.\n");
    else printf("Not a perfect number.\n");

    return 0;
}
