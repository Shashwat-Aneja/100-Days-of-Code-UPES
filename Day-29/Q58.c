// Q58: Write a program to find the maximum and minimum elements of an array.
#include <stdio.h>

int main(void) {
    int a[100], n, i, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    max = min = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    printf("Maximum = %d\nMinimum = %d\n", max, min);
    return 0;
}
