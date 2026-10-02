// Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

/*
Follow-up 1 (optional):
Can you do it in O(log n) Time Complexity?

Follow-up 2 (optional):
Can you do it in O(1) Time Complexity?

Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    long long n;

    printf("Enter a positive integer n: ");
    if (scanf("%lld", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    /*
       Sum(1..x) = Sum(x..n)

       x(x + 1)/2 = n(n + 1)/2 - x(x - 1)/2

       This simplifies to:
       x^2 = n(n + 1)/2

       Therefore, x exists only when n(n + 1)/2 is a perfect square.
       The square root gives the required pivot integer.
    */

    long long triangular = n * (n + 1) / 2;
    long long x = (long long)sqrt((long double)triangular);

    if (x * x == triangular) {
        printf("%lld\n", x);
    } else {
        printf("-1\n");
    }

    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)

The O(1) solution directly uses the mathematical condition:
x^2 = n(n + 1) / 2
*/
