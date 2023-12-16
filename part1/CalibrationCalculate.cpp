#include "CalibrationCalculate.h"

#include <algorithm>

int CalibrationCalculate::calculate(const std::vector<std::string> calibrationDocument) {
    int sum = 0;

    // Calculating the sum of calibration values
    #pragma omp parallel for reduction(+:sum)
    #pragma unroll
    for (const auto& line : calibrationDocument) {
        int calibrationValue = extractCalibrationValue(line);
        sum += calibrationValue;
    }

    return sum;
}

int CalibrationCalculate::extractCalibrationValue(const std::string& line) {
    //find the first digit in the string
    auto first = std::find_if(line.begin(), line.end(), ::isdigit);
    //find the last digit in the string
    auto last = std::find_if(line.rbegin(), line.rend(), ::isdigit);

    // Converting characters to digits and forming a two-digit number
    int firstDigit = std::stoi(std::string(1, *first));
    int lastDigit = std::stoi(std::string(1, *last));

    return firstDigit * 10 + lastDigit;
}