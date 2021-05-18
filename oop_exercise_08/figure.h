#ifndef FIGURE_H_
#define FIGURE_H_

#include <fstream>
#include <map>
#include <memory>
#include "point.h"

namespace figure {
    class Figure {
        public:
            virtual Point center() const = 0;
            virtual double area() const = 0;
            virtual void print(std::ostream& os) const = 0;
            virtual ~Figure() = default;
            friend std::ostream& operator<< (std::ostream& os, const Figure& f);
    };
}

enum figure_t {
    OCTAGON,
    TRIANGLE,
    SQUARE
};

class Fact_Interface {
    public:
        virtual std::shared_ptr<figure::Figure> Create_figure() const = 0;
        virtual std::shared_ptr<figure::Figure> Create_figure(std::istream& is) const = 0;
};



#endif // FIGURE_H_