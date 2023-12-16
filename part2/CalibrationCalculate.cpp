#include "CalibrationCalculate.h"

#include <string>
#include <vector>
#include <map>

int CalibrationCalculate::calculate(const std::vector<std::string> calibrationDocument) {
    int sum = 0;

    // Calculating the sum of calibration values
    #pragma omp parallel for reduction(+:sum)
    for (const auto& line : calibrationDocument) {
        int calibrationValue = extractCalibrationValue(line);
        sum += calibrationValue;
    }

    return sum;
}

int CalibrationCalculate::extractCalibrationValue(const std::string& line) {
    std::map<std::string, int> digitMap = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    int firstDigit = 0;
    int lastDigit = 0;

    //search for the first digit
    for (int i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {
            firstDigit = line[i] - '0';
            break;
        }
        //check if its a word in the map
        for (auto& x : digitMap) {
            if (line.length() - i > x.first.length()){
                for (int j = 0; j < x.first.length(); j++) {
                    if (line[i + j] != x.first[j]) {
                        break;
                    }
                    if (j == x.first.length() - 1) {
                        firstDigit = x.second;
                        break;
                    }
                }
            }
        }
        if (firstDigit != 0) {
            break;
        }
    }
    //search for the last digit
    for (int i = line.length() - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            lastDigit = line[i] - '0';
            break;
        }
        //check if its a word in the map    
        for (auto& x : digitMap) {
            if (i + 1 > x.first.length()) {
                for (int j = 0; j < x.first.length(); j++) {
                    if (line[i - j] != x.first[x.first.length() - 1 - j]) {
                        break;
                    }
                    if (j == x.first.length() - 1) {
                        lastDigit = x.second;
                        break;
                    }
                }
            }
        }
        if (lastDigit != 0) {
            break;
        }
    }

    return firstDigit * 10 + lastDigit;
}