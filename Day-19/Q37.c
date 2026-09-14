// Q37: Write a program to find the LCM of two numbers.
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a < 0 ? -a : a;
}

int main(void) {
    int a, b, g;
    long long lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if (a == 0 || b == 0) {
        printf("LCM = 0\n");
        return 0;
    }

    g = gcd(a, b);
    lcm = (long long)(a / g) * b;
    if (lcm < 0) lcm = -lcm;

    printf("LCM = %lld\n", lcm);
    return 0;
}
