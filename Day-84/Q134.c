/*
Q134: Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.

Sample Test Case:
Input: FAILURE
Output: Operation failed
*/

#include <stdio.h>
#include <string.h>

typedef enum {
    SUCCESS,
    FAILURE,
    TIMEOUT
} OperationStatus;

int main(void)
{
    char input[20];
    OperationStatus status;

    if (scanf("%19s", input) != 1) {
        fprintf(stderr, "Error: Unable to read operation status.\n");
        return 1;
    }

    if (strcmp(input, "SUCCESS") == 0) {
        status = SUCCESS;
    } else if (strcmp(input, "FAILURE") == 0) {
        status = FAILURE;
    } else if (strcmp(input, "TIMEOUT") == 0) {
        status = TIMEOUT;
    } else {
        printf("Invalid status\n");
        return 0;
    }

    switch (status) {
        case SUCCESS:
            printf("Operation successful\n");
            break;
        case FAILURE:
            printf("Operation failed\n");
            break;
        case TIMEOUT:
            printf("Operation timed out\n");
            break;
    }

    return 0;
}

/*
Time Complexity: O(1), because the input buffer and number of enum values are fixed.
Space Complexity: O(1), because only a fixed-size character array and one enum variable are used.
*/
