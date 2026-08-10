// Q2: Write a program to input two numbers and display their sum, difference, product, and quotient.

/*
Sample Test Cases:
Input 1:
10 2
Output 1:
Sum=12, Diff=8, Product=20, Quotient=5

Input 2:
7 3
Output 2:
Sum=10, Diff=4, Product=21, Quotient=2

*/
#include <stdio.h>

int main ()
{
    int a, b, c, d, e, f;

    printf("Enter any two numbers: ");
    scanf("%d%d", &a, &b);

    c = a + b;
    d=a*b;
    e=a-b;
    f=a/b;
    printf("Sum = %d", c);
    printf("\nMultiplication = %d", d);
    printf("\nSubtraction = %d", e);    
    printf("\nDivision = %d", f);
}