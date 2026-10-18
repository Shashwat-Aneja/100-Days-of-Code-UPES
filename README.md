# UPES 100 Days of Code

A collection of C solutions for the UPES 100 Days of Code challenge.

## Source of truth

Challenge questions must come from the published source:
[Basic Coding with C](https://maitysoumik.github.io/basic-coding-with-c/).

- Preserve the source's exact question wording and numbering.
- After Day 50, expect one question per day unless the source explicitly specifies otherwise.
- Do not invent future questions, add filler commits, or overwrite existing solution files.
- Add a new day's solution only after that day is actually published by the source.
- If the next day is not published or the source/repository is unavailable, make no commit and check again on the next scheduled run.
- Verify each new commit by fetching the committed file from GitHub.

## Repository structure

Solutions are grouped by challenge day (for example, `Day-64/Q114.c`). Each source file should include the exact problem statement in a comment, a complete beginner-friendly C implementation, sample-case handling, and time/space complexity notes where appropriate.

## Compile and run

Use a C compiler such as GCC:

```sh
gcc Day-64/Q114.c -std=c11 -Wall -Wextra -pedantic -o solution
./solution
```

Replace the source path with the solution you want to run.

## Publication status

As of October 18, 2026, the source website is reported to have published only 66 days. The next new day to check is **Day 67**, starting October 19, 2026. Do not add a Day 67 solution until the source publishes it. Existing repository files are left untouched.
