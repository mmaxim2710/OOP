#ifndef D_Square_H_
#define D_Square_H_

#include "figure.h"

namespace figure {
struct Square : public Figure {
  private:
    Point coordinate[4];
  public:
    Square();
    Square(std::istream& is);
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
};
}// end of namespace

class Squ_factory: public Fact_Interface {
  public:
    std::shared_ptr<figure::Figure> Create_figure() const override;
    std::shared_ptr<figure::Figure> Create_figure(std::istream& is) const override;
};

#endif // D_Square_H_
