// Q70: Write a program to rotate an array to the right by k positions.
#include <stdio.h>

void reverse(int a[], int left, int right) {
    while (left < right) {
        int temp = a[left];
        a[left++] = a[right];
        a[right--] = temp;
    }
}

int main(void) {
    int a[100], n, k, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter k: ");
    scanf("%d", &k);

    k %= n;
    if (k < 0) k += n;
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);

    printf("Rotated array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
