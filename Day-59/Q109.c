// Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

/*
Sample Test Cases:
Input 1:
arr = [100, 200, 300, 400], k = 2
Output 1:
700

Input 2:
arr = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output 2:
39

Input 3:
arr = [2, 3], k = 1
Output 3:
3
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

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
        printf("Invalid value of k.\n");
        return 1;
    }

    /*
       Sliding-window approach:
       Calculate the first window sum, then move the window
       one position at a time by removing the outgoing element
       and adding the incoming element.
    */
    long long windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    long long maxSum = windowSum;

    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];

        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    printf("%lld\n", maxSum);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for the input array.
*/
