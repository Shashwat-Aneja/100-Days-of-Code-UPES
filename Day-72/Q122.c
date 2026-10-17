/*
Q122: Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.

Sample file content:
Name: Rahul
Age: 23
Expected output:
Name: Rahul
Age: 23
*/
#include <stdio.h>

int main(void) {
    FILE *file = fopen("info.txt", "r");
    if (!file) {
        perror("info.txt");
        return 1;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof buffer, file) != NULL) {
        if (fputs(buffer, stdout) == EOF) {
            fclose(file);
            return 1;
        }
    }
    if (ferror(file)) {
        perror("Error reading info.txt");
        fclose(file);
        return 1;
    }
    return fclose(file) == 0 ? 0 : 1;
}
/* Time: O(B), where B is the number of bytes read. Auxiliary space: O(1). */
