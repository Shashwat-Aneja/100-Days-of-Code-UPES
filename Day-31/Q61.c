// Q61: Write a program to search for an element using linear search.
#include <stdio.h>

int main(void) {
    int a[100], n, key, i, found = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) { found = i; break; }
    }
    if (found >= 0) printf("Element found at position %d.\n", found + 1);
    else printf("Element not found.\n");
    return 0;
}
