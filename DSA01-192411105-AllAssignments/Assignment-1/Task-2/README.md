# Task 2 – Tokens, Keywords, Identifiers and Constants

## Five token categories

- **Keywords:** `int`, `class`, `if`, `return`, `switch`.
- **Identifiers:** `SmartCard`, `balancePaise`, `calculateFare`.
- **Constants/literals:** `5000`, `20`, `true`, `'A'`.
- **Operators:** `+`, `-`, `*`, `/`, `==`, `&&`.
- **Punctuators:** `{ } ( ) ; , [ ]`.

## Recommended constants

```cpp
constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long BASE_FARE_PAISE[] = {1000, 2000, 3000};
```

`constexpr` is preferred for compile-time values such as the fare table. `const` prevents modification after initialization but is not always required to be a compile-time constant. `#define` is a preprocessor substitution and has no C++ type checking or normal scope.

## Zones

```cpp
enum class Zone { Inner, Middle, Outer };
```

`enum class` is safer than an unscoped `enum`: values are scoped (`Zone::Inner`) and do not implicitly convert to integers.

## Identifier conventions

Use meaningful names, begin identifiers with a letter or underscore, do not use spaces, do not use keywords, and keep a consistent style such as `balancePaise` for variables and `MIN_BALANCE_PAISE` for constants.

## Macro comparison

A macro such as `#define PEAK_RATE 20` performs textual substitution. It has no type or enum scope and can cause unexpected substitution. `constexpr` has a type and follows C++ scope and type-checking rules. Neither normally requires a separate runtime memory location, and neither changes the O(1) running time of a fare calculation.
