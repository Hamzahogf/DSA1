#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Point.hpp"

class Segment {
private:
    Point start;
    Point end;

public:
    Segment(const Point& start_val = Point(), const Point& end_val = Point());
    double getDistance() const;
};

#endif // SEGMENT_H
