  
#include <iostream>
#include <cmath>
#include "triangle.h"

namespace figure {

Triangle::Triangle(): id_(0) {
    //coordinate = new Point[3];
    for(int i = 0; i < 3; i++) {
        coordinate[i].x = 0.0;
        coordinate[i].y = 0.0;
    }
}

Triangle::Triangle(uint32_t id, std::istream& is): id_(id) {
    //coordinate = new Point[3];
    for(int i = 0; i < 3; i++) {
        is >> coordinate[i];
    }
    double AB, BC, AC;
    AB = sqrt(pow(coordinate[1].x - coordinate[0].x, 2) + pow(coordinate[1].y - coordinate[0].y, 2));
    BC = sqrt(pow(coordinate[2].x - coordinate[1].x, 2) + pow(coordinate[2].y - coordinate[1].y, 2));
    AC = sqrt(pow(coordinate[2].x - coordinate[0].x, 2) + pow(coordinate[2].y - coordinate[0].y, 2));
    if(AB + BC <= AC || AB + AC <= BC || BC + AC <= AB) throw std::logic_error("This is not Triange");
}

Point Triangle::center() const {
    Point result;
    for(int i = 0; i < 3; i++) {
        result = result + coordinate[i];
    }
    return result / 3.0;
}

double Triangle::area() const {
    return fabs(((coordinate[0].x - coordinate[2].x) * (coordinate[1].y - coordinate[2].y) - (coordinate[1].x - coordinate[2].x) * (coordinate[0].y - coordinate[2].y)) / 2);
}

void Triangle::print(std::ostream& os) const {
    os << "=================================\n";
    os << "id - " << id_ << "\nFigure - Triangle" << "\nArea: " << area() << "\nCenter: " << center();
    std::cout << "Triangle coordinates" << std::endl;
    os << Point(coordinate[0].x, coordinate[0].y) << "\n" 
    << Point(coordinate[1].x, coordinate[1].y) << "\n" 
    << Point(coordinate[2].x, coordinate[2].y) << std::endl;
}

uint32_t Triangle::get_ID() const {
    return id_;
}

void Triangle::load(std::ifstream& is) {
    is.read((char*)(&id_), sizeof(id_));
    for (int i = 0; i < 3; ++i) {
        is >> coordinate[i].x  >> coordinate[i].y;
    }
}

void Triangle::save(std::ofstream& os) const {
    figure_t t = TRIANGLE;
    os.write(reinterpret_cast<char*>(&t), sizeof(t));
    os.write((char*)(&id_), sizeof(id_));
    for (int i = 0; i <= 2; ++i) {
        os << coordinate[i].x << ' ' << coordinate[i].y;
        if (i != 2) os << '\t';
    }
}

}// end of namespace

std::shared_ptr<figure::Figure> Tri_factory::Create_figure() const {
    return std::shared_ptr<figure::Figure>(new figure::Triangle());
}

std::shared_ptr<figure::Figure> Tri_factory::Create_figure(uint32_t id, std::istream& is) const {
    return std::shared_ptr<figure::Figure>(new figure::Triangle(id, is));
}