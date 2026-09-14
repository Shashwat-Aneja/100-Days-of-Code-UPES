// Q68: Write a program to delete an element from an array by position.
#include <stdio.h>

int main(void) {
    int a[100], n, position, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter position to delete (1-%d): ", n);
    scanf("%d", &position);

    if (position < 1 || position > n) {
        printf("Invalid position.\n");
        return 0;
    }
    for (i = position - 1; i < n - 1; i++) a[i] = a[i + 1];
    n--;

    printf("Array after deletion: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
