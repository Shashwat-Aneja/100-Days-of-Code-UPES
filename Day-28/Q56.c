// Q56: Read and print a one-dimensional array.
#include <stdio.h>

int main(void) {
    int a[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
