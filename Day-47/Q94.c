// Q94: Find the longest word in a sentence.

#include <stdio.h>
#include <string.h>

int main(void) {
    char sentence[1000];
    char longest[1000] = "";
    char current[1000];
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) return 1;

    while (sentence[i] != '\0') {
        if (sentence[i] != ' ' && sentence[i] != '\t' &&
            sentence[i] != '\n' && sentence[i] != '\r') {
            current[j++] = sentence[i];
        } else if (j > 0) {
            current[j] = '\0';
            if (strlen(current) > strlen(longest))
                strcpy(longest, current);
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        current[j] = '\0';
        if (strlen(current) > strlen(longest))
            strcpy(longest, current);
    }

    if (strlen(longest) > 0)
        printf("Longest word: %s\n", longest);
    else
        printf("No word found.\n");

    return 0;
}
