/*
Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

Sample Test Case from the source:
File: sample.txt (Content: Hello world\nThis is C programming)
Source-listed output:
Characters: 31
Words: 5
Lines: 2

Note: The source's sample output is inconsistent with its stated input and word definition.
The content contains 33 characters when the newline is counted, 6 words, and 2 lines.
This program reports the counts based on the file's actual contents.
*/
#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("Unable to open sample.txt");
        return 1;
    }

    long long characters = 0;
    long long words = 0;
    long long lines = 0;
    int ch;
    int in_word = 0;
    int has_content = 0;
    int last_char_was_newline = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        has_content = 1;
        last_char_was_newline = (ch == '\n');

        if (ch == '\n') {
            lines++;
        }

        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
    }

    if (ferror(file)) {
        perror("Error reading sample.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Error closing sample.txt");
        return 1;
    }

    if (has_content && !last_char_was_newline) {
        lines++;
    }

    printf("Characters: %lld\n", characters);
    printf("Words: %lld\n", words);
    printf("Lines: %lld\n", lines);

    return 0;
}

/* Time complexity: O(n), where n is the file size in characters.
   Auxiliary space: O(1). */
