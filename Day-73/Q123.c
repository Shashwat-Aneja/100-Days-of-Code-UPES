/*
Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

Sample file: sample.txt containing "Hello world\nThis is C programming"
Note: The source lists 31 characters, but counting every byte including the newline gives 33 for this exact content. This implementation counts newline characters as characters and a final unterminated line as one line.
*/
#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *file = fopen("sample.txt", "r");
    if (!file) {
        perror("sample.txt");
        return 1;
    }

    long long characters = 0, words = 0, lines = 0;
    int ch, in_word = 0, any_character = 0, last_char = '\n';
    while ((ch = fgetc(file)) != EOF) {
        ++characters;
        any_character = 1;
        last_char = ch;
        if (ch == '\n') ++lines;
        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            ++words;
            in_word = 1;
        }
    }
    if (ferror(file)) {
        perror("Error reading sample.txt");
        fclose(file);
        return 1;
    }
    if (any_character && last_char != '\n') ++lines;
    if (fclose(file) != 0) return 1;

    printf("Characters: %lld\nWords: %lld\nLines: %lld\n",
           characters, words, lines);
    return 0;
}
/* Time: O(B). Auxiliary space: O(1). */
