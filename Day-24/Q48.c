// Q48: Write a program to print the numeric triangle 1, 12, 123, ...
#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) printf("%d", j);
        printf("\n");
    }
    return 0;
}
