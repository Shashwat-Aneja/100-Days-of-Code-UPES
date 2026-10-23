/*
Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number

Input format: n, followed by n distinct integers from the range 0 through n, with one value missing.
The source page's sample test cases are not included in the provided text.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000000) return 1;

    long long expected = (long long)n * (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) return 1;
        expected -= value;
    }

    printf("%lld\n", expected);
    return 0;
}
/* Time: O(n). Auxiliary space: O(1). */
