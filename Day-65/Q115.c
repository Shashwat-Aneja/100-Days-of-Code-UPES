// Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

/*
Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100001];
    char t[100001];

    if (scanf("%100000s %100000s", s, t) != 2) {
        return 1;
    }

    if (strlen(s) != strlen(t)) {
        printf("Not Anagram\n");
        return 0;
    }

    int frequency[26] = {0};

    for (size_t i = 0; s[i] != '\0'; i++) {
        if (s[i] < 'a' || s[i] > 'z' ||
            t[i] < 'a' || t[i] > 'z') {
            printf("Not Anagram\n");
            return 0;
        }

        frequency[s[i] - 'a']++;
        frequency[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");
    return 0;
}

/*
Time Complexity: O(n), where n is the length of each string.
Auxiliary Space: O(1), because the frequency array always contains 26 entries.
*/
