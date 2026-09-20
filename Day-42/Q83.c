// Q83: Count vowels and consonants in a string.

/*
Sample Test Case:
Input:
hello
Output:
Vowels=2, Consonants=3
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[1000];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (isalpha(ch)) {
            ch = (unsigned char)tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels=%d, Consonants=%d\n", vowels, consonants);

    return 0;
}
