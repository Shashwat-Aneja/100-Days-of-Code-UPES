// Q107: Write a program to take an array arr[] of integers as input, the task is to find the previous greater element for each element of the array in order of their appearance in the array. Previous greater element of an element in the array is the nearest element on the left which is greater than the current element. If there does not exist next greater of current element, then previous greater element for current element is -1.
//
// N.B:
// - Print the output for each element in a comma separated fashion.
// - Do not use Stack, use brute force approach (nested loop) to solve.
//
// Try solving this using brute force (nested loop). No need of attempting the optimized stack-based solution.

/*
Sample Test Cases:
Input 1:
arr = [10, 4, 2, 20, 40, 12, 30]
Output 1:
-1,10,4,-1,-1,40,40

Input 2:
arr = [1, 3, 2, 4]
Output 2:
-1,-1,3,-1

Input 3:
arr = [10, 5, 11, 6, 20, 12]
Output 3:
-1,10,-1,11,-1,20
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
       For every element, scan elements to its left from
       nearest to farthest. The first greater element found
       is the previous greater element.
    */
    for (int i = 0; i < n; i++) {
        int previousGreater = -1;

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                previousGreater = arr[j];
                break;
            }
        }

        if (i > 0) {
            printf(",");
        }
        printf("%d", previousGreater);
    }

    printf("\n");

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n) for the input array.
*/
