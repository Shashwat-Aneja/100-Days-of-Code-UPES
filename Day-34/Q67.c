// Q67: Write a program to insert an element at a given position in an array.
#include <stdio.h>

int main(void) {
    int a[101], n, value, position, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 0 || n >= 100) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter position (1-%d): ", n + 1);
    scanf("%d", &position);
    printf("Enter element: ");
    scanf("%d", &value);

    if (position < 1 || position > n + 1) {
        printf("Invalid position.\n");
        return 0;
    }
    for (i = n; i >= position; i--) a[i] = a[i - 1];
    a[position - 1] = value;
    n++;

    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
