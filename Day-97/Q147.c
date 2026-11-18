/*
Q147: Store employee data in a binary file using fwrite() and read using fread().

Input: Employee name, ID and salary (space-separated).
Output: Displays the employee data read back from the binary file.
Time complexity: O(1) for one fixed-size record.
Auxiliary space complexity: O(1).
*/
#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    double salary;
};

int main(void) {
    struct Employee employee = {0};
    struct Employee saved = {0};
    FILE *file;

    if (scanf("%49s %d %lf", employee.name, &employee.id,
              &employee.salary) != 3) {
        fprintf(stderr, "Invalid employee details.\n");
        return 1;
    }

    file = fopen("employee.dat", "wb");
    if (file == NULL) {
        perror("Cannot open file for writing");
        return 1;
    }
    if (fwrite(&employee, sizeof employee, 1, file) != 1) {
        fprintf(stderr, "Could not write employee data.\n");
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        perror("Could not close written file");
        return 1;
    }

    file = fopen("employee.dat", "rb");
    if (file == NULL) {
        perror("Cannot open file for reading");
        return 1;
    }
    if (fread(&saved, sizeof saved, 1, file) != 1) {
        fprintf(stderr, "Could not read employee data.\n");
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        perror("Could not close read file");
        return 1;
    }

    printf("Name: %s | ID: %d | Salary: %.2f\n",
           saved.name, saved.id, saved.salary);
    return 0;
}
