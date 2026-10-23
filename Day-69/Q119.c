/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

Input format: n, followed by n integers. Exactly one value is repeated.
The source page's sample test cases are not included in the provided text.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

static size_t hash_int(int value) {
    uint32_t x = (uint32_t)value;
    x ^= x >> 16;
    x *= UINT32_C(0x7feb352d);
    x ^= x >> 15;
    x *= UINT32_C(0x846ca68b);
    x ^= x >> 16;
    return (size_t)x;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 2 || n > 1000000) return 1;

    size_t capacity = 1;
    while (capacity < (size_t)n * 2) {
        if (capacity > SIZE_MAX / 2) return 1;
        capacity *= 2;
    }

    int *keys = malloc(capacity * sizeof *keys);
    unsigned char *used = calloc(capacity, sizeof *used);
    if (!keys || !used) {
        free(keys);
        free(used);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            free(keys);
            free(used);
            return 1;
        }

        size_t slot = hash_int(value) & (capacity - 1);
        while (used[slot] && keys[slot] != value)
            slot = (slot + 1) & (capacity - 1);

        if (used[slot]) {
            printf("%d\n", value);
            free(keys);
            free(used);
            return 0;
        }
        used[slot] = 1;
        keys[slot] = value;
    }

    puts("-1");
    free(keys);
    free(used);
    return 0;
}
/* Expected time: O(n). Auxiliary space: O(n) for the hash table. */
