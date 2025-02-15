#include <iostream>
#include "AutoDiff.hpp"

DualNumber<double> exampleFunction1(DualNumber<double> x) {
    return x * x + 3 * x + 5;
}

DualNumber<double> exampleFunction2(DualNumber<double> x) {
    return csc(x) + cos(x) + 5;
}


int main() {
    double x = 2.0;
    double derivative = DualNumber<double>::differentiate(exampleFunction1, x);

    std::cout << "Function: f(x) = x^2 + 3x + 5" << std::endl;
    std::cout << "Derivative at x = " << x << " is: " << derivative << std::endl;

    return 0;
}
