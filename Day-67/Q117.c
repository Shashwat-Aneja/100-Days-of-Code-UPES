/*
Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.

Sample cases:
[2,7,11,15] and [4,8,10] -> 2 4 7 8 10 11 15
[1,2,7] and [9,10,17] -> 1 2 7 9 10 17
[-10,-2,7] and [-3,-1,7] -> -10 -3 -2 -1 7 7

Input format: m, m sorted integers, n, n sorted integers.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;
    if (scanf("%d", &m) != 1 || m < 0 || m > 100000) return 1;
    int *a = malloc((size_t)(m ? m : 1) * sizeof *a);
    if (!a) return 1;
    for (int i = 0; i < m; ++i)
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }

    if (scanf("%d", &n) != 1 || n < 0 || n > 100000) { free(a); return 1; }
    int *b = malloc((size_t)(n ? n : 1) * sizeof *b);
    if (!b) { free(a); return 1; }
    for (int i = 0; i < n; ++i)
        if (scanf("%d", &b[i]) != 1) { free(a); free(b); return 1; }

    int i = 0, j = 0, first = 1;
    while (i < m || j < n) {
        int value;
        if (j == n || (i < m && a[i] <= b[j])) value = a[i++];
        else value = b[j++];
        printf("%s%d", first ? "" : " ", value);
        first = 0;
    }
    putchar('\n');
    free(a);
    free(b);
    return 0;
}
/* Time: O(m+n). Auxiliary space: O(m+n) for the two input arrays. */
