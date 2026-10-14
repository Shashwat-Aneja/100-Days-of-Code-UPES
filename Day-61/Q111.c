// Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

/*
Sample Test Cases:

Input 1:
arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 1:
-1 -1 -7 -15 -15 0

Input 2:
arr = [1, 2, 3, 4, 5], k = 2
Output 2:
0 0 0 0
*/

#include <stdio.h>

int main(void) {
    int n, k;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    int negatives[n];
    int front = 0, back = -1;

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid array input.\n");
            return 1;
        }
    }

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid value of k.\n");
        return 1;
    }

    // Store indices of negative elements in their order of appearance.
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives[++back] = i;
        }
    }

    int nextNegative = 0;
    for (int start = 0; start <= n - k; start++) {
        int end = start + k - 1;

        // Skip negative indices that are left of the current window.
        while (nextNegative <= back && negatives[nextNegative] < start) {
            nextNegative++;
        }

        if (nextNegative <= back && negatives[nextNegative] <= end) {
            printf("%d", arr[negatives[nextNegative]]);
        } else {
            printf("0");
        }

        if (start < n - k) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}

/*
Time Complexity: O(n), because each negative index is processed at most once.
Space Complexity: O(n), for the input array and negative-index list.
*/
