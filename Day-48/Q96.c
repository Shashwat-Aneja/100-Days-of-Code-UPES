// Q96: Reverse each word in a sentence without changing the word order.

/*
Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc
*/

#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    char sentence[1000];
    int start = -1;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    sentence[strcspn(sentence, "\n")] = '\0';

    for (int i = 0; ; i++) {
        if (sentence[i] != ' ' && sentence[i] != '\0' && start == -1) {
            start = i;
        }

        if ((sentence[i] == ' ' || sentence[i] == '\0') && start != -1) {
            reverseWord(&sentence[start], &sentence[i - 1]);
            start = -1;
        }

        if (sentence[i] == '\0') {
            break;
        }
    }

    printf("%s\n", sentence);

    return 0;
}
