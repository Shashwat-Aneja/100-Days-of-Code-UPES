// Q35: Write a program to find all factors of a number.
#include <stdio.h>

int main(void) {
    int n, i;

    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    printf("Factors: ");
    for (i = 1; i <= n; i++) {
        if (n % i == 0) printf("%d ", i);
    }
    printf("\n");

    return 0;
}
