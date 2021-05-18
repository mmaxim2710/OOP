#ifndef D_TRIANGLE_H_
#define D_TRIANGLE_H_

#include "figure.h"

namespace figure {

class Triangle : public Figure {
    public:
        Point coordinate[3];
        Triangle();
        Triangle(std::istream& is);
        Point center() const override;
        double area() const override;
        void print(std::ostream& os) const override;
};
} // end of namespace


class Tri_factory: public Fact_Interface {
    public:
    std::shared_ptr<figure::Figure> Create_figure() const override;
    std::shared_ptr<figure::Figure> Create_figure(std::istream& is) const override;
};

#endif //D_TRIANGLE_H_