#include <iostream>
#include <cmath> // For square root function


class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0)
            throw std::invalid_argument("Denominator cannot be zero.");
        reduce();
    }

    Rational add(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational subtract(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational multiply(const Rational& other) const {
        return Rational(numerator * other.numerator,
                        denominator * other.denominator);
    }

    Rational divide(const Rational& other) const {
        if (other.numerator == 0)
            throw std::invalid_argument("Cannot divide by zero.");
        return Rational(numerator * other.denominator,
                        denominator * other.numerator);
    }

    void print() const {
        std::cout << numerator << "/" << denominator;
    }

    double to_double() const {
        return static_cast<double>(numerator) / denominator;
    }
};
class Point {
private:
    Rational x;
    Rational y;

public:
    Point(Rational x_val = Rational(), Rational y_val = Rational()) : x(x_val), y(y_val) {}

    std::pair<Rational, Rational> get_coordinates() const {
        return std::make_pair(x, y);
    }

    void set_coordinates(Rational x_val, Rational y_val) {
        x = x_val;
        y = y_val;
    }

    void print() const {
        std::cout << "(";
        x.print();
        std::cout << ", ";
        y.print();
        std::cout << ")";
    }
};
class Segment {
private:
    Point point1;
    Point point2;

public:
    Segment(const Point& p1 = Point(), const Point& p2 = Point()) : point1(p1), point2(p2) {}

Rational get_dimension_x(const Point& p1, const Point& p2) const {
    Rational x1 = p1.get_coordinates().first;
    Rational x2 = p2.get_coordinates().first;
    return x2.subtract(x1);
}

Rational get_dimension_y(const Point& p1, const Point& p2) const {
    Rational y1 = p1.get_coordinates().second;
    Rational y2 = p2.get_coordinates().second;
    return y2.subtract(y1);
}

   
};



class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int common_divisor = gcd(this->numerator, this->denominator);
        this->numerator /= common_divisor;
        this->denominator /= common_divisor;
    }

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (this->denominator == 0)
            throw std::invalid_argument("Denominator cannot be zero.");
        this->reduce();
    }

    Rational add(const Rational& other) const {
        return Rational(this->numerator * other.denominator + other.numerator * this->denominator,
                        this->denominator * other.denominator);
    }

    Rational subtract(const Rational& other) const {
        return Rational(this->numerator * other.denominator - other.numerator * this->denominator,
                        this->denominator * other.denominator);
    }

    Rational multiply(const Rational& other) const {
        return Rational(this->numerator * other.numerator,
                        this->denominator * other.denominator);
    }

    Rational divide(const Rational& other) const {
        if (other.numerator == 0)
            throw std::invalid_argument("Cannot divide by zero.");
        return Rational(this->numerator * other.denominator,
                        this->denominator * other.numerator);
    }

    void print() const {
        std::cout << this->numerator << "/" << this->denominator;
    }

    double to_double() const {
        return static_cast<double>(this->numerator) / this->denominator;
    }
};
class Point {

private:
    Rational x;
    Rational y;

public:
    Point(Rational x_val = Rational(), Rational y_val = Rational()) : x(x_val), y(y_val) {}

    std::pair<Rational, Rational> get_coordinates() const {
        return std::make_pair(this->x, this->y);
    }

    void set_coordinates(Rational x_val, Rational y_val) {
        this->x = x_val;
        this->y = y_val;
    }

    void print() const {
        std::cout << "(";
        this->x.print();
        std::cout << ", ";
        this->y.print();
        std::cout << ")";
    }
};
class Segment {
private:
    Point point1;
    Point point2;

public:
    Segment(const Point& p1 = Point(), const Point& p2 = Point()) : point1(p1), point2(p2) {}
Rational get_dx() const {
    return this->point2.get_coordinates().first.subtract(this->point1.get_coordinates().first);
}

Rational get_dy() const {
    return this->point2.get_coordinates().second.subtract(this->point1.get_coordinates().second);
}

    
};