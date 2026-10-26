
#include "Circle.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Circle::Circle()
    : Shape(), center(), radius(1.0) {}

Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center), radius(radius) {
    if (radius < 0)
        throw std::invalid_argument("El radio no puede ser negativo");
}


double Circle::get_radius() const {
    return radius;
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_radius(double radius) {
    if (radius < 0)
        throw std::invalid_argument("El radio no puede ser negativo");
    this->radius = radius;
}

void Circle::set_center(Point2D center) {
    this->center = center;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2.0 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}
std::ostream& operator<<(std::ostream& out, const Circle& c) {
    out << "[Circle: color = " << c.get_color()
        << "; center = " << c.get_center()
        << "; radius = " << c.get_radius() << "]";
    return out;
}

void Circle::print()  {
    std::cout << "Circle(center=" << center
              << ", radius=" << radius
              << ", color=" << color << ")";
}

