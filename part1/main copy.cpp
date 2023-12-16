#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int extractCalibrationValue(const std::string& line) {
    auto first = std::find_if(line.begin(), line.end(), ::isdigit);
    auto last = std::find_if(line.rbegin(), line.rend(), ::isdigit);

    int firstDigit = std::stoi(std::string(1, *first));
    int lastDigit = std::stoi(std::string(1, *last));

    return firstDigit * 10 + lastDigit;
}

int main() {
    std::vector<std::string> calibrationDocument = {
        "1abc2",
        "pqr3stu8vwx",
        "a1b2c3d4e5f",
        "treb7uchet"
    };

    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    #pragma unroll
    for (const auto& line : calibrationDocument) {
        int calibrationValue = extractCalibrationValue(line);
        sum += calibrationValue;
    }

    std::cout << "The sum of all calibration values is: " << sum << std::endl;

    return 0;
}