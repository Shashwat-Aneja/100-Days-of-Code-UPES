// Q78: To find the sum of the main diagonal elements for a square matrix.

/*
Sample Test Case:
Input:
3 3
1 2 3
4 5 6
7 8 9
Output:
15
*/

#include <stdio.h>

int main(void) {
    int n;
    int matrix[20][20];
    int diagonal_sum = 0;

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
        diagonal_sum += matrix[i][i];
    }

    printf("Sum of main diagonal elements: %d\n", diagonal_sum);

    return 0;
}
