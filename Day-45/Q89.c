// Q89: Count frequency of a given character in a string.

/*
Sample Test Case:
Input:
programming
g
Output:
2
*/

#include <stdio.h>

int main(void) {
    char str[200];
    char target;
    int count = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    printf("Enter the character to count: ");
    if (scanf(" %c", &target) != 1) {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
