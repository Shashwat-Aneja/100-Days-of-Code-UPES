# Q110: Sliding Window Maximum Test Cases

Run these cases against `Q110.c`.

| Case | Array | k | Expected output | Purpose |
|---|---|---:|---|---|
| 1 | `[1, 2, 3, 1, 4, 5, 2, 3, 6]` | 3 | `3 3 4 5 5 5 6` | Standard example |
| 2 | `[5, 1, 3, 4, 2]` | 1 | `5 1 3 4 2` | Window size one |
| 3 | `[4, 4, 4, 4]` | 2 | `4 4 4` | Duplicate values |
| 4 | `[-8, -3, -6, -2, -5]` | 3 | `-3 -2 -2` | All-negative values |
| 5 | `[7, 2, 9, 1]` | 4 | `9` | Window equals array size |
| 6 | `[1, 2, 3, 4, 5]` | 2 | `2 3 4 5` | Increasing sequence |
| 7 | `[9, 7, 5, 3, 1]` | 3 | `9 7 5` | Decreasing sequence |

## Invalid-input checks

- Array size is zero or negative.
- Array element input contains non-integer text.
- `k` is zero or negative.
- `k` is greater than the array size.
- `k` is not an integer.

For invalid input, the program should report an error and exit without accessing the array out of bounds.
