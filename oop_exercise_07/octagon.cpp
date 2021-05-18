#include <iostream>
#include <cmath>
#include "octagon.h"

namespace figure {

Octagon::Octagon(): id_(0) {
    for(int i = 0; i < 8; i++) {
        coordinate[i].x = 0.0;
        coordinate[i].y = 0.0;
    }
}

Octagon::Octagon(uint32_t id, std::istream& is): id_(id) {
    for(int i = 0; i < 8; i++) {
        is >> coordinate[i];
    }
}

double Octagon::area() const {
    double result = 0;
    for(int i = 0; i < 7; i++) {
        result += (coordinate[i].x * coordinate[i+1].y) - (coordinate[i+1].x * coordinate[i].y);
    }
    result = std::abs(result + (coordinate[7].x * coordinate[0].y) - (coordinate[0].x * coordinate[7].y));
    return result / 2.0;
}

Point Octagon::center() const {
    Point result;
    for(int i = 0; i < 8; i++) {
        result = result + coordinate[i];
    }
    return result / 8.0;
}

void Octagon::print(std::ostream& os) const {
    os << "=================================\n";
    os << "id - " << id_ << "\nFigure - Octagon" << "\nArea: " << area() << "\nCenter: " << center();
    std::cout << "Octagon coordinates:" << std::endl;
    os << this->coordinate[0];
    os << this->coordinate[1];
    os << this->coordinate[2];
    os << this->coordinate[3];
    os << this->coordinate[4];
    os << this->coordinate[5];
    os << this->coordinate[6];
    os << this->coordinate[7];
}

uint32_t Octagon::get_ID() const {
    return id_;
}

void Octagon::save(std::ofstream& os) const {
    figure_t t = OCTAGON;
    os.write(reinterpret_cast<char*>(&t), sizeof(t));
    os.write((char*)(&id_), sizeof(id_));
    for(int i = 0; i <= 7 ; i++) {
        os << coordinate[i].x << ' ' << coordinate[i].y;
        if(i != 7) {
            os << "\t";
        }
    }
}

void Octagon::load(std::ifstream& is) {
    is.read((char*)(&id_), sizeof(id_));
    for(int i = 0; i <= 7; i++) {
        is >> coordinate[i].x >> coordinate[i].y;
    }
}

}// end of namespace

std::shared_ptr<figure::Figure> Oct_factory::Create_figure() const {
    return std::shared_ptr<figure::Figure>(new figure::Octagon());
}

std::shared_ptr<figure::Figure> Oct_factory::Create_figure(uint32_t id, std::istream& is) const {
    return std::shared_ptr<figure::Figure>(new figure::Octagon(id, is));
}