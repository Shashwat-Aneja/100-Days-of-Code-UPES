/* Q26: Write a program to print numbers from 1 to n.
 * Time complexity: O(n).
 * Auxiliary space complexity: O(1).
 */
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            putchar(' ');
        }
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}
