// Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

/*
Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    size_t capacity = 128;
    size_t length = 0;
    char *input = malloc(capacity);

    if (input == NULL) {
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length + 1 >= capacity) {
            if (capacity > ((size_t)-1) / 2) {
                free(input);
                return 1;
            }

            size_t newCapacity = capacity * 2;
            char *newInput = realloc(input, newCapacity);

            if (newInput == NULL) {
                free(input);
                return 1;
            }

            input = newInput;
            capacity = newCapacity;
        }

        input[length++] = (char)ch;
    }

    input[length] = '\0';

    char *start = input;

    while (*start != '\0' && isspace((unsigned char)*start)) {
        start++;
    }

    char *firstQuote = strchr(start, '"');

    if (firstQuote != NULL) {
        char *lastQuote = strrchr(firstQuote + 1, '"');

        if (lastQuote != NULL) {
            *lastQuote = '\0';
            start = firstQuote + 1;
        }
    } else {
        char *equals = strchr(start, '=');

        if (equals != NULL) {
            start = equals + 1;

            while (*start != '\0' && isspace((unsigned char)*start)) {
                start++;
            }
        }

        char *end = start + strlen(start);

        while (end > start && isspace((unsigned char)end[-1])) {
            *--end = '\0';
        }
    }

    int lastSeen[256];

    for (int i = 0; i < 256; i++) {
        lastSeen[i] = -1;
    }

    size_t left = 0;
    size_t maxLength = 0;
    size_t stringLength = strlen(start);

    for (size_t right = 0; right < stringLength; right++) {
        unsigned char current = (unsigned char)start[right];

        if (lastSeen[current] >= 0 && (size_t)lastSeen[current] >= left) {
            left = (size_t)lastSeen[current] + 1;
        }

        lastSeen[current] = (int)right;

        size_t windowLength = right - left + 1;

        if (windowLength > maxLength) {
            maxLength = windowLength;
        }
    }

    printf("%zu\n", maxLength);

    free(input);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) for the input string and O(1) auxiliary space for the fixed 256-entry last-seen table.
*/
