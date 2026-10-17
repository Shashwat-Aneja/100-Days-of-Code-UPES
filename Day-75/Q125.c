/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

Sample: data.txt initially contains "Hello world"; append "This is appended text."
Expected confirmation: File updated successfully with appended text.
Input format: filename on the first line, text to append on the second line.
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[256], text[4096];
    if (!fgets(filename, sizeof filename, stdin)) return 1;
    filename[strcspn(filename, "\r\n")] = '\0';
    if (filename[0] == '\0' || !fgets(text, sizeof text, stdin)) return 1;
    size_t len = strlen(text);
    while (len > 0 && (text[len - 1] == '\n' || text[len - 1] == '\r'))
        text[--len] = '\0';

    FILE *file = fopen(filename, "a");
    if (!file) {
        perror(filename);
        return 1;
    }
    int failed = fprintf(file, "%s%s", len ? "\n" : "", text) < 0;
    if (fclose(file) != 0) failed = 1;
    if (failed) {
        fputs("Error appending text.\n", stderr);
        return 1;
    }
    puts("File updated successfully with appended text.");
    return 0;
}
/* Time: O(L). Auxiliary space: O(L) for the input line. */
