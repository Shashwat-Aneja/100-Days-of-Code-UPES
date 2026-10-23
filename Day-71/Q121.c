/*
Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

Input format: user's name on the first line, followed by age on the second line.
The source page's sample test cases are not included in the provided text.
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[256];
    char age_line[64];

    if (!fgets(name, sizeof name, stdin)) return 1;
    name[strcspn(name, "\n")] = '\0';

    if (!fgets(age_line, sizeof age_line, stdin)) return 1;
    int age;
    char extra;
    if (sscanf(age_line, " %d %c", &age, &extra) != 1 || age < 0) {
        fprintf(stderr, "Invalid age.\n");
        return 1;
    }

    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        perror("Could not create info.txt");
        return 1;
    }

    int write_ok = fprintf(file, "Name: %s\nAge: %d\n", name, age) >= 0;
    if (fclose(file) != 0) write_ok = 0;

    if (!write_ok) {
        fprintf(stderr, "Failed to save data to info.txt.\n");
        return 1;
    }

    puts("Data successfully saved to info.txt.");
    return 0;
}
/* Time: O(L), where L is the name length. Auxiliary space: O(L) for input. */
