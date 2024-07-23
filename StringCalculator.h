#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <stdexcept>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> tokenizeAndFilter(const std::string& numbers);
    std::string replaceNewlinesWithCommas(const std::string& numbers);
    std::vector<std::string> splitString(const std::string& str, char delimiter);
    std::vector<int> convertTokensToIntegers(const std::vector<std::string>& tokens);
    std::vector<int> filterNumbers(const std::vector<int>& numbers, int upperLimit);
    int calculateSum(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
