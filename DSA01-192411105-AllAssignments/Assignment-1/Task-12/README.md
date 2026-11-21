# Task 12 – Re-evaluate and Adapt the Design (Day-4 Design Challenge)

## Decision: MODIFY the design

Do not keep the original three-case switch unchanged. Extend the zone model and move fare data into a table. Keep `SmartCard` encapsulated and introduce a `MonthlyPass` that stores the two selected zones and allows unlimited trips in those zones while active.

## A. Impact analysis

- Add `Airport` to `enum class Zone`.
- Add Airport base fare Rs 60 (6000 paise).
- Replace the three-element fare table with four entries.
- Replace or update switch statements that assume only three zones.
- Add a weekend policy: 10% discount.
- The weekend discount does not combine with the 20% peak surcharge.
- Add `MonthlyPass` with two covered zones and validity dates.
- Update tests for every zone, weekend/peak combinations and pass coverage.

## B. Evaluate original design

A switch with three cases cannot calculate Airport fare without a new case. A SmartCard with private balance remains useful, but it needs a journey-payment method that checks whether a valid monthly pass covers the zone before deducting a fare. A pass must not accidentally deduct money for a covered trip.

Worked examples:
- Inner off-peak weekday: Rs 10.
- Inner peak weekday: Rs 12.
- Inner weekend (not peak-surcharged): Rs 9.
- Airport off-peak weekday: Rs 60.
- Airport weekend: Rs 54.
- A valid pass covering Inner and Middle makes trips in those zones free for the pass holder; Outer and Airport still use the fare rules.

## C. Revised implementation

See `Task12.cpp`. It uses a four-zone fare table, a mutually exclusive weekend/peak rule, an encapsulated card and a two-zone monthly pass. The example treats weekend discount as applying instead of peak surcharge, exactly as the changed requirement states. Pass validity is represented by a boolean in this small demonstration; a production version should check actual start/end dates and renewal.

## D. Evidence-based defence

The fare table makes adding another zone a data change rather than adding another switch branch. Separate pass logic avoids mixing subscription eligibility with fare arithmetic. Tests cover the new policy combinations. The trade-off is that a table needs safe zone-index validation, and a real pass requires date validation and secure passenger/card association.
