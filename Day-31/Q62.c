// Q62: Write a program to reverse an array without using extra space.
#include <stdio.h>

int main(void) {
    int a[100], n, i, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
