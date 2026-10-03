// Q105: Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than floor(n / 2) times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.

/*
Follow-up (optional):
Can you do it in O(n) Time Complexity?

Sample Test Cases:
Input 1:
nums = [3, 2, 3]
Output 1:
3

Input 2:
nums = [2, 2, 1, 1, 1, 2, 2]
Output 2:
2

Input 3:
nums = [1, 2, 3, 4]
Output 3:
-1
*/

#include <stdio.h>

int main(void) {
    int n;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    /*
       Boyer-Moore Majority Vote Algorithm:
       The candidate is found in O(n) time and O(1) extra space.
    */
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    /* Verify that the candidate is actually a majority element. */
    int frequency = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            frequency++;
        }
    }

    if (frequency > n / 2) {
        printf("%d\n", candidate);
    } else {
        printf("-1\n");
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for the input array, O(1) extra space.
*/
