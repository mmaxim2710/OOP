#include <iostream>
#include <cmath>
#include "octagon.h"

Octagon::Octagon() {
    for(int i = 0; i < 8; i++) {
        coordinate[i].x = 0.0;
        coordinate[i].y = 0.0;
    }
}

Octagon::Octagon(std::istream& is) {
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