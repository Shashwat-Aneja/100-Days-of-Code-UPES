/*
Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

Input format: source filename on the first line, destination filename on the second line.

Sample test case from the source:
Source file: source.txt (content: Learning C File Handling)
Destination file: destination.txt
Output: File copied successfully to destination.txt
Expected destination.txt content: Learning C File Handling
*/
#include <stdio.h>
#include <string.h>

#define FILENAME_SIZE 512

static void remove_line_ending(char *text) {
    text[strcspn(text, "\r\n")] = '\0';
}

int main(void) {
    char source_name[FILENAME_SIZE];
    char destination_name[FILENAME_SIZE];

    if (fgets(source_name, sizeof source_name, stdin) == NULL ||
        fgets(destination_name, sizeof destination_name, stdin) == NULL) {
        fprintf(stderr, "Please provide the source and destination filenames.\n");
        return 1;
    }

    remove_line_ending(source_name);
    remove_line_ending(destination_name);

    if (source_name[0] == '\0' || destination_name[0] == '\0') {
        fprintf(stderr, "Filenames cannot be empty.\n");
        return 1;
    }

    if (strcmp(source_name, destination_name) == 0) {
        fprintf(stderr, "Source and destination filenames must be different.\n");
        return 1;
    }

    FILE *source = fopen(source_name, "rb");
    if (source == NULL) {
        perror("Could not open source file");
        return 1;
    }

    FILE *destination = fopen(destination_name, "wb");
    if (destination == NULL) {
        perror("Could not open destination file");
        fclose(source);
        return 1;
    }

    int ch;
    int failed = 0;
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) {
            perror("Error writing to destination file");
            failed = 1;
            break;
        }
    }

    if (ferror(source)) {
        perror("Error reading source file");
        failed = 1;
    }

    if (fclose(source) != 0) {
        perror("Error closing source file");
        failed = 1;
    }

    if (fclose(destination) != 0) {
        perror("Error closing destination file");
        failed = 1;
    }

    if (failed) {
        return 1;
    }

    printf("File copied successfully to %s\n", destination_name);
    return 0;
}

/* Time complexity: O(n), where n is the number of bytes in the source file.
   Auxiliary space: O(1). */
