#ifndef AUTODIFF_TPP
#define AUTODIFF_TPP

#include "AutoDiff.hpp"

template <typename T>
DualNumber<T>::DualNumber(T real, T dual) : real(real), dual(dual) {}

// Operator Overloads
template <typename T>
DualNumber<T> DualNumber<T>::operator+(const DualNumber<T>& num) const {
    return DualNumber<T>(real + num.real, dual + num.dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator+(T scalar) const {
    return DualNumber<T>(real + scalar, dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator-(const DualNumber<T>& num) const {
    return DualNumber<T>(real - num.real, dual - num.dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator-(T scalar) const {
    return DualNumber<T>(real - scalar, dual);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator*(const DualNumber<T>& num) const {
    return DualNumber<T>(real * num.real, real * num.dual + dual * num.real);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator*(T scalar) const {
    return DualNumber<T>(real * scalar, dual * scalar);
}

template <typename T>
DualNumber<T> DualNumber<T>::operator/(const DualNumber<T>& num) const {
    return DualNumber<T>(real / num.real, (dual * num.real - real * num.dual) / (num.real * num.real));
}

template <typename T>
DualNumber<T> DualNumber<T>::operator/(T scalar) const {
    return DualNumber<T>(real / scalar, dual / scalar);
}

template <typename T>
DualNumber<T> DualNumber<T>::pow(const T& exponent) const {
    return DualNumber<T>(std::pow(real, exponent), exponent * std::pow(real, exponent - 1) * dual);
}

// Trigonometric Functions
template <typename T>
DualNumber<T> sin(const DualNumber<T>& num) {
    return DualNumber<T>(std::sin(num.real), std::cos(num.real) * num.dual);
}

template <typename T>
DualNumber<T> cos(const DualNumber<T>& num) {
    return DualNumber<T>(std::cos(num.real), -std::sin(num.real) * num.dual);
}

template <typename T>
DualNumber<T> tan(const DualNumber<T>& num) {
    T cos_real = std::cos(num.real);
    return DualNumber<T>(std::tan(num.real), num.dual / (cos_real * cos_real));
}

template <typename T>
DualNumber<T> cot(const DualNumber<T>& num) {
    T tan_real = std::tan(num.real);
    return DualNumber<T>(1.0 / tan_real, -num.dual / (std::sin(num.real) * std::sin(num.real)));
}

template <typename T>
DualNumber<T> csc(const DualNumber<T>& num) {
    T sin_real = std::sin(num.real);
    return DualNumber<T>(1.0 / sin_real, -num.dual * std::cos(num.real) / (sin_real * sin_real));
}

template <typename T>
DualNumber<T> sec(const DualNumber<T>& num) {
    T cos_real = std::cos(num.real);
    return DualNumber<T>(1.0 / cos_real, num.dual * std::tan(num.real) / cos_real);
}


// Differentiation Function
template <typename T>
template <typename Func>
T DualNumber<T>::differentiate(Func f, T x) {
    DualNumber<T> input(x, 1);
    DualNumber<T> result = f(input);
    return result.dual;
}

#endif // AUTODIFF_TPP
