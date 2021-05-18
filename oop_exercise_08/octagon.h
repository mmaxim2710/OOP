#ifndef OCTAGON_H_
#define OCTAGON_H_

#include "figure.h"

namespace figure {

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
}

class Oct_factory: public Fact_Interface {
    public:
        std::shared_ptr<figure::Figure> Create_figure() const override;
        std::shared_ptr<figure::Figure> Create_figure(std::istream& is) const override;
};

#endif // OCTAGON_H_