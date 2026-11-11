/*
 * Q140: Define a struct with enum Gender and print person's gender.
 *
 * Time complexity: O(1), since the input is limited to a fixed-size word.
 * Auxiliary space complexity: O(1).
 */
#include <stdio.h>
#include <string.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    enum Gender gender;
};

int main(void) {
    char input[32];
    struct Person person;

    if (scanf("%31s", input) != 1) {
        return 1;
    }

    const char *value = input;
    if (strncmp(input, "Gender=", 7) == 0) {
        value = input + 7;
    }

    if (strcmp(value, "MALE") == 0) {
        person.gender = MALE;
    } else if (strcmp(value, "FEMALE") == 0) {
        person.gender = FEMALE;
    } else if (strcmp(value, "OTHER") == 0) {
        person.gender = OTHER;
    } else {
        puts("Invalid gender");
        return 1;
    }

    switch (person.gender) {
        case MALE:
            puts("Male");
            break;
        case FEMALE:
            puts("Female");
            break;
        case OTHER:
            puts("Other");
            break;
    }

    return 0;
}
