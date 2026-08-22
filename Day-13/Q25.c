// Q25: Write a program to implement a basic calculator using switch-case for +, -, *, /, %.

/*
Sample Test Cases:
Input 1:
4 2 +
Output 1:
6

Input 2:
10 3 %
Output 2:
1

Input 3:
15 5 /
Output 3:
3

*/

#include <stdio.h>

int main ()
{
    int a, b, result;
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    switch (operator){
        case '+':
            result = a + b;
            printf("%d + %d = %d\n", a, b, result);
            break; 
        case '-':
            result = a - b;
            printf("%d - %d = %d\n", a, b, result);
            break;
        case '*':
            result = a * b;
            printf("%d * %d = %d\n", a, b, result);
            break;
        case '/':
            result = a / b;
            printf("%d / %d = %d\n", a, b, result);
            break;
    }
}
