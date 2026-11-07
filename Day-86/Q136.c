/*
Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

Sample Test Case:
Input: ADD 10 20
Output: 30

Time Complexity: O(1)
Auxiliary Space Complexity: O(1)
*/

#include <stdio.h>
#include <string.h>

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY
} MenuChoice;

int main(void)
{
    char operationText[16];
    long long firstNumber;
    long long secondNumber;
    MenuChoice choice;

    if (scanf("%15s %lld %lld", operationText, &firstNumber, &secondNumber) != 3) {
        return 1;
    }

    if (strcmp(operationText, "ADD") == 0) {
        choice = ADD;
    } else if (strcmp(operationText, "SUBTRACT") == 0) {
        choice = SUBTRACT;
    } else if (strcmp(operationText, "MULTIPLY") == 0) {
        choice = MULTIPLY;
    } else {
        printf("Invalid choice\n");
        return 0;
    }

    switch (choice) {
        case ADD:
            printf("%lld\n", firstNumber + secondNumber);
            break;
        case SUBTRACT:
            printf("%lld\n", firstNumber - secondNumber);
            break;
        case MULTIPLY:
            printf("%lld\n", firstNumber * secondNumber);
            break;
    }

    return 0;
}
