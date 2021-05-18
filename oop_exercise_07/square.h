#ifndef D_Square_H_
#define D_Square_H_

#include "figure.h"

namespace figure {
struct Square : public Figure {
  private:
    Point coordinate[4];
    uint32_t id_;
  public:
    Square();
    Square(uint32_t id, std::istream& is);
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void save(std::ofstream& os) const override;
    void load(std::ifstream& is) override;
    uint32_t get_ID() const override;
};
}// end of namespace

class Squ_factory: public Fact_Interface {
  public:
    std::shared_ptr<figure::Figure> Create_figure() const override;
    std::shared_ptr<figure::Figure> Create_figure(uint32_t id, std::istream& is) const override;
};

#endif // D_Square_H_
