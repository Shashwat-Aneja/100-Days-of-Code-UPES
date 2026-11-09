#include <stdio.h>

/*
 * Q138: Print all enum names and integer values using a loop.
 *
 * Sample Input: No input
 * Sample Output:
 * RED=0
 * YELLOW=1
 * GREEN=2
 *
 * Time Complexity: O(1), since the enumeration has three fixed values.
 * Space Complexity: O(1), since a fixed-size array and loop variable are used.
 */

typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLight;

int main(void)
{
    const char *names[] = {"RED", "YELLOW", "GREEN"};

    for (int value = RED; value <= GREEN; value++) {
        printf("%s=%d\n", names[value], value);
    }

    return 0;
}
