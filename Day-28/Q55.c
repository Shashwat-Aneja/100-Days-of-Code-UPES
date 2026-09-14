// Q55: Write a program to print all prime numbers from 1 to n.
#include <stdio.h>

int isPrime(int n) {
    int i;
    if (n < 2) return 0;
    for (i = 2; i <= n / i; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main(void) {
    int n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Prime numbers: ");
    for (i = 2; i <= n; i++)
        if (isPrime(i)) printf("%d ", i);
    printf("\n");
    return 0;
}
