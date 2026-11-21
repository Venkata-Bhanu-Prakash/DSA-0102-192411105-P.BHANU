# Task 4 – Control Implicit Conversions

## Predicted output (before running)

```text
3 3.5
C 68
1 true
s >= u
```

## Explanation

1. `a / b` is integer division: 7 / 2 gives 3, then converts to `double`. The explicit cast makes the second division floating-point and gives 3.5.
2. `'A' + 2` promotes the character to an integer and produces the character `C`. In `ch + 1`, `char` is promoted to `int`; the ASCII-compatible value is 68 on the usual execution character set.
3. Integer 5 converts to `bool true`. Default stream formatting prints `1`; `std::boolalpha` prints `true`.
4. Comparing signed `-1` with unsigned `1` converts the signed value to unsigned. The converted value is very large, so the expression `s < u` is false.

Compile with `g++ -std=c++17 -Wall -Wextra Task4.cpp -o Task4` and run it to verify the prediction.

## Safer conversions

Use braces for initialization, e.g. `int hour{8};`, because narrowing such as `int x{3.7};` is rejected. Use `static_cast<double>(a)` when floating-point division is intended. Validate signed values before converting to unsigned.

## Alternative concept

Explicit casts make intended conversions visible and brace initialization catches narrowing at compile time. They do not normally change the O(1) time or storage size of the operations. They improve reviewability and can move certain mistakes from runtime surprises to compile-time errors.
