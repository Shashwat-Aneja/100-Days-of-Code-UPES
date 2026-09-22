// Q87: Count spaces, digits, and special characters in a string.

/*
Sample Test Case:
Input:
Hello 123!
Output:
Spaces = 1
Digits = 3
Special chars = 1
*/

#include <stdio.h>

int main(void) {
    char str[200];
    int spaces = 0, digits = 0, special = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ') {
            spaces++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else if (!((str[i] >= 'A' && str[i] <= 'Z') ||
                     (str[i] >= 'a' && str[i] <= 'z'))) {
            special++;
        }
    }

    printf("Spaces = %d\n", spaces);
    printf("Digits = %d\n", digits);
    printf("Special chars = %d\n", special);

    return 0;
}
