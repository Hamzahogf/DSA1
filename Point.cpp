#include "Point.h"

Point::Point(const Rational& x_val, const Rational& y_val) : x(x_val), y(y_val) {}

void Point::setX(const Rational& x_val) {
    x = x_val;
}

void Point::setY(const Rational& y_val) {
    y = y_val;
}

Rational Point::getX() const {
    return x;
}

Rational Point::getY() const {
    return y;
}
