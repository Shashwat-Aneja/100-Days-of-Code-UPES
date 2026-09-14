// Q46: Write a program to print a 5x5 star pattern.
#include <stdio.h>

int main(void) {
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
