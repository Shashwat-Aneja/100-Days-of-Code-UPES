/*
Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

Sample:
input.txt: Hello World
C programming
output.txt: HELLO WORLD
C PROGRAMMING
*/
#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in) {
        perror("input.txt");
        return 1;
    }
    FILE *out = fopen("output.txt", "w");
    if (!out) {
        perror("output.txt");
        fclose(in);
        return 1;
    }

    int ch, failed = 0;
    while ((ch = fgetc(in)) != EOF) {
        int converted = islower((unsigned char)ch)
            ? toupper((unsigned char)ch) : ch;
        if (fputc(converted, out) == EOF) { failed = 1; break; }
    }
    if (ferror(in)) failed = 1;
    if (fclose(in) != 0) failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Error converting file.\n", stderr);
        return 1;
    }
    puts("Conversion complete. Result written to output.txt");
    return 0;
}
/* Time: O(B). Auxiliary space: O(1). */
