/*
Q146: Create Employee structure with nested Date structure for joining date and print details.

Official sample input:
Employee: Raj | ID: 11 | Joining Date: 12 05 2020
Official sample output:
Name: Raj | ID: 11 | Joining Date: 12/05/2020

Time complexity: O(1).
Auxiliary space complexity: O(1).
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[100];
    int id;
    Date joining_date;
} Employee;

int main(void) {
    Employee employee;
    char line[256];

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }

    /* Accept the descriptive sample format or simple space-separated values. */
    if (sscanf(line, "Employee: %99[^|] | ID: %d | Joining Date: %d %d %d",
               employee.name, &employee.id, &employee.joining_date.day,
               &employee.joining_date.month, &employee.joining_date.year) != 5) {
        if (sscanf(line, "%99s %d %d %d %d", employee.name, &employee.id,
                   &employee.joining_date.day, &employee.joining_date.month,
                   &employee.joining_date.year) != 5) {
            return 1;
        }
    } else {
        size_t length = strlen(employee.name);
        while (length > 0 && employee.name[length - 1] == ' ') {
            employee.name[--length] = '\0';
        }
    }

    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           employee.name, employee.id, employee.joining_date.day,
           employee.joining_date.month, employee.joining_date.year);
    return 0;
}
