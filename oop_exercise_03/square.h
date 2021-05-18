#ifndef D_Square_H_
#define D_Square_H_

#include "figure.h"

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

#endif // D_Square_H_
