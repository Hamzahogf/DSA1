#ifndef POINT_HPP
#define POINT_HPP

#include "Rational.hpp"

class Point {
private:
    Rational x;
    Rational y;

public:
    Point(const Rational& x_val = Rational(), const Rational& y_val = Rational());
    void setX(const Rational& x_val);
    void setY(const Rational& y_val);
    Rational getX() const;
    Rational getY() const;
};

#endif // POINT_H
