#include <iostream>
#include <string>

enum class Zone { Inner, Middle, Outer, Invalid };

constexpr long long MIN_BALANCE = 5000;

long long calculateFare(Zone zone, int hour) {
    if (hour < 0 || hour > 23) return -1;
    long long base = 0;
    switch (zone) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
        default: return -1;
    }
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? base + base * 20 / 100 : base;
}

int main() {
    struct Test { const char* name; Zone zone; int hour; long long expected; };
    Test tests[] = {
        {"Inner off-peak", Zone::Inner, 11, 1000},
        {"Middle off-peak", Zone::Middle, 11, 2000},
        {"Outer off-peak", Zone::Outer, 11, 3000},
        {"Inner peak", Zone::Inner, 8, 1200},
        {"Middle peak", Zone::Middle, 17, 2400},
        {"Outer peak", Zone::Outer, 19, 3600},
        {"08:00 peak", Zone::Inner, 8, 1200},
        {"10:00 off-peak", Zone::Inner, 10, 1000},
        {"17:00 peak", Zone::Inner, 17, 1200},
        {"20:00 off-peak", Zone::Inner, 20, 1000},
        {"Invalid hour", Zone::Inner, 24, -1},
        {"Unknown zone", Zone::Invalid, 9, -1}
    };

    int passed = 0;
    for (const Test& t : tests) {
        long long actual = calculateFare(t.zone, t.hour);
        bool ok = actual == t.expected;
        if (ok) ++passed;
        std::cout << t.name << ": expected " << t.expected
                  << ", actual " << actual << " -> "
                  << (ok ? "PASS" : "FAIL") << '\n';
    }
    std::cout << "Passed " << passed << " of "
              << sizeof(tests) / sizeof(tests[0]) << " tests\n";

    // Five-journey hand-calculated example: 1000 + 1200 + 2000 + 2400 + 3000 = 9600 paise.
    std::cout << "Five-journey total: " << 9600 << " paise (Rs 96.00)\n";
    std::cout << "Exact Rs 50 remaining: "
              << std::boolalpha << (6000 - 1000 >= MIN_BALANCE) << '\n';
}
