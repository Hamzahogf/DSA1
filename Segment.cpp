#include "Segment.h"
#include <cmath>

Segment::Segment(const Point& start_val, const Point& end_val) : start(start_val), end(end_val) {}

double Segment::getDistance() const {
    Rational diffX = end.getX().subtract(start.getX());
    Rational diffY = end.getY().subtract(start.getY());

    double diffX_float = diffX.printFloat();
    double diffY_float = diffY.printFloat();

    return std::sqrt(diffX_float * diffX_float + diffY_float * diffY_float);
}
