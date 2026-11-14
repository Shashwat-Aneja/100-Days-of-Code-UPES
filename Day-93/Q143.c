/*
Q143: Find and print the student with the highest marks.

Time complexity: O(n), where n is the number of students.
Auxiliary space complexity: O(1), excluding the fixed-size input buffers.
*/
#include <stdio.h>

#define NAME_SIZE 100

typedef struct {
    char name[NAME_SIZE];
    int roll_no;
    int marks;
} Student;

int main(void) {
    int count;
    Student student;
    Student topper;

    /* Enter the number of students, then each name, roll number and marks. */
    if (scanf("%d", &count) != 1 || count <= 0) {
        puts("Invalid number of students");
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        if (scanf("%99s %d %d", student.name, &student.roll_no,
                  &student.marks) != 3) {
            puts("Invalid student details");
            return 1;
        }

        if (i == 0 || student.marks > topper.marks) {
            topper = student;
        }
    }

    printf("Topper: %s (Marks: %d)\n", topper.name, topper.marks);
    return 0;
}
