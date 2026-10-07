// Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
// Follow-up (optional): Can you write a code that runs in O(n) time and without using the division operation?

/*
Sample Test Cases:
Input 1:
nums = [1, 2, 3, 4]
Output 1:
[24, 12, 8, 6]

Input 2:
nums = [-1, 1, 0, -3, 3]
Output 2:
[0, 0, 9, 0, 0]
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
    long long answer[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    /*
       First pass:
       answer[i] stores the product of all elements to the left of i.

       Second pass:
       Multiply by the product of all elements to the right of i.

       This avoids division and runs in O(n) time.
    */
    long long prefix = 1;

    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    long long suffix = 1;

    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    printf("Product array: ");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%lld", answer[i]);
    }
    printf("\n");

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for the output array.
No division operation is used.
*/
