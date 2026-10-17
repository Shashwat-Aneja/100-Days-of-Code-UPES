/*
Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

Sample: Name: Rahul, Age: 23
Expected confirmation: File created successfully! Data written to info.txt
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[200];
    int age;
    if (!fgets(name, sizeof name, stdin)) return 1;
    name[strcspn(name, "\r\n")] = '\0';
    if (scanf("%d", &age) != 1 || age < 0) return 1;

    FILE *file = fopen("info.txt", "w");
    if (!file) {
        perror("info.txt");
        return 1;
    }
    int result = fprintf(file, "Name: %s\nAge: %d\n", name, age);
    if (fclose(file) != 0 || result < 0) {
        fputs("Error writing data to info.txt\n", stderr);
        return 1;
    }
    puts("File created successfully! Data written to info.txt");
    return 0;
}
/* Time: O(L), where L is the name length. Auxiliary space: O(L). */
