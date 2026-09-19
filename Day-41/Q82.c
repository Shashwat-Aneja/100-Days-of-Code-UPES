// Q82: Print each character of a string on a new line.

#include <stdio.h>

int main(void) {
    char str[100];
    int i;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        printf("%c\n", str[i]);
    }

    return 0;
}
