/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

Sample cases:
[1,3,3,4] -> 3
[1,2,2] -> 2
[0,4,1,1,5] -> 1

Input format: n followed by n integers. A hash table is used so each input element is examined once.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000000) return 1;
    size_t capacity = 1;
    while (capacity < (size_t)n * 4) capacity <<= 1;
    int *keys = malloc(capacity * sizeof *keys);
    unsigned char *used = calloc(capacity, sizeof *used);
    if (!keys || !used) { free(keys); free(used); return 1; }

    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) { free(keys); free(used); return 1; }
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
/* Expected O(n) time with hashing; O(n) auxiliary space. */
