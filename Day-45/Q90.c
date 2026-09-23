// Q90: Toggle case of each character in a string.

/*
Sample Test Case:
Input:
Hello
Output:
hELLO
*/

#include <stdio.h>

int main(void) {
    char str[200];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)(str[i] - 'a' + 'A');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char)(str[i] - 'A' + 'a');
        }
    }

    printf("%s", str);

    return 0;
}
