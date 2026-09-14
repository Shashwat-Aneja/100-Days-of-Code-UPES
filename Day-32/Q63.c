// Q63: Write a program to merge two arrays into one array.
#include <stdio.h>

int main(void) {
    int a[100], b[100], merged[200], n, m, i;
    printf("Enter size of first array: ");
    scanf("%d", &n);
    printf("Enter first array: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter size of second array: ");
    scanf("%d", &m);
    printf("Enter second array: ");
    for (i = 0; i < m; i++) scanf("%d", &b[i]);

    for (i = 0; i < n; i++) merged[i] = a[i];
    for (i = 0; i < m; i++) merged[n + i] = b[i];

    printf("Merged array: ");
    for (i = 0; i < n + m; i++) printf("%d ", merged[i]);
    printf("\n");
    return 0;
}
