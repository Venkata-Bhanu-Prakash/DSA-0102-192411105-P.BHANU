# Task 10 – Compare Expectations with Execution

## Scale calculation

Use a sample fixed fare of Rs 10.00 (1000 paise) only to demonstrate accumulation. The total is:

| Journeys/day | Total rupees | Total paise |
|---:|---:|---:|
| 20,000 | Rs 200,000 | 20,000,000 |
| 500,000 | Rs 5,000,000 | 500,000,000 |
| 3,000,000 | Rs 30,000,000 | 3,000,000,000 |

A 32-bit signed `int` commonly has maximum 2,147,483,647, so the 3,000,000,000-paise total exceeds it. A `long long` can hold this total. The example uses a constant Rs 10 fare; actual totals depend on zone, peak periods and concessions.

`Task10.cpp` compares integer paise and double rupees and prints the limits and totals. Floating-point results may display tiny representation differences for decimal fractions. With `-Wall -Wextra`, warnings depend on compiler and code; common warnings include signed/unsigned comparisons and unused variables.

## Alternative accumulator types

- `int`: 4 bytes on common systems; overflows for the demonstrated paise total.
- `long long`: commonly 8 bytes; safely holds this total.
- `double`: commonly 8 bytes; broad range but not exact decimal money representation.

Each addition is O(1). The storage per accumulator is O(1).
