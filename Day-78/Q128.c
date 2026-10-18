/*
Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.

Sample Test Case:
File: text.txt (Content: Welcome to C language)
Output:
Vowels: 8
Consonants: 10
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("text.txt");
        return 1;
    }

    unsigned long long vowels = 0;
    unsigned long long consonants = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha((unsigned char)ch)) {
            int lower = tolower((unsigned char)ch);

            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    if (ferror(file)) {
        fputs("Error while reading text.txt.\n", stderr);
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        fputs("Error while closing text.txt.\n", stderr);
        return 1;
    }

    printf("Vowels: %llu\n", vowels);
    printf("Consonants: %llu\n", consonants);
    return 0;
}

/*
Time Complexity: O(B), where B is the number of bytes in the file.
Auxiliary Space: O(1).
*/
