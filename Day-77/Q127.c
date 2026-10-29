/*
Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

Sample test case from the source:
Input file (input.txt):
Hello World
C programming

Output file (output.txt):
HELLO WORLD
C PROGRAMMING

Explanation: All lowercase letters in input.txt are converted to uppercase using character manipulation before writing to output.txt.

Time Complexity: O(n), where n is the number of characters in input.txt.
Space Complexity: O(1), because the program processes one character at a time.
*/
#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        fprintf(stderr, "Error: Could not open input.txt for reading.\n");
        return 1;
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        fprintf(stderr, "Error: Could not open output.txt for writing.\n");
        fclose(input);
        return 1;
    }

    int ch;
    int status = 0;

    while ((ch = fgetc(input)) != EOF) {
        if (fputc(toupper((unsigned char)ch), output) == EOF) {
            fprintf(stderr, "Error: Could not write to output.txt.\n");
            status = 1;
            break;
        }
    }

    if (ferror(input)) {
        fprintf(stderr, "Error: Could not read input.txt completely.\n");
        status = 1;
    }

    if (fclose(input) == EOF) {
        fprintf(stderr, "Error: Could not close input.txt correctly.\n");
        status = 1;
    }

    if (fclose(output) == EOF) {
        fprintf(stderr, "Error: Could not finish writing output.txt.\n");
        status = 1;
    }

    return status;
}
