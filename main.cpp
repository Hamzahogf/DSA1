#include <iostream>
#include "Segment.hpp"
#include "Rational.hpp"
#include "Point.hpp"
int main() {
    // Create Rational numbers for Point coordinates
    Rational x1(1, 2);
    Rational y1(3, 4);
    Rational x2(5, 6);
    Rational y2(7, 8);

    // Create Points
    Point start(x1, y1);
    Point end(x2, y2);

    // Create Segment
    Segment segment(start, end);

    // Calculate and print the distance between the start and end points
    double distance = segment.getDistance();
    std::cout << "Distance between start and end points: " << distance << std::endl;

    return 0;
}
