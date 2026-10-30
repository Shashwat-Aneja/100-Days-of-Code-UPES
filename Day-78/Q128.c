/*
 * Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
 *
 * Sample file (text.txt):
 * Welcome to C language
 *
 * Expected output:
 * Vowels: 8
 * Consonants: 10
 *
 * Time Complexity: O(n), where n is the number of characters in the file.
 * Space Complexity: O(1), because only counters and one character are stored.
 */
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open text.txt.\n");
        return 1;
    }

    unsigned long vowels = 0;
    unsigned long consonants = 0;
    int character;

    while ((character = fgetc(file)) != EOF)
    {
        if (isalpha((unsigned char)character))
        {
            int lower = tolower((unsigned char)character);

            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        /* Digits, spaces, and special characters are ignored. */
    }

    if (ferror(file))
    {
        printf("Error: Could not read text.txt.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Vowels: %lu\n", vowels);
    printf("Consonants: %lu\n", consonants);

    return 0;
}
