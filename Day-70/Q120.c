/*
Q120: Write a program to take a string input. Change it to sentence case.

Source examples:
"I am trying to build logic." -> "I Am Trying To Build Logic"
"The classes are supposed to start early." -> "The Classes Are Supposed To Start Early."
"We are going to look at 26 different test cases." -> "We Are Going To Look At 26 Different Test Cases."

The published examples capitalize each word, so this solution follows that demonstrated behavior.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char line[10000];
    if (!fgets(line, sizeof line, stdin)) return 1;
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') line[--len] = '\0';

    int word_start = 1;
    for (size_t i = 0; i < len; ++i) {
        unsigned char ch = (unsigned char)line[i];
        if (isspace(ch)) {
            word_start = 1;
        } else {
            line[i] = (char)(word_start ? toupper(ch) : tolower(ch));
            word_start = 0;
        }
    }
    puts(line);
    return 0;
}
/* Time: O(n). Auxiliary space: O(1) beyond the fixed input buffer. */
