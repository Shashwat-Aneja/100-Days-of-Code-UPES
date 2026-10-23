/*
Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.

Input format: m, followed by m sorted integers, then n, followed by n sorted integers.
The source page's sample test cases are not included in the provided text.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;
    if (scanf("%d", &m) != 1 || m < 0 || m > 100000) return 1;
    int *a = m ? malloc((size_t)m * sizeof *a) : NULL;
    if (m && !a) return 1;
    for (int i = 0; i < m; ++i) {
        if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    }

    if (scanf("%d", &n) != 1 || n < 0 || n > 100000) {
        free(a);
        return 1;
    }
    int *b = n ? malloc((size_t)n * sizeof *b) : NULL;
    if (n && !b) { free(a); return 1; }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &b[i]) != 1) { free(a); free(b); return 1; }
    }

    int *merged = (m + n) ? malloc((size_t)(m + n) * sizeof *merged) : NULL;
    if ((m + n) && !merged) { free(a); free(b); return 1; }

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] <= b[j]) merged[k++] = a[i++];
        else merged[k++] = b[j++];
    }
    while (i < m) merged[k++] = a[i++];
    while (j < n) merged[k++] = b[j++];

    for (int p = 0; p < k; ++p) {
        if (p) putchar(' ');
        printf("%d", merged[p]);
    }
    putchar('\n');

    free(a);
    free(b);
    free(merged);
    return 0;
}
/* Time: O(m + n). Auxiliary space: O(m + n) for the merged array. */
