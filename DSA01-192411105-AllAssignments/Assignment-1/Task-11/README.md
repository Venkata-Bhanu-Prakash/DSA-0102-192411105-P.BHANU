# Task 11 – Recommend and Defend the Final Design

## Recommendation

Retain the object-oriented design, but make fare rules and policies centralized and configurable. Use:

- `enum class Zone` for type-safe zones.
- `long long` integer paise for balances, fares and network totals.
- `constexpr` constants for fixed policy values in the initial version.
- `SmartCard` with a private balance and validated `canTravel()` / `deduct()` methods.
- `FareTable` or a centralized fare service to own zone fares and surcharge calculations.
- Unit tests for peak boundaries, exact minimum balance, invalid input and large totals.

A fare revision should update one fare table/configuration source and rerun the tests. The design is O(1) per fare lookup and O(1) per card state; processing J journeys is O(J).

## Limitations

The original problem does not state the exact student/senior concession percentages or rounding policy. These must be specified by the metro authority. The original three-zone switch also requires code changes when a new zone is added.

## Configuration-file alternative

Reading z fares at startup takes O(z) startup time and O(z) memory. It avoids recompiling for every fare revision, but the program must validate the file and handle missing or invalid entries. For a small fixed table, compile-time constants are simpler; for frequent policy updates, validated configuration is more flexible.
