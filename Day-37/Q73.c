// Q73: Find the sum of each row of a matrix and store it in an array.
#include <stdio.h>

int main(void) {
    int matrix[20][20], rowSum[20];
    int rows, cols, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 20 || cols < 1 || cols > 20) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        rowSum[i] = 0;
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            rowSum[i] += matrix[i][j];
        }
    }

    printf("Row sums: ");
    for (i = 0; i < rows; i++) {
        printf("%d", rowSum[i]);
        if (i < rows - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
