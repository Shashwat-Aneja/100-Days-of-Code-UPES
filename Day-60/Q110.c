// Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

/*
Sample Test Cases:

Input 1:
arr = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output 1:
3 3 4 5 5 5 6

Explanation:
The maximum of each consecutive window of size 3 is:
[1, 2, 3] -> 3
[2, 3, 1] -> 3
[3, 1, 4] -> 4
[1, 4, 5] -> 5
[4, 5, 2] -> 5
[5, 2, 3] -> 5
[2, 3, 6] -> 6

Input 2:
arr = [5, 1, 3, 4, 2], k = 1
Output 2:
5 1 3 4 2
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
    int deque[n];

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

    /*
       The deque stores array indices. Values at those indices
       remain in decreasing order, so the front always points
       to the maximum element in the current window.
    */
    int front = 0;
    int back = -1;

    for (int i = 0; i < n; i++) {
        // Remove indices that are outside the current window.
        while (front <= back && deque[front] <= i - k) {
            front++;
        }

        // Remove smaller or equal values from the back.
        while (front <= back && arr[deque[back]] <= arr[i]) {
            back--;
        }

        deque[++back] = i;

        // Once the first full window is formed, print its maximum.
        if (i >= k - 1) {
            if (i > k - 1) {
                printf(" ");
            }
            printf("%d", arr[deque[front]]);
        }
    }

    printf("\n");
    return 0;
}

/*
Time Complexity: O(n), because each index enters and leaves the deque at most once.
Space Complexity: O(n), for the input array and deque.
*/
