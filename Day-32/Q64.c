// Q64: Write a program to find the digit that occurs most frequently in an integer.
#include <stdio.h>

int main(void) {
    long long n;
    int count[10] = {0}, digit, i, maxDigit = 0;

    printf("Enter an integer: ");
    scanf("%lld", &n);
    if (n < 0) n = -n;

    do {
        digit = (int)(n % 10);
        count[digit]++;
        n /= 10;
    } while (n > 0);

    for (i = 1; i < 10; i++)
        if (count[i] > count[maxDigit]) maxDigit = i;

    printf("Most frequent digit = %d\n", maxDigit);
    return 0;
}
