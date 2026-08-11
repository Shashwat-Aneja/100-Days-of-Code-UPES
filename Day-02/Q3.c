// Q3: Write a program to calculate the area and perimeter of a rectangle given its length and breadth.

/*
Sample Test Cases:
Input 1:
5 10
Output 1:
Area=50, Perimeter=30

Input 2:
3 7
Output 2:
Area=21, Perimeter=20

*/

#include <stdio.h>

int main ()
{
    int a, b, c, d;

    printf("Enter the dimensions of the Rectangle: ");
    scanf("%d%d", &a, &b);

    c = (a+b)*2;
    d = a*b;
    printf("Peremetre = %d\n", c);
    printf("Area = %d\n", d);
}
