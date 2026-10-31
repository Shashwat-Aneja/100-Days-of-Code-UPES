/*
 * Q129: A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
 *
 * Sample file (numbers.txt):
 * 10 20 30 40 50
 *
 * Expected output:
 * Sum = 150
 * Average = 30.00
 *
 * Time Complexity: O(n), where n is the number of integers in the file.
 * Space Complexity: O(1), because only the current number, sum, and count are stored.
 */
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open numbers.txt.\n");
        return 1;
    }

    long long number;
    long long sum = 0;
    unsigned long long count = 0;
    int scanResult;

    while ((scanResult = fscanf(file, "%lld", &number)) == 1)
    {
        sum += number;
        count++;
    }

    if (ferror(file))
    {
        printf("Error: Could not read numbers.txt.\n");
        fclose(file);
        return 1;
    }

    if (scanResult != EOF)
    {
        printf("Error: numbers.txt must contain only integers.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    if (count == 0)
    {
        printf("Error: numbers.txt does not contain any integers.\n");
        return 1;
    }

    double average = (double)sum / (double)count;

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
