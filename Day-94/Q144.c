/*
 * Q144: Write a function that accepts a structure as parameter and prints its members.
 * Time complexity: O(1), for a bounded-length name.
 * Auxiliary space complexity: O(1).
 */
#include <stdio.h>

typedef struct {
    char name[100];
    int roll_no;
    int marks;
} Student;

void printStudent(Student student) {
    printf("Name: %s | Roll: %d | Marks: %d\n",
           student.name, student.roll_no, student.marks);
}

int main(void) {
    Student student;
    char line[256];

    if (fgets(line, sizeof line, stdin) == NULL) {
        return 1;
    }

    /* Accept the published sample's "Student:" label or plain values. */
    int fields = sscanf(line, " Student: %99s %d %d",
                        student.name, &student.roll_no, &student.marks);
    if (fields != 3) {
        fields = sscanf(line, " %99s %d %d",
                        student.name, &student.roll_no, &student.marks);
    }
    if (fields != 3) {
        fputs("Invalid student data\n", stderr);
        return 1;
    }

    printStudent(student);
    return 0;
}
