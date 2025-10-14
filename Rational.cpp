#include "Rational.h"
#include <iostream>
#include <cmath>

int Rational::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Rational::reduce() {
    int gcd_val = gcd(numerator, denominator);
    numerator /= gcd_val;
    denominator /= gcd_val;
}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    reduce();
}

Rational Rational::add(const Rational& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Rational(num, denom);
}

Rational Rational::subtract(const Rational& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Rational(num, denom);
}

Rational Rational::multiply(const Rational& other) const {
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Rational(num, denom);
}

Rational Rational::divide(const Rational& other) const {
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    return Rational(num, denom);
}

void Rational::print() const {
    std::cout << numerator << " / " << denominator;
}

double Rational::printFloat() const {
    return static_cast<double>(numerator) / denominator;
}
