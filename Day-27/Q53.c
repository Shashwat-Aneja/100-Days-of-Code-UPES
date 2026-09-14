// Q53: Print the diamond-like star pattern without leading spaces.
#include <stdio.h>

int main(void) {
    int i, j, stars;
    for (i = 1; i <= 9; i += 2) {
        for (j = 1; j <= i; j++) printf("*");
        printf("\n");
    }
    for (i = 7; i >= 1; i -= 2) {
        for (j = 1; j <= i; j++) printf("*");
        printf("\n");
    }
    return 0;
}
