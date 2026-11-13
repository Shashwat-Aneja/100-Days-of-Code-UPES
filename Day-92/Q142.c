/*
Q142: Store details of 5 students in an array of structures and print all.

Time complexity: O(n), where n = 5 students.
Auxiliary space complexity: O(n) for the array of student records.
*/
#include <stdio.h>

#define STUDENT_COUNT 5
#define NAME_LENGTH 50

struct Student {
    char name[NAME_LENGTH];
    int roll_no;
    int marks;
};

int main(void) {
    struct Student students[STUDENT_COUNT];

    for (int i = 0; i < STUDENT_COUNT; i++) {
        if (scanf("%49s %d %d", students[i].name,
                  &students[i].roll_no, &students[i].marks) != 3) {
            return 1;
        }
    }

    printf("Name\tRoll\tMarks\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s\t%d\t%d\n", students[i].name,
               students[i].roll_no, students[i].marks);
    }

    return 0;
}
