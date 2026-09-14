// Q50: Write a program to print a right-shifted descending star pattern.
#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 5; i >= 1; i--) {
        for (j = 1; j <= 5 - i; j++) printf("  ");
        for (j = 1; j <= i; j++) printf("* ");
        printf("\n");
    }
    return 0;
}
