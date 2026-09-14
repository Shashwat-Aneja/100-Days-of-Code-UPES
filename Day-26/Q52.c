// Q52: Write a program to print the star pattern with 1, 3, 5, 3, 1 stars.
#include <stdio.h>

int main(void) {
    int row, j, stars;
    for (row = 1; row <= 5; row++) {
        stars = row <= 3 ? 2 * row - 1 : 9 - 2 * row;
        for (j = 1; j <= stars; j++) printf("*");
        printf("\n");
    }
    return 0;
}
