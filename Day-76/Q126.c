/*
Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.

Sample test cases from the source:
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully.
(Displays file content)

Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!
*/
#include <stdio.h>
#include <string.h>

#define FILENAME_SIZE 256
#define LINE_SIZE 1024

int main(void) {
    char filename[FILENAME_SIZE];
    char line[LINE_SIZE];

    printf("Filename: ");
    if (fgets(filename, sizeof filename, stdin) == NULL) {
        fprintf(stderr, "Error: Could not read the filename.\n");
        return 1;
    }

    filename[strcspn(filename, "\r\n")] = '\0';

    if (filename[0] == '\0') {
        fprintf(stderr, "Error: Filename cannot be empty.\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        puts("Error: File does not exist!");
        return 1;
    }

    puts("File opened successfully.");

    while (fgets(line, sizeof line, file) != NULL) {
        if (fputs(line, stdout) == EOF) {
            fprintf(stderr, "Error: Could not display file content.\n");
            fclose(file);
            return 1;
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: Could not read file content.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error: Could not close the file.\n");
        return 1;
    }

    return 0;
}

/* Time complexity: O(F), where F is the number of characters in the file.
   Auxiliary space: O(B), where B is the fixed line-buffer size. */
