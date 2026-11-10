/*
 * Q139: Show that enums store integers by printing assigned values.
 *
 * Time complexity: O(1).
 * Auxiliary space complexity: O(1).
 */
#include <stdio.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main(void) {
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", SUCCESS, FAILURE, TIMEOUT);
    return 0;
}
