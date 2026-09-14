// Q71: Read and print a matrix.
#include <stdio.h>

int main(void) {
    int matrix[20][20], rows, cols, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    if (rows < 1 || rows > 20 || cols < 1 || cols > 20) return 0;

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    printf("Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
