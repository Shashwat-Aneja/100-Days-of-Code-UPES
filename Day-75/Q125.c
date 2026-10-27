/*
Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

Sample test case from the source:
Existing file: data.txt (content before execution: Hello world)
User input: This is appended text.
Output: File updated successfully with appended text.
Expected data.txt content after execution:
Hello world
This is appended text.
*/
#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 1024

static void remove_line_ending(char *text) {
    text[strcspn(text, "\r\n")] = '\0';
}

int main(void) {
    char text[TEXT_SIZE];

    if (fgets(text, sizeof text, stdin) == NULL) {
        fprintf(stderr, "Please enter the text to append.\n");
        return 1;
    }
    remove_line_ending(text);

    /* Check the existing file so the new text starts on a new line. */
    FILE *existing = fopen("data.txt", "rb");
    if (existing == NULL) {
        perror("Could not open existing data.txt");
        return 1;
    }

    if (fseek(existing, 0, SEEK_END) != 0) {
        perror("Could not seek in data.txt");
        fclose(existing);
        return 1;
    }

    long file_size = ftell(existing);
    if (file_size < 0) {
        perror("Could not determine data.txt size");
        fclose(existing);
        return 1;
    }

    int last_character = '\n';
    if (file_size > 0) {
        if (fseek(existing, -1L, SEEK_END) != 0) {
            perror("Could not inspect the end of data.txt");
            fclose(existing);
            return 1;
        }
        last_character = fgetc(existing);
        if (last_character == EOF) {
            fprintf(stderr, "Could not read the end of data.txt.\n");
            fclose(existing);
            return 1;
        }
    }

    if (fclose(existing) != 0) {
        perror("Could not close data.txt after reading");
        return 1;
    }

    FILE *file = fopen("data.txt", "a");
    if (file == NULL) {
        perror("Could not open data.txt in append mode");
        return 1;
    }

    int failed = 0;
    if (file_size > 0 && last_character != '\n' && fputc('\n', file) == EOF) {
        failed = 1;
    }
    if (fputs(text, file) == EOF || fputc('\n', file) == EOF) {
        failed = 1;
    }

    if (fclose(file) != 0) {
        failed = 1;
    }

    if (failed) {
        fprintf(stderr, "Failed to append text to data.txt.\n");
        return 1;
    }

    puts("File updated successfully with appended text.");
    return 0;
}

/* Time complexity: O(L) for writing the new line; auxiliary space: O(L), where L is the input buffer size. */
