// Q29: Write a program to calculate the factorial of a number.

/*
Sample Test Cases:
Input 1:
5
Output 1:
120

Input 2:
3
Output 2:
6

*/

#include <stdio.h>

int main () {
    int n, i;
    long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for(i = 1; i <= n; i++) {
            factorial *= i; // Calculate factorial
        }
        printf("Factorial of %d = %ld\n", n, factorial);
    }

    return 0;
}
