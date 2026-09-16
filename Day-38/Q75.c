// Q75: Add two matrices.

/*
Sample Test Cases:
Input 1:
2 2
1 2
3 4
2 2
5 6
7 8
Output 1:
6 8
10 12
*/

#include <stdio.h>

int main(void) {
    int rows1, cols1, rows2, cols2;
    int a[20][20], b[20][20], sum[20][20];

    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    if (rows1 < 1 || rows1 > 20 || cols1 < 1 || cols1 > 20) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (rows2 < 1 || rows2 > 20 || cols2 < 1 || cols2 > 20) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices cannot be added (different sizes).\n");
        return 0;
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Sum of matrices:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("%d", sum[i][j]);
            if (j < cols1 - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
