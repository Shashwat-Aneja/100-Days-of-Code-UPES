// Q36: Write a program to find the HCF/GCD of two numbers.
#include <stdio.h>

int main(void) {
    int a, b, x, y, remainder;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    x = a < 0 ? -a : a;
    y = b < 0 ? -b : b;

    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }

    printf("HCF/GCD = %d\n", x);
    return 0;
}
