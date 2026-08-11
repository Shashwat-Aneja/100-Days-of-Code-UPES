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
