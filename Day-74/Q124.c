/*
Q124: Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

Sample: source.txt contains "Learning C File Handling"
Expected confirmation: File copied successfully to destination.txt
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char source[256], destination[256];
    if (scanf("%255s %255s", source, destination) != 2) return 1;
    if (strcmp(source, destination) == 0) {
        fputs("Source and destination must be different files.\n", stderr);
        return 1;
    }

    FILE *in = fopen(source, "rb");
    if (!in) {
        perror(source);
        return 1;
    }
    FILE *out = fopen(destination, "wb");
    if (!out) {
        perror(destination);
        fclose(in);
        return 1;
    }

    int ch, failed = 0;
    while ((ch = fgetc(in)) != EOF) {
        if (fputc(ch, out) == EOF) { failed = 1; break; }
    }
    if (ferror(in)) failed = 1;
    if (fclose(in) != 0) failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Error while copying file.\n", stderr);
        return 1;
    }
    printf("File copied successfully to %s\n", destination);
    return 0;
}
/* Time: O(B). Auxiliary space: O(1). */
