#include "StringCalculator.h"
#include <sstream>
#include <vector>
#include <regex>

// Helper function to replace newlines with commas
static std::string replaceNewlinesWithCommas(const std::string& numbers) {
    return std::regex_replace(numbers, std::regex("[\n]"), ",");
}

// Helper function to split the input string into tokens
static std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

// Helper function to convert tokens to integers and check for negatives
static std::vector<int> convertTokensToIntegers(const std::vector<std::string>& tokens) {
    std::vector<int> integers;

    for (const std::string& token : tokens) {
        int num = std::stoi(token);
        if (num < 0) {
            throw std::runtime_error("Negative numbers not allowed: " + token);
        }
        integers.push_back(num);
    }

    return integers;
}

// Helper function to filter out numbers greater than the upper limit
static std::vector<int> filterNumbers(const std::vector<int>& numbers, int upperLimit) {
    std::vector<int> filteredNumbers;

    for (int num : numbers) {
        if (num <= upperLimit) {
            filteredNumbers.push_back(num);
        }
    }

    return filteredNumbers;
}

// Helper function to calculate the sum of integers
static int calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty() || numbers == "0") {
        return 0;
    }

    std::string modifiedNumbers = replaceNewlinesWithCommas(numbers);
    std::vector<std::string> tokens = splitString(modifiedNumbers, ',');
    std::vector<int> integers = convertTokensToIntegers(tokens);
    std::vector<int> filteredIntegers = filterNumbers(integers, 1000);

    return calculateSum(filteredIntegers);
}
