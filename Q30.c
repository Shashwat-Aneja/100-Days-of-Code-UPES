// Q30: Write a program to reverse a given number.

/*
Sample Test Cases:
Input 1:
1234
Output 1:
4321

Input 2:
100
Output 2:
1

*/

#include <stdio.h>

int main() {
    int num, a, b, c;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    a = num % 10;
    num = num / 10;

    b = num % 10;
    num = num / 10;

    c = num % 10;

    printf("Reverse number: %d%d%d", a, b, c);
}
