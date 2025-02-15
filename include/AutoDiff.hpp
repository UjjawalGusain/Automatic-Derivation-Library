#ifndef AUTODIFF_HPP
#define AUTODIFF_HPP

#include <iostream>
#include <cmath>

template <typename T>
class DualNumber {
public:
    T real, dual;

    DualNumber(T real, T dual);

    // Operator Overloads
    DualNumber<T> operator+(const DualNumber<T>& num) const;
    DualNumber<T> operator+(T scalar) const;
    friend DualNumber<T> operator+(T scalar, const DualNumber<T>& num) { return num + scalar; }

    DualNumber<T> operator-(const DualNumber<T>& num) const;
    DualNumber<T> operator-(T scalar) const;
    friend DualNumber<T> operator-(T scalar, const DualNumber<T>& num) { return DualNumber<T>(scalar - num.real, -num.dual); }

    DualNumber<T> operator*(const DualNumber<T>& num) const;
    DualNumber<T> operator*(T scalar) const;
    friend DualNumber<T> operator*(T scalar, const DualNumber<T>& num) { return num * scalar; }

    DualNumber<T> operator/(const DualNumber<T>& num) const;
    DualNumber<T> operator/(T scalar) const;
    friend DualNumber<T> operator/(T scalar, const DualNumber<T>& num) { return DualNumber<T>(scalar / num.real, -scalar * num.dual / (num.real * num.real)); }

    DualNumber<T> pow(const T& exponent) const;
    friend DualNumber<T> pow(const DualNumber<T>& base, const T& exponent) { return base.pow(exponent); }

    // Trigonometric Functions
    template <typename U>  // Add template parameter explicitly
    friend DualNumber<U> sin(const DualNumber<U>& num);
    
    template <typename U>
    friend DualNumber<U> cos(const DualNumber<U>& num);
    
    template <typename U>
    friend DualNumber<U> tan(const DualNumber<U>& num);
    
    template <typename U>
    friend DualNumber<U> cot(const DualNumber<U>& num);
    
    template <typename U>
    friend DualNumber<U> sec(const DualNumber<U>& num);
    
    template <typename U>
    friend DualNumber<U> csc(const DualNumber<U>& num);


    // Differentiation Function
    template <typename Func>
    static T differentiate(Func f, T x);
};

#include "AutoDiff.tpp" 

#endif // AUTODIFF_HPP
