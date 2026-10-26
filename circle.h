
#ifndef CIRCLE_H
#define CIRCLE_H

#include <ostream>
#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    Circle();
    Circle(std::string color, Point2D center, double radius);

    double get_radius() const;
    Point2D get_center() const;

    void set_radius(double radius);
    void set_center(Point2D center);

    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;

    friend std::ostream& operator<<(std::ostream& out, const Circle& c);
};

#endif

