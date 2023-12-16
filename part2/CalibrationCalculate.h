#ifndef CalibrationCalculate_h
#define CalibrationCalculate_h

#include <string>
#include <vector>

class CalibrationCalculate
{
public:
    static int calculate(const std::vector<std::string> calibrationDocument);
private:
    static int extractCalibrationValue(const std::string& line);
};

#endif // CalibrationCalculate_h