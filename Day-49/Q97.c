// Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char name[200];
    int new_word = 1;
    int first = 1;

    printf("Enter name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; name[i] != '\0'; i++) {
        if (isspace((unsigned char)name[i])) {
            new_word = 1;
        } else if (new_word) {
            if (!first) {
                printf(".");
            }
            printf("%c", (char)toupper((unsigned char)name[i]));
            first = 0;
            new_word = 0;
        }
    }

    if (!first) {
        printf(".");
    }
    printf("\n");

    return 0;
}
