#include "Square.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

Square::Square()
    : Rectangle("red", new Point2D[N_VERTICES]{
        Point2D(-1, 1),
        Point2D(1, 1),
        Point2D(1, -1),
        Point2D(-1, -1)
    })
{
}

Square::Square(std::string color, Point2D* vertices)
    : Rectangle(color, vertices)
{
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid square vertices");
    }
}

bool Square::check(Point2D* vertices)
{
    if (vertices == nullptr) {
        return false;
    }

    const double epsilon = 1e-9;

    double d0 = Point2D::distance(vertices[0], vertices[1]);
    double d1 = Point2D::distance(vertices[1], vertices[2]);
    double d2 = Point2D::distance(vertices[2], vertices[3]);
    double d3 = Point2D::distance(vertices[3], vertices[0]);

    return std::abs(d0 - d1) < epsilon &&
           std::abs(d1 - d2) < epsilon &&
           std::abs(d2 - d3) < epsilon;
}

void Square::set_vertices(Point2D* vertices)
{
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid square vertices");
    }

    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream& out, const Square& square)
{
    out << "[Square: color = " << square.get_color()
        << "; vertices = ";

    for (int i = 0; i < Square::N_VERTICES; i++) {
        if (i > 0) {
            out << ", ";
        }

        out << square.get_vertex(i);
    }

    out << "]";

    return out;
}
void Square::print()
{
    std::cout << *this;
}
