# Task 8 – Read and Print Data Safely

`Task8.cpp` demonstrates safe numeric input. If extraction fails, it checks `cin.fail()`, calls `cin.clear()` to reset the error state and ignores the rest of the invalid line. It validates the hour range and formats paise as rupees with two decimal digits.

`std::getline()` followed by `std::stoi()` is an alternative. It reads a whole line and can detect invalid text using `try/catch` (and the parsed character count should be checked to reject trailing junk). Processing a line of length L is O(L), and the line buffer uses O(L) space. Direct `cin >>` is convenient for token input; getline gives better control over line-based recovery.
