// Q99: Change the date format from dd/04/yyyy to dd-Apr-yyyy.

/*
Sample Test Cases:
Input 1:
15/04/2025
Output 1:
15-Apr-2025
*/

#include <stdio.h>

int main(void) {
    int day, month, year;
    char separator;

    printf("Enter date (dd/04/yyyy): ");
    if (scanf("%d%c%d%c%d", &day, &separator, &month, &separator, &year) != 5) {
        printf("Invalid date format.\n");
        return 1;
    }

    if (month != 4 || day < 1 || day > 30 || year < 1) {
        printf("Invalid date.\n");
        return 1;
    }

    printf("%02d-Apr-%04d\n", day, year);

    return 0;
}
