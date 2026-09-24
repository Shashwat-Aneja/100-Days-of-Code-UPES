// Q91: Remove all vowels from a string.

/*
Sample Test Case:
Input:
education
Output:
dctn
*/

#include <stdio.h>

int is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int main(void) {
    char str[1000];
    int i;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    printf("String without vowels: ");
    for (i = 0; str[i] != '\0'; i++) {
        if (!is_vowel(str[i])) {
            putchar(str[i]);
        }
    }

    return 0;
}
