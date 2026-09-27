// Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char name[200];
    char words[20][50];
    int count = 0;

    printf("Enter name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        return 1;
    }

    char *token = strtok(name, " \t\n\r");
    while (token != NULL && count < 20) {
        strncpy(words[count], token, sizeof(words[count]) - 1);
        words[count][sizeof(words[count]) - 1] = '\0';
        count++;
        token = strtok(NULL, " \t\n\r");
    }

    if (count == 0) {
        printf("No name entered.\n");
        return 0;
    }

    for (int i = 0; i < count - 1; i++) {
        printf("%c.", (char)toupper((unsigned char)words[i][0]));
    }

    printf(" %s\n", words[count - 1]);

    return 0;
}
