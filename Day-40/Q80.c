// Q80: Multiply two matrices.

/*
Sample Test Case:
Input:
2 3
1 2 3
4 5 6
3 2
7 8
9 10
11 12
Output:
58 64
139 154
*/

#include <stdio.h>

int main(void) {
    int rows1, cols1, rows2, cols2;
    int a[20][20], b[20][20], product[20][20];

    scanf("%d %d", &rows1, &cols1);

    if (rows1 < 1 || rows1 > 20 || cols1 < 1 || cols1 > 20) {
        printf("Invalid first matrix dimensions.\n");
        return 0;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d %d", &rows2, &cols2);

    if (rows2 < 1 || rows2 > 20 || cols2 < 1 || cols2 > 20) {
        printf("Invalid second matrix dimensions.\n");
        return 0;
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
