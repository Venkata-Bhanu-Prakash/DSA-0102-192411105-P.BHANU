#include <iostream>

constexpr long long MIN_BALANCE = 5000;

bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= MIN_BALANCE;
}

bool proceduralDeduct(long long& balance, long long fare) {
    if (!proceduralCanTravel(balance, fare)) return false;
    balance -= fare;
    return true;
}

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long initialPaise) : balancePaise(initialPaise) {}

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 && balancePaise - farePaise >= MIN_BALANCE;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise -= farePaise;
        return true;
    }

    long long balance() const { return balancePaise; }
};

int main() {
    long long proceduralBalance = 10000;
    std::cout << "Procedural accepted: "
              << std::boolalpha << proceduralDeduct(proceduralBalance, 3000)
              << ", balance: " << proceduralBalance << " paise\n";

    SmartCard card(10000);
    std::cout << "OOP accepted: " << card.deduct(3000)
              << ", balance: " << card.balance() << " paise\n";
}
