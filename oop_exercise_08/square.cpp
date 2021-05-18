#include <iostream>
#include "square.h"
#include <cmath>
#include <algorithm>

namespace figure {

Square::Square() {
  for(int i = 0; i < 4; i++) {
    coordinate[i].x = 0.0;
    coordinate[i].y = 0.0;
  }
}

Square::Square(std::istream& is) {
  double a, b, c, d;
  is >> coordinate[0];
  is >> coordinate[1];
  is >> coordinate[2];
  is >> coordinate[3];
  a = sqrt((coordinate[1].x - coordinate[0].x)*(coordinate[1].x - coordinate[0].x) + (coordinate[1].y - coordinate[0].y)*(coordinate[1].y - coordinate[0].y));
  b = sqrt((coordinate[2].x - coordinate[1].x)*(coordinate[2].x - coordinate[1].x) + (coordinate[2].y - coordinate[1].y)*(coordinate[2].y - coordinate[1].y));
  c = sqrt((coordinate[3].x - coordinate[2].x)*(coordinate[3].x - coordinate[2].x) + (coordinate[3].y - coordinate[2].y)*(coordinate[3].y - coordinate[2].y));
  d = sqrt((coordinate[0].x - coordinate[3].x)*(coordinate[0].x - coordinate[3].x) + (coordinate[0].y - coordinate[3].y)*(coordinate[0].y - coordinate[3].y));
  double d1, d2;
  d1 = sqrt((coordinate[1].x - coordinate[3].x)*(coordinate[1].x - coordinate[3].x) + (coordinate[1].y - coordinate[3].y)*(coordinate[2].y - coordinate[3].y));
  d2 = sqrt((coordinate[2].x - coordinate[0].x)*(coordinate[2].x - coordinate[0].x) + (coordinate[2].y - coordinate[0].y)*(coordinate[2].y - coordinate[0].y));
  double ABC = (a * a + b * b - d2 * d2) / (2 * a * b);
  double BCD = (b * b + c * c - d1 * d1) / (2 * b * c);
  double CDA = (c * c + d * d - d1 * d1) / (2 * c * d);
  double DAB = (d * d + a * a - d2 * d2) / (2 * d * a);

  if(ABC != BCD || ABC != CDA || ABC != DAB || a!=b || a!=c || a!=d) throw std::logic_error("It`s not a square");
}

Point Square::center() const {
  return Point((coordinate[0].x + coordinate[2].x) / 2, (coordinate[0].y + coordinate[2].y) / 2);
}

double Square::area() const {
  return pow(sqrt((coordinate[0].x - coordinate[3].x)*(coordinate[0].x - coordinate[3].x) + (coordinate[0].y - coordinate[3].y)*(coordinate[0].y - coordinate[3].y)), 2);
}

void Square::print(std::ostream& os) const {
  os << "=================================\n";
  os << "\nFigure - Square" << "\nArea: " << area() << "\nCenter: " << center();
  std::cout << "Square coordinates:" << std::endl;
  os << coordinate[0] << std::endl;
  os << coordinate[1] << std::endl;
  os << coordinate[2] << std::endl;
  os << coordinate[3] << std::endl;
}
}// end of namespace

std::shared_ptr<figure::Figure> Squ_factory::Create_figure() const {
    return std::shared_ptr<figure::Figure>(new figure::Square());
}

std::shared_ptr<figure::Figure> Squ_factory::Create_figure(std::istream& is) const {
    return std::shared_ptr<figure::Figure>(new figure::Square(is));
}

