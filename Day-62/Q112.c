// Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.

/*
Sample Test Cases:

Input 1:
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output 1:
6

Explanation:
The maximum-sum subarray is [4, -1, 2, 1], whose sum is 6.

Input 2:
arr = [-8, -3, -6, -2, -5, -4]
Output 2:
-2

Input 3:
arr = [1, 2, 3, 4]
Output 3:
10
*/

#include <stdio.h>

int main(void) {
    int n;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid array input.\n");
            return 1;
        }
    }

    // Kadane's algorithm: allow a new subarray to start at each element.
    long long currentSum = arr[0];
    long long maxSum = arr[0];

    for (int i = 1; i < n; i++) {
        if (currentSum + arr[i] < arr[i]) {
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    printf("%lld\n", maxSum);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for the input array; Kadane's algorithm itself uses O(1) extra space.
*/
