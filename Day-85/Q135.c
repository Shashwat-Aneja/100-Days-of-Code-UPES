/*
 * Q135: Assign explicit values starting from 10 and print them.
 *
 * Sample:
 * Input: No input
 * Output:
 * A=10
 * B=11
 * C=12
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#include <stdio.h>

enum LetterValue {
    A = 10,
    B,
    C
};

int main(void)
{
    printf("A=%d\n", A);
    printf("B=%d\n", B);
    printf("C=%d\n", C);

    return 0;
}
