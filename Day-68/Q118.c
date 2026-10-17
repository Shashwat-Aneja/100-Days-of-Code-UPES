/*
Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number.

Sample cases:
[0,3,2,4] -> 1
[1,2,3] -> 0
[0,4,3,1,5] -> 2

Input format: n, followed by n distinct integers from the range 0..n with one missing.
*/
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000000) return 1;
    long long expected = (long long)n * (n + 1) / 2;
    long long actual = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) return 1;
        actual += value;
    }
    printf("%lld\n", expected - actual);
    return 0;
}
/* Time: O(n). Auxiliary space: O(1). */
