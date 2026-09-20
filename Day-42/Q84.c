// Q84: Convert a lowercase string to uppercase without using built-in functions.

/*
Sample Test Case:
Input:
hello
Output:
HELLO
*/

#include <stdio.h>

int main(void) {
    char str[1000];

    printf("Enter a lowercase string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)(str[i] - ('a' - 'A'));
        }
    }

    printf("%s", str);

    return 0;
}
