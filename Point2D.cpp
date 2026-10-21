#include <ostream>
#include <cmath>
#include "Point2D.h"

double Point2D::distance(const Point2D &a,const Point2D &b) {
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

bool Point2D::operator==(const Point2D &other) {
    // A definir
	if (x==other.x && y==other.y){
		return true;
	}
		return false;

}

bool Point2D::operator!=(const Point2D &other) {
    // A definir
	if (x!=other.x || y!=other.y){
		return true;
	}
		return false;
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    // A definir
	out<<"(";
	out<<p.x;
	out<<",";
	out<<p.y;
	out<<")";
	return out;
}
