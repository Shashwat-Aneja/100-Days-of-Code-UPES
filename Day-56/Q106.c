// Q106: Write a program to take an array arr[] of integers as input, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.
//
// N.B:
// - Print the output for each element in a comma separated fashion.
// - Do not use Stack, use brute force approach (nested loop) to solve.
//
// Try solving this using brute force (nested loop). No need of attempting the optimized stack-based solution.

/*
Sample Test Cases:
Input 1:
arr = [4, 5, 2, 25]
Output 1:
5,25,25,-1

Input 2:
arr = [13, 7, 6, 12]
Output 2:
-1,12,12,-1

Input 3:
arr = [1, 3, 2, 4]
Output 3:
3,4,4,-1
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
        scanf("%d", &arr[i]);
    }

    /*
       Brute-force approach:
       For every element, scan the elements to its right.
       The first element greater than the current element
       is its next greater element.
    */
    for (int i = 0; i < n; i++) {
        int nextGreater = -1;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nextGreater = arr[j];
                break;
            }
        }

        if (i > 0) {
            printf(",");
        }
        printf("%d", nextGreater);
    }

    printf("\n");

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n) for the input array.
*/
