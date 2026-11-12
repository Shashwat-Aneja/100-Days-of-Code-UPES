/*
Q141: Define a structure Student with name, roll_no, and marks, then read and print one student's data.

Time complexity: O(1) for bounded input.
Auxiliary space complexity: O(1).
*/
#include <stdio.h>

typedef struct {
    char name[100];
    int roll_no;
    int marks;
} Student;

int main(void) {
    Student student;
    char line[128];

    if (fgets(line, sizeof line, stdin) == NULL ||
        sscanf(line, "Name: %99[^\n]", student.name) != 1) {
        return 1;
    }
    if (fgets(line, sizeof line, stdin) == NULL ||
        sscanf(line, "Roll: %d", &student.roll_no) != 1) {
        return 1;
    }
    if (fgets(line, sizeof line, stdin) == NULL ||
        sscanf(line, "Marks: %d", &student.marks) != 1) {
        return 1;
    }

    printf("Name: %s | Roll: %d | Marks: %d\n",
           student.name, student.roll_no, student.marks);
    return 0;
}
