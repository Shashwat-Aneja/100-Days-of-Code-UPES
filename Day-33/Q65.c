// Q65: Write a program to search for an element using binary search in a sorted array.
#include <stdio.h>

int main(void) {
    int a[100], n, key, low, high, mid, found = -1, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    printf("Enter sorted array: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0; high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == key) { found = mid; break; }
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (found >= 0) printf("Element found at position %d.\n", found + 1);
    else printf("Element not found.\n");
    return 0;
}
