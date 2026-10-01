// Q103: Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.

/*
Follow-up (optional):
Try to solve this in O(n) TC.

Sample Test Cases:
Input 1:
arr = [1, 7, 3, 6, 5, 6]
Output 1:
3

Input 2:
arr = [1, 2, 3]
Output 2:
-1

Input 3:
arr = [2, 1, -1]
Output 3:
0
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
    long long totalSum = 0;

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        totalSum += arr[i];
    }

    long long leftSum = 0;
    int pivotIndex = -1;

    for (int i = 0; i < n; i++) {
        long long rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum) {
            pivotIndex = i;
            break;
        }

        leftSum += arr[i];
    }

    printf("%d\n", pivotIndex);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for the input array.
*/
