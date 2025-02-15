#include <iostream>
#include "AutoDiff.hpp"
#include <fstream>
#include <cmath>
#define M_PI 3.14

const double h = 1e-6;

DualNumber<double> func1(DualNumber<double> x) { return pow(x, 3) + 2 * x + 9; }
DualNumber<double> func2(DualNumber<double> x) { return sin(x) + cos(x); }
DualNumber<double> func3(DualNumber<double> x) { return tan(x) - x * x; }
DualNumber<double> func4(DualNumber<double> x) { return pow(x, 4) - 3 * pow(x, 2) + 7; }
DualNumber<double> func5(DualNumber<double> x) { return 1 / cos(x) + 1 / sin(x); }
DualNumber<double> func6(DualNumber<double> x) { return x * sin(x) + cos(x) / x; }
DualNumber<double> func7(DualNumber<double> x) { return sin(x) + cos(x); }

double numerical_derivative(double (*f)(double), double x) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

double func1_num(double x) { return pow(x, 3) + 2 * x + 9; }
double func2_num(double x) { return sin(x) + cos(x); }
double func3_num(double x) { return tan(x) - x * x; }
double func4_num(double x) { return pow(x, 4) - 3 * pow(x, 2) + 7; }
double func5_num(double x) { return 1 / cos(x) + 1 / sin(x); }
double func6_num(double x) { return x * sin(x) + cos(x) / x; }
double func7_num(double x) { return sin(x) + cos(x); }

double computeAverageError(DualNumber<double>(*func)(DualNumber<double>), double (*num_func)(double), double test_values[], int size) {
    double total_error = 0.0;
    
    for (int i = 0; i < size; i++) {
        double x = test_values[i];
        double autodiff_result = DualNumber<double>::differentiate(func, x);
        double numerical_result = numerical_derivative(num_func, x);
        total_error += std::abs(autodiff_result - numerical_result);
    }
    
    return total_error / size;
}

int main() {
    std::ofstream testFile("test_results.txt");
    
    if (!testFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    double test_values[] = {1, 2, 3, 0.5, -1, -0.5, M_PI / 4};
    int test_size = sizeof(test_values) / sizeof(test_values[0]);

    testFile << "Average Errors:\n";
    testFile << "pow(x, 3) + 2x + 9: " << computeAverageError(func1, func1_num, test_values, test_size) << "\n";
    testFile << "sin(x) + cos(x): " << computeAverageError(func2, func2_num, test_values, test_size) << "\n";
    testFile << "tan(x) - x^2: " << computeAverageError(func3, func3_num, test_values, test_size) << "\n";
    testFile << "pow(x, 4) - 3 * pow(x, 2) + 7: " << computeAverageError(func4, func4_num, test_values, test_size) << "\n";
    testFile << "sec(x) + csc(x): " << computeAverageError(func5, func5_num, test_values, test_size) << "\n";
    testFile << "x * sin(x) + cos(x) / x: " << computeAverageError(func6, func6_num, test_values, test_size) << "\n";
    testFile << "sin(x) + cos(x): " << computeAverageError(func7, func7_num, test_values, test_size) << "\n";

    testFile.close();
    
    std::cout << "Average errors written to 'test_results.txt'\n";
    
    return 0;
}
