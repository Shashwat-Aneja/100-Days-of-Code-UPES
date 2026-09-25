// Q93: Check if two strings are anagrams of each other.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s1[1000], s2[1000];
    int freq1[256] = {0}, freq2[256] = {0};

    printf("Enter first string: ");
    if (fgets(s1, sizeof(s1), stdin) == NULL) return 1;

    printf("Enter second string: ");
    if (fgets(s2, sizeof(s2), stdin) == NULL) return 1;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != '\n' && !isspace((unsigned char)s1[i]))
            freq1[(unsigned char)tolower((unsigned char)s1[i])]++;
    }

    for (int i = 0; s2[i] != '\0'; i++) {
        if (s2[i] != '\n' && !isspace((unsigned char)s2[i]))
            freq2[(unsigned char)tolower((unsigned char)s2[i])]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq1[i] != freq2[i]) {
            printf("False\n");
            return 0;
        }
    }

    printf("True\n");
    return 0;
}
