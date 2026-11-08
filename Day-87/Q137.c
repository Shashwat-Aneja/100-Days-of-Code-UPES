#include <stdio.h>
#include <string.h>

/*
 * Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
 *
 * Sample Input:
 * GUEST
 *
 * Sample Output:
 * Welcome Guest!
 *
 * Time Complexity: O(1), because the input buffer has a fixed maximum size.
 * Space Complexity: O(1), because only a fixed-size character array and an enum are used.
 */

typedef enum {
    ADMIN,
    USER,
    GUEST
} UserRole;

int main(void)
{
    char roleInput[16];
    UserRole role;

    if (scanf("%15s", roleInput) != 1) {
        fprintf(stderr, "Error: Could not read the user role.\n");
        return 1;
    }

    if (strcmp(roleInput, "ADMIN") == 0) {
        role = ADMIN;
    } else if (strcmp(roleInput, "USER") == 0) {
        role = USER;
    } else if (strcmp(roleInput, "GUEST") == 0) {
        role = GUEST;
    } else {
        printf("Invalid role.\n");
        return 1;
    }

    switch (role) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
    }

    return 0;
}
