#include <iostream>
#include "square.h"
#include <cmath>
#include <algorithm>

namespace figure {

Square::Square(): id_(0) {
  for(int i = 0; i < 4; i++) {
    coordinate[i].x = 0.0;
    coordinate[i].y = 0.0;
  }
}

Square::Square(uint32_t id, std::istream& is): id_(id) {
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
  //if((coordinate[1].x - coordinate[2].x != coordinate[1].y - coordinate[2].y) || (coordinate[1].x == coordinate[2].x && coordinate[1].y == coordinate[2].y)) throw std::logic_error("This are incorrect coordinates");
  //if(coordinate[1].x - coordinate[2].x != coordinate[1].y - coordinate[2].y) throw std::logic_error("This is not square");
}

Point Square::center() const {
  return Point((coordinate[0].x + coordinate[2].x) / 2, (coordinate[0].y + coordinate[2].y) / 2);
}

double Square::area() const {
  //const double dx = coordinate[1].x - coordinate[3].x;
  //const double dy = coordinate[1].y - coordinate[3].y;
  //return std::abs(dx * dy);
  return pow(sqrt((coordinate[0].x - coordinate[3].x)*(coordinate[0].x - coordinate[3].x) + (coordinate[0].y - coordinate[3].y)*(coordinate[0].y - coordinate[3].y)), 2);
}

void Square::print(std::ostream& os) const {
  os << "=================================\n";
  os << "id - " << id_ << "\nFigure - Square" << "\nArea: " << area() << "\nCenter: " << center();
  std::cout << "Square coordinates:" << std::endl;
  os << coordinate[0] << std::endl;
  os << coordinate[1] << std::endl;
  os << coordinate[2] << std::endl;
  os << coordinate[3] << std::endl;
}

void Square::save(std::ofstream& os) const {
  figure_t t = SQUARE;
  os.write(reinterpret_cast<char*>(&t), sizeof(t));
  os.write((char*)(&id_), sizeof(id_));
  for (int i = 0; i < 2; ++i) {
    os << coordinate[i].x << ' ' << coordinate[i].y;
    if (i != 1) os << '\t';
  }
}

void Square::load(std::ifstream& is) {
  is.read((char*)(&id_), sizeof(id_));
  for (int i = 0; i < 2; ++i) {
    is >> coordinate[i].x  >> coordinate[i].y;
  }
}

uint32_t Square::get_ID() const {
  return id_;
}
}// end of namespace

std::shared_ptr<figure::Figure> Squ_factory::Create_figure() const {
    return std::shared_ptr<figure::Figure>(new figure::Square());
}

std::shared_ptr<figure::Figure> Squ_factory::Create_figure(uint32_t id, std::istream& is) const {
    return std::shared_ptr<figure::Figure>(new figure::Square(id, is));
}

