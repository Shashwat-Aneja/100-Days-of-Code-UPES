/*
Q133: Create an enum for months and print how many days each month has.

Sample Test Case:
Input:
FEB
Output:
28 or 29 days

Time Complexity: O(L), where L is the length of the month name.
Space Complexity: O(1), using a fixed-size input buffer.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
} Month;

static int parseMonth(const char *input, Month *month)
{
    char normalized[20];
    size_t length = strlen(input);

    if (length >= sizeof(normalized)) {
        return 0;
    }

    for (size_t i = 0; i < length; i++) {
        normalized[i] = (char)toupper((unsigned char)input[i]);
    }
    normalized[length] = '\0';

    static const struct {
        const char *abbreviation;
        const char *fullName;
        Month value;
    } months[] = {
        {"JAN", "JANUARY", JAN},
        {"FEB", "FEBRUARY", FEB},
        {"MAR", "MARCH", MAR},
        {"APR", "APRIL", APR},
        {"MAY", "MAY", MAY},
        {"JUN", "JUNE", JUN},
        {"JUL", "JULY", JUL},
        {"AUG", "AUGUST", AUG},
        {"SEP", "SEPTEMBER", SEP},
        {"OCT", "OCTOBER", OCT},
        {"NOV", "NOVEMBER", NOV},
        {"DEC", "DECEMBER", DEC}
    };

    for (size_t i = 0; i < sizeof(months) / sizeof(months[0]); i++) {
        if (strcmp(normalized, months[i].abbreviation) == 0 ||
            strcmp(normalized, months[i].fullName) == 0) {
            *month = months[i].value;
            return 1;
        }
    }

    return 0;
}

static void printDays(Month month)
{
    switch (month) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            puts("31 days");
            break;

        case APR:
        case JUN:
        case SEP:
        case NOV:
            puts("30 days");
            break;

        case FEB:
            puts("28 or 29 days");
            break;

        default:
            puts("Invalid month");
            break;
    }
}

int main(void)
{
    char input[20];
    Month month;

    if (scanf("%19s", input) != 1) {
        return 1;
    }

    if (!parseMonth(input, &month)) {
        puts("Invalid month");
        return 1;
    }

    printDays(month);
    return 0;
}
