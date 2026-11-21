# Task 9 – Implement and Test the Fare Logic

`Task9.cpp` tests all three zones in peak and off-peak periods, the four time boundaries, the exact Rs 50 remaining-balance boundary, invalid hour/zone values and a five-journey total. It prints expected and actual results.

Peak boundaries: 08:00 is peak, 10:00 is off-peak, 17:00 is peak and 20:00 is off-peak. A journey leaving exactly Rs 50 is accepted. Invalid input must be rejected without changing the card balance.

For t table-driven tests, runtime is O(t), and the test table uses O(t) space. Adding a boundary case means adding another row rather than writing a separate hand-coded test.
