#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& numbers) {
    // If the input string is empty or "0", return 0
    if (numbers.empty() || numbers == "0") {
        return 0;
    }

    std::stringstream ss(numbers);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        sum += std::stoi(token);
    }

    return sum;
}


