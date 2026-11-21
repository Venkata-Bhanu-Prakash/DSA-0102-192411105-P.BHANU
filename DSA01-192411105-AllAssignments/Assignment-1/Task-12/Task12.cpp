#include <array>
#include <iostream>
#include <string>

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };

constexpr std::array<long long, 4> BASE_FARE_PAISE = {
    1000, 2000, 3000, 6000
};

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;
    bool active;

public:
    MonthlyPass(Zone a, Zone b, bool isActive)
        : firstZone(a), secondZone(b), active(isActive) {}

    bool covers(Zone z) const {
        return active && (z == firstZone || z == secondZone);
    }
};

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long balance) : balancePaise(balance) {}

    bool pay(long long farePaise) {
        constexpr long long MIN_BALANCE = 5000;
        if (farePaise < 0 || balancePaise - farePaise < MIN_BALANCE)
            return false;
        balancePaise -= farePaise;
        return true;
    }

    long long balance() const { return balancePaise; }
};

long long calculateFare(Zone zone, int hour, bool weekend) {
    int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(BASE_FARE_PAISE.size()))
        return -1;
    if (hour < 0 || hour > 23) return -1;

    long long base = BASE_FARE_PAISE[static_cast<std::size_t>(index)];
    bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);

    // Weekend discount replaces peak surcharge; they never combine.
    if (weekend) return base * 90 / 100;
    if (peak) return base * 120 / 100;
    return base;
}

int main() {
    SmartCard card(20000); // Rs 200.00
    MonthlyPass pass(Zone::Inner, Zone::Middle, true);

    struct Trip { Zone zone; int hour; bool weekend; const char* label; };
    Trip trips[] = {
        {Zone::Inner, 9, false, "Inner weekday peak"},
        {Zone::Inner, 9, true, "Inner weekend"},
        {Zone::Airport, 12, false, "Airport weekday"},
        {Zone::Middle, 18, true, "Middle weekend"}
    };

    for (const Trip& trip : trips) {
        long long fare = pass.covers(trip.zone)
            ? 0 : calculateFare(trip.zone, trip.hour, trip.weekend);

        bool accepted = fare >= 0 && (fare == 0 || card.pay(fare));
        std::cout << trip.label << ": ";
        if (accepted)
            std::cout << "fare " << fare << " paise";
        else
            std::cout << "journey denied";
        std::cout << ", balance " << card.balance() << " paise\n";
    }
}
