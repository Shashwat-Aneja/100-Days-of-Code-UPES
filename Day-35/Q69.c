// Q69: Write a program to find the second largest element in an array.
#include <stdio.h>
#include <limits.h>

int main(void) {
    int a[100], n, i, largest = INT_MIN, second = INT_MIN;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 2 || n > 100) return 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        } else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    if (second == INT_MIN) printf("No distinct second largest element.\n");
    else printf("Second largest = %d\n", second);
    return 0;
}
