/*
Q120: Write a program to take a string input. Change it to sentence case.

Input format: one line of text.
Interpretation used: capitalize the first alphabetic character and convert subsequent alphabetic characters to lowercase.
The source page's sample test cases are not included in the provided text.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char text[10000];
    if (!fgets(text, sizeof text, stdin)) return 1;

    int first_letter_seen = 0;
    for (size_t i = 0; text[i] != '\0'; ++i) {
        unsigned char ch = (unsigned char)text[i];
        if (isalpha(ch)) {
            if (!first_letter_seen) {
                text[i] = (char)toupper(ch);
                first_letter_seen = 1;
            } else {
                text[i] = (char)tolower(ch);
            }
        }
    }

    size_t length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') text[length - 1] = '\0';
    puts(text);
    return 0;
}
/* Time: O(L). Auxiliary space: O(1) beyond the input buffer, where L is the text length. */
