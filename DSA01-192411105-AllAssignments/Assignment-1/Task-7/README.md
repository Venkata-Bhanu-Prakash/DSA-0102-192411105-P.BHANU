# Task 7 – From Procedural to Object-Oriented

Two versions are included in `Task7.cpp`:

- Procedural: a balance variable is passed to free functions. Every caller must use those functions correctly.
- OOP: `SmartCard` stores its balance privately. `canTravel()` checks the remaining Rs 50 rule and `deduct()` changes the balance only when valid.

Both versions use O(1) time for one fare check and O(1) memory per card. Making the balance public does not improve time or memory, but any code could set it negative or bypass the minimum-balance rule. Private data plus validated methods protects the invariant. If the minimum balance changes, a centralized constant is updated once.
