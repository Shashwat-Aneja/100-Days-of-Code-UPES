// Q113: Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.

/*
Sample Test Cases:
Input 1:
arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5

Input 2:
arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7
*/

#include <stdio.h>
#include <stdlib.h>

static int compareIntegers(const void *left, const void *right) {
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

int main(void) {
    int n;

    // Input format: n, followed by n array elements, followed by k.
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof(*arr));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    int k;
    if (scanf("%d", &k) != 1 || k < 1 || k > n) {
        free(arr);
        return 1;
    }

    qsort(arr, (size_t)n, sizeof(*arr), compareIntegers);
    printf("%d\n", arr[k - 1]);

    free(arr);
    return 0;
}

/*
Time Complexity: O(n log n) on average with qsort.
Space Complexity: O(n) for the input array; qsort workspace is implementation-dependent.
*/
