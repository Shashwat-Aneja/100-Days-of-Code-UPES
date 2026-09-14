// Q57: Write a program to find the sum of all elements in an array.
#include <stdio.h>

int main(void) {
    int a[100], n, i, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    printf("Enter elements: ");
    for (i = 0; i < n; i++) { scanf("%d", &a[i]); sum += a[i]; }
    printf("Sum = %d\n", sum);
    return 0;
}
