// Q76: Check if a matrix is symmetric.

/*
Sample Test Cases:
Input 1:
2 2
1 2
2 1
Output 1:
True

Input 2:
2 2
1 0
2 1
Output 2:
False
*/

#include <stdio.h>

int main(void) {
    int n;
    int matrix[20][20];
    int symmetric = 1;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) {
            break;
        }
    }

    if (symmetric) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
