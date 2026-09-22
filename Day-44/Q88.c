// Q88: Replace spaces with hyphens in a string.

/*
Sample Test Case:
Input:
Hello World From C
Output:
Hello-World-From-C
*/

#include <stdio.h>

int main(void) {
    char str[200];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }

    printf("%s", str);

    return 0;
}
