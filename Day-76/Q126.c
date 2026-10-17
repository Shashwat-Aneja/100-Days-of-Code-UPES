/*
Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.

Sample:
Filename: nofile.txt -> Error: File does not exist!
For an existing file, display its contents.
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[256];
    if (!fgets(filename, sizeof filename, stdin)) return 1;
    filename[strcspn(filename, "\r\n")] = '\0';
    FILE *file = fopen(filename, "r");
    if (!file) {
        puts("Error: File does not exist!");
        return 1;
    }

    puts("File opened successfully.");
    char buffer[1024];
    while (fgets(buffer, sizeof buffer, file) != NULL) {
        if (fputs(buffer, stdout) == EOF) {
            fclose(file);
            return 1;
        }
    }
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }
    return fclose(file) == 0 ? 0 : 1;
}
/* Time: O(B). Auxiliary space: O(1). */
