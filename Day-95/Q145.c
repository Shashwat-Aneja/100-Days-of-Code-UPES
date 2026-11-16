/*
Q145: Return a structure containing top student's details from a function.

Sample input (three students):
Riya 101 89
Karan 102 96
Meena 103 92

Expected output:
Top Student: Karan | Roll: 102 | Marks: 96

Time complexity: O(n), where n is the number of students.
Auxiliary space complexity: O(1), since only one current and one top student are stored.
*/
#include <stdio.h>

typedef struct {
    char name[100];
    int roll_no;
    int marks;
} Student;

/* Return the highest-scoring student by value. */
Student findTopStudent(int count) {
    Student current;
    Student top = {{0}, 0, 0};

    for (int i = 0; i < count; ++i) {
        if (scanf("%99s %d %d", current.name, &current.roll_no, &current.marks) != 3) {
            Student invalid = {{0}, 0, 0};
            return invalid;
        }
        if (i == 0 || current.marks > top.marks) {
            top = current;
        }
    }
    return top;
}

int main(void) {
    int count;
    if (scanf("%d", &count) != 1 || count <= 0) {
        return 1;
    }

    Student top = findTopStudent(count);
    if (top.name[0] == '\0') {
        return 1;
    }
    printf("Top Student: %s | Roll: %d | Marks: %d\n", top.name, top.roll_no, top.marks);
    return 0;
}
