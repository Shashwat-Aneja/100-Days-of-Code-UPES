// Q66: Write a program to insert an element into a sorted array while keeping it sorted.
#include <stdio.h>

int main(void) {
    int a[101], n, value, i, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 0 || n >= 100) return 0;
    printf("Enter sorted array: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter element: ");
    scanf("%d", &value);

    pos = n;
    while (pos > 0 && a[pos - 1] > value) {
        a[pos] = a[pos - 1];
        pos--;
    }
    a[pos] = value;
    n++;

    printf("Array after insertion: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
