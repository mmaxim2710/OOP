#include "point.h"
#include <cmath>

Point::Point(): x(0), y(0) {
}

Point::Point(double a, double b): x(a), y(b) {
}

/*Point& Point::operator=(const Point& other) {
  this->x = other.x;
  this->y = other.y;
  return *this;
}*/

Point Point::operator+(const Point& other) {
  Point result;
  result.x = this->x + other.x;
  result.y = this->y + other.y;
  return result;
}

Point Point::operator-(const Point& other) {
  Point result;
  result.x = this->x - other.x;
  result.y = this->y - other.y;
  return result;
}

Point Point::operator/(const double num) {
  Point result;
  result.x = this->x / num;
  result.y = this->y / num;
  return result;
}

std::istream& operator>> (std::istream& is, Point& p) {
  return is >> p.x >> p.y;
}

std::ostream& operator<< (std::ostream& os, const Point& p) {
  return os << "(" << p.x << ", " << p.y << ")" << std::endl;
}
