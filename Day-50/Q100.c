// Q100: Print all sub-strings of a string.

/*
Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    int first = 1;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    for (int start = 0; str[start] != '\0'; start++) {
        for (int end = start; str[end] != '\0'; end++) {
            if (!first) {
                printf(",");
            }

            for (int k = start; k <= end; k++) {
                putchar(str[k]);
            }

            first = 0;
        }
    }

    printf("\n");
    return 0;
}
