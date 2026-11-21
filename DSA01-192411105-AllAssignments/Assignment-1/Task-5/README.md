# Task 5 – Write Correct Expressions with the Right Precedence

## Fare expressions

```cpp
bool peak = (hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20);
long long surcharge = peak ? basePaise * 20 / 100 : 0;
long long fare = basePaise + surcharge;
```

The parentheses make the two peak-hour windows clear. `&&` is evaluated before `||`; the conditional operator `?:` selects one of two values. Use integer paise.

The supplied scenario says students and senior citizens receive concessions but does not give the concession percentages or whether the concession is applied before/after surcharge. Those policy values must be confirmed rather than invented.

## Predicted output (before running)

```text
11 16
9 6 4
6 0
3 1 -3 -1
18
```

## Explanation

- `x + y * 2`: multiplication first, so 5 + 6 = 11. Parentheses in `(x + y) * 2` give 16.
- `x++ + ++y`: post-increment uses old x=5 then increments x to 6; pre-increment changes y from 3 to 4 and uses 4. Thus z=9.
- `x > y ? x : y` returns 6. `x % 4 * 2` is left-to-right for equal-precedence multiplicative operators: 6 % 4 * 2 = 4.
- Integer division truncates toward zero: 10/3=3 and -10/3=-3. Remainders are 1 and -1.
- Loop values added are 0, 3, 6, 9, giving 18.

`x++` yields the old value; `++x` yields the incremented value. Avoid `i = i++` because it is confusing and has historically had undefined/unspecified behaviour depending on language version and expression context; write `i++` or `++i` separately.

## Negative division and modulo

C++ integer division truncates toward zero. The remainder has the sign of the dividend: `-10 % 3` is `-1`.

## Lookup-table alternative

A `bool peak[24]` table uses 24 boolean elements (commonly 24 bytes) and performs O(1) indexed lookup. The expression version is also O(1) but evaluates comparisons. A table can be easier to maintain for irregular schedules, while a direct expression avoids the table storage.
