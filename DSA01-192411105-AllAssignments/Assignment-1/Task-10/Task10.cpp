#include <climits>
#include <iomanip>
#include <iostream>

int main() {
    const long long paisePerJourney = 1000; // Rs 10.00 demonstration fare
    const long long counts[] = {20000, 500000, 3000000};

    std::cout << "INT_MAX = " << INT_MAX << '\n';
    std::cout << std::fixed << std::setprecision(2);

    for (long long n : counts) {
        long long totalPaise = n * paisePerJourney;
        double totalRupees = static_cast<double>(n) * 10.00;
        std::cout << n << " journeys: "
                  << totalPaise << " paise, Rs "
                  << static_cast<double>(totalPaise) / 100.0
                  << " (double Rs " << totalRupees << ")\n";
    }

    std::cout << "3,000,000 journeys at 1000 paise = 3,000,000,000 paise\n";
    std::cout << "This exceeds the common 32-bit signed int maximum.\n";
}
