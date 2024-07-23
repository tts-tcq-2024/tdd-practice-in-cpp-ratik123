#include "StringCalculator.h"
#include <sstream>
#include <regex>

static const int UPPER_LIMIT = 1000;

std::string StringCalculator::replaceNewlinesWithCommas(const std::string& numbers) {
    return std::regex_replace(numbers, std::regex("[\n]"), ",");
}

std::vector<std::string> StringCalculator::splitString(const std::string& str, char delimiter) {
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<int> StringCalculator::convertTokensToIntegers(const std::vector<std::string>& tokens) {
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

std::vector<int> StringCalculator::filterNumbers(const std::vector<int>& numbers, int upperLimit) {
    std::vector<int> filteredNumbers;

    for (int num : numbers) {
        if (num <= upperLimit) {
            filteredNumbers.push_back(num);
        }
    }

    return filteredNumbers;
}

int StringCalculator::calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

std::vector<int> StringCalculator::tokenizeAndFilter(const std::string& numbers) {
    std::string delimiter = ",";
    std::string modifiedNumbers = numbers;

    if (numbers.substr(0, 2) == "//") {
        size_t delimiterPos = numbers.find('\n');
        delimiter = numbers.substr(2, delimiterPos - 2);
        modifiedNumbers = numbers.substr(delimiterPos + 1);
    }

    modifiedNumbers = replaceNewlinesWithCommas(modifiedNumbers);
    std::vector<std::string> tokens = splitString(modifiedNumbers, delimiter[0]);
    std::vector<int> integers = convertTokensToIntegers(tokens);
    return filterNumbers(integers, UPPER_LIMIT);
}

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty() || numbers == "0") {
        return 0;
    }

    std::vector<int> tokens = tokenizeAndFilter(numbers);
    return calculateSum(tokens);
}
