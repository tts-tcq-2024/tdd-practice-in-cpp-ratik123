#include "StringCalculator.h"
#include <sstream>
#include <vector>
#include <regex>

// Helper function to split the input string into tokens and check for negatives
static std::vector<int> tokenizeAndCheckForNegatives(const std::string& numbers) {
    // Replace newlines with commas for consistent delimiter processing
    std::string modifiedNumbers = std::regex_replace(numbers, std::regex("[\n]"), ",");
    
    std::stringstream ss(modifiedNumbers);
    std::string token;
    std::vector<int> tokens;

    while (std::getline(ss, token, ',')) {
        int num = std::stoi(token);
        if (num < 0) {
            throw std::runtime_error("Negative numbers not allowed: " + token);
        }
        tokens.push_back(num);
    }

    return tokens;
}

// Helper function to calculate the sum of integers
static int calculateSum(const std::vector<int>& tokens) {
    int sum = 0;
    for (int num : tokens) {
        sum += num;
    }
    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty() || numbers == "0") {
        return 0;
    }

    std::vector<int> tokens = tokenizeAndCheckForNegatives(numbers);
    return calculateSum(tokens);
}
