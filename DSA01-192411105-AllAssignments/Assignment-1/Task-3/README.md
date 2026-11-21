# Task 3 – Choose Data Types and Check Type Compatibility

## Data type selection

| Value | Suggested type | Reason |
|---|---|---|
| Fare and card balance | `long long` paise | exact integer money and safe totals |
| Peak flag | `bool` | true/false value |
| Hour | `int` | values 0–23 |
| Zone | `enum class Zone` | named, type-safe categories |
| Daily journey count | `long long` | supports millions and larger totals |
| Passenger/card ID | `string` | identifiers may contain letters or leading zeroes |
| Single character code | `char` | one character |
| Calculated display amount | `double` only for display if needed | never use as stored money |

Exact `sizeof` values are implementation-dependent. On a typical 64-bit g++ system, `sizeof(int)` is commonly 4, `sizeof(long long)` 8, `sizeof(double)` 8, `sizeof(bool)` 1 and `sizeof(char)` 1. Confirm on the target compiler with `sizeof`.

## Why integer paise?

Rs 10.01 is stored as 1001 paise. Integer addition and percentage calculations with a defined rounding rule avoid binary floating-point representation errors. For a 20% surcharge, calculate `basePaise * 20 / 100`; all given base fares are divisible so the result is exact.

## Type compatibility

In `double x = 7 / 2;`, integer division happens first, producing 3, then it converts to 3.0. In `double x = 7.0 / 2;`, the result is 3.5. A `bool` used in arithmetic converts to 0 or 1; an integer assigned to `bool` becomes false only for zero.

## Range and daily total

Use `<climits>` and `LLONG_MAX`/`INT_MAX` to inspect limits. Even if each journey costs at most a few thousand paise, millions of journeys can exceed the safe range of a 32-bit `int` depending on the exact total. `long long` is the safer accumulator.

## Alternative: double rupees

A `double` usually occupies 8 bytes and an integer `long long` usually occupies 8 bytes. Addition is O(1) for both. But binary floating-point cannot represent many decimal fractions exactly; repeated additions can accumulate small rounding differences. Integer paise provides exact smallest-unit accounting, provided overflow is checked.
