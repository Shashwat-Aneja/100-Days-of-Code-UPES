/*
Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

Sample records:
Asha 101 85
Ravi 102 92

Expected output:
Name: Asha | Roll: 101 | Marks: 85
Name: Ravi | Roll: 102 | Marks: 92

Input format: number of students, followed by one name, roll number, and marks per student.

Time Complexity: O(n), where n is the number of student records.
Space Complexity: O(1) auxiliary space.
*/

#include <stdio.h>

int main(void)
{
    FILE *file;
    int numberOfStudents;
    int i;
    char name[50];
    int rollNumber;
    int marks;

    if (scanf("%d", &numberOfStudents) != 1 || numberOfStudents <= 0)
    {
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }

    file = fopen("students.txt", "w");
    if (file == NULL)
    {
        perror("Unable to create students.txt");
        return 1;
    }

    for (i = 0; i < numberOfStudents; i++)
    {
        if (scanf("%49s %d %d", name, &rollNumber, &marks) != 3)
        {
            fprintf(stderr, "Invalid student record.\n");
            fclose(file);
            return 1;
        }

        if (fprintf(file, "%s %d %d\n", name, rollNumber, marks) < 0)
        {
            fprintf(stderr, "Error writing student record.\n");
            fclose(file);
            return 1;
        }
    }

    if (fclose(file) != 0)
    {
        perror("Error closing students.txt after writing");
        return 1;
    }

    file = fopen("students.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open students.txt for reading");
        return 1;
    }

    while (fscanf(file, "%49s %d %d", name, &rollNumber, &marks) == 3)
    {
        printf("Name: %s | Roll: %d | Marks: %d\n", name, rollNumber, marks);
    }

    if (ferror(file))
    {
        fprintf(stderr, "Error reading students.txt.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0)
    {
        perror("Error closing students.txt after reading");
        return 1;
    }

    return 0;
}
