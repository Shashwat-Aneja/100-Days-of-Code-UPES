/*
Q122: Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.

Sample Test Case:
File: info.txt (Content: Name: Rahul\nAge: 23)
Output:
Name: Rahul
Age: 23
*/
#include <stdio.h>

int main(void) {
    FILE *file = fopen("info.txt", "r");
    if (file == NULL) {
        perror("Unable to open info.txt");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof line, file) != NULL) {
        fputs(line, stdout);
    }

    if (ferror(file)) {
        perror("Error reading info.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Error closing info.txt");
        return 1;
    }

    return 0;
}

/* Time complexity: O(B), where B is the number of bytes read.
   Auxiliary space: O(L), where L is the buffer size. */
