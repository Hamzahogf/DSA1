#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);
    void reduce();

public:
    Rational(int num = 0, int denom = 1);
    Rational add(const Rational& other) const;
    Rational subtract(const Rational& other) const;
    Rational multiply(const Rational& other) const;
    Rational divide(const Rational& other) const;
    void print() const;
    double printFloat() const;
};

#endif