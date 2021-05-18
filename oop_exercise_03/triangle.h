#ifndef D_TRIANGLE_H_
#define D_TRIANGLE_H_

#include "figure.h"

class Triangle : public Figure {
    public:
        Point coordinate[3];
        Triangle();
        Triangle(std::istream& is);
        Point center() const override;
        double area() const override;
        void print(std::ostream& os) const override;
};

#endif //D_TRIANGLE_H_