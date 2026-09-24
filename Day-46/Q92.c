// Q92: Find the first repeating lowercase alphabet in a string.

/*
Sample Test Case:
Input:
stress
Output:
s
*/

#include <stdio.h>

int main(void) {
    char str[1000];
    int frequency[26] = {0};
    int i;
    char result = '\0';

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int index = str[i] - 'a';
            frequency[index]++;
            if (frequency[index] == 2) {
                result = str[i];
                break;
            }
        }
    }

    if (result != '\0') {
        printf("First repeating lowercase alphabet: %c\n", result);
    } else {
        printf("No repeating lowercase alphabet found.\n");
    }

    return 0;
}
