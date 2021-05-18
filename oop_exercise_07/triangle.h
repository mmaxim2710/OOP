#ifndef D_TRIANGLE_H_
#define D_TRIANGLE_H_

#include "figure.h"

namespace figure {

class Triangle : public Figure {
    public:
        Point coordinate[3];
        uint32_t id_;
        Triangle();
        Triangle(uint32_t id, std::istream& is);
        Point center() const override;
        double area() const override;
        void print(std::ostream& os) const override;
        uint32_t get_ID() const override;
        void save(std::ofstream& os) const override;
        void load(std::ifstream& is) override;
};
} // end of namespace


class Tri_factory: public Fact_Interface {
    public:
    std::shared_ptr<figure::Figure> Create_figure() const override;
    std::shared_ptr<figure::Figure> Create_figure(uint32_t id, std::istream& is) const override;
};

#endif //D_TRIANGLE_H_