#include "StringCalculator.h"
#include <sstream>

// Helper function to calculate sum from tokens
static int calculateSumFromTokens(std::stringstream& ss) {
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        sum += std::stoi(token);
    }

    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    // If the input string is empty or "0", return 0
    if (numbers.empty() || numbers == "0") {
        return 0;
    }

    std::stringstream ss(numbers);
    return calculateSumFromTokens(ss);
}
