// Q59: Write a program to count even and odd elements in an array.
#include <stdio.h>

int main(void) {
    int a[100], n, i, even = 0, odd = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) even++; else odd++;
    }
    printf("Even = %d\nOdd = %d\n", even, odd);
    return 0;
}
