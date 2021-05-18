#ifndef OCTAGON_H_
#define OCTAGON_H_

#include "figure.h"

namespace figure {

    class Octagon : public Figure {
        private:
            Point coordinate[8];
            uint32_t id_;
        public:
            Octagon();
            Octagon(uint32_t id, std::istream& is);
            Point center() const override;
            double area() const override;
            void print(std::ostream& os) const override;
            uint32_t get_ID() const override;
            void save(std::ofstream& os) const override;
            void load(std::ifstream& is) override;
    };
}

class Oct_factory: public Fact_Interface {
    public:
        std::shared_ptr<figure::Figure> Create_figure() const override;
        std::shared_ptr<figure::Figure> Create_figure(uint32_t id, std::istream& is) const override;
};

#endif // OCTAGON_H_