// Q79: Perform diagonal traversal of a matrix.

/*
Sample Test Case:
Input:
3 3
1 2 3
4 5 6
7 8 9
Output:
1 2 4 7 5 3 6 8 9
*/

#include <stdio.h>

int main(void) {
    int rows, cols;
    int matrix[20][20];
    int first = 1;

    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 20 || cols < 1 || cols > 20) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Traverse diagonals in the order of increasing i + j.
       Even-numbered diagonals are traversed upward, and odd-numbered
       diagonals are traversed downward. */
    for (int diagonal = 0; diagonal <= rows + cols - 2; diagonal++) {
        int row_start = diagonal < rows ? diagonal : rows - 1;
        int row_end = diagonal - cols + 1 > 0 ? diagonal - cols + 1 : 0;

        if (diagonal % 2 == 0) {
            for (int i = row_start; i >= row_end; i--) {
                int j = diagonal - i;
                if (!first) {
                    printf(" ");
                }
                printf("%d", matrix[i][j]);
                first = 0;
            }
        } else {
            for (int i = row_end; i <= row_start; i++) {
                int j = diagonal - i;
                if (!first) {
                    printf(" ");
                }
                printf("%d", matrix[i][j]);
                first = 0;
            }
        }
    }

    printf("\n");
    return 0;
}
