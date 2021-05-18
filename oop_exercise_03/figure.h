#ifndef D_FIGURE_H_
#define D_FIGURE_H_

#include <iostream>
#include "point.h"

class Figure {
    public:
    virtual Point center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual ~Figure() = default;
};

std::ostream& operator<< (std::ostream& os, const Figure& f);

#endif //D_FIGURE_H_