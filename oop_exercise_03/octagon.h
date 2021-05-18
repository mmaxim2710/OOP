#ifndef D_OCTAGON_H_
#define D_OCTAGON_H_

#include "figure.h"
#include <cmath>

class Octagon : public Figure {
    private:
        Point coordinate[8];
    public:
        Octagon();
        Octagon(std::istream& is);
        Point center() const override;
        double area() const override;
        void print(std::ostream& os) const override;
};

#endif //D_OCTAGON_H_