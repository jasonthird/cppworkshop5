#include <iostream>
#include <string>
#include <fstream>
#include "CalibrationCalculate.h"

int main() {

    //read from file
    std::ifstream file("../input.txt");

    std::string line;
    std::vector<std::string> calibrationDocument;
    
    while (std::getline(file, line))
    {
        calibrationDocument.push_back(line);
    }
    file.close();
    int sum = CalibrationCalculate::calculate(calibrationDocument);

    std::cout << "The sum of all calibration values is: " << sum << std::endl;

    return 0;
}