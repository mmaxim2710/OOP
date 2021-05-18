#ifndef OCTAGON_H_
#define OCTAGON_H_

#include "vertex.h"
#include <iostream>
#include <type_traits>

template <class T>
class Octagon {
public:
    vertex<T> points[8];
    int size = 8;

    Octagon<T>() = default;
    explicit Octagon<T>(std::istream& is) {
        for (auto & point : points) {
            is >> point;
        }
    }

    double area() {
        double result = 0;
        for(int i = 0; i < 7; ++i) {
            result += (points[i].x * points[i+1].y) - (points[i+1].x * points[i].y);
        }
        
        result = (result + (points[7].x * points[0].y) - (points[0].x * points[7].y))/2;
        return std::abs(result);
    }

    void print(std::ostream& os) {
        for(int i = 0; i < 8; ++i) {
            os << this->points[i];
            if(i != size - 1) os << ", ";
        }
        os << '\n';
    }

    void operator<< (std::ostream& os) {
        for(int i = 0; i < 8; ++i) {
            os << this->points[i];
            if(i != size - 1) os << ", ";
        }
    }
};

#endif // OCTAGON_H_