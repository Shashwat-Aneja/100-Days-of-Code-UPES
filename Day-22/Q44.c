// Q44: Find the sum of the series 1 + 3/4 + 5/6 + 7/8 + ... for n terms.
#include <stdio.h>

int main(void) {
    int n, i;
    double sum = 0.0;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += (double)(2 * i - 1) / (2 * i);
    }

    printf("Sum of series = %.4f\n", sum);
    return 0;
}
