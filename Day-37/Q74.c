// Q74: Find the transpose of a matrix.
#include <stdio.h>

int main(void) {
    int matrix[20][20];
    int rows, cols, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > 20 || cols < 1 || cols > 20) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Transpose:\n");
    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            printf("%d", matrix[i][j]);
            if (i < rows - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
