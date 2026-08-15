// Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.

/*
Sample Test Cases:
Input 1:
1000 5 2
Output 1:
Simple Interest=100, Compound Interest=102.5

Input 2:
5000 7 3
Output 2:
Simple Interest=1050, Compound Interest=1125.76

*/

#include <stdio.h>

int main() {
    int a, b, c, d;

    printf("Enter the amount as Principal, rate of interest (p.a.) and time(in yrs.): ");
    scanf("%d%d%d", &a, &b, &c);

    d = (a*b*c)/100;
    printf("Simple Interest = ₹%d\n", d);
    return 0;
}
