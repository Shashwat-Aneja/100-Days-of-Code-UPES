// Q4: Write a program to calculate the area and circumference of a circle given its radius.
// let pi=3.14
/*
Sample Test Cases:
Input 1:
7
Output 1:
Area=153.94, Circumference=43.96

Input 2:
3
Output 2:
Area=28.27, Circumference=18.85

*/

#include <stdio.h>

int main ()
{
    float a, b, c;

    printf("Enter the radius of the circle: ");
    scanf("%f", &a);

    b = 2*3.14*a;
    c = 3.14 * (a*a);
    printf("Circumference = %f\n", b);
    printf("Area = %f\n", c);
}
