#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <fstream>
#include <memory>
#include <list>
#include "figure.h"
#include "octagon.h"
#include "square.h"
#include "triangle.h"

const uint32_t FORMAT_CODE = 06032001;

namespace document_class {

    class Factory {
    public:
        Factory() {
            plants.emplace(TRIANGLE, std::make_shared<Tri_factory>());
            plants.emplace(SQUARE, std::make_shared<Squ_factory>());
            plants.emplace(OCTAGON, std::make_shared<Oct_factory>());
            figure_names.emplace("triangle", TRIANGLE);
            figure_names.emplace("square", SQUARE);
            figure_names.emplace("octagon", OCTAGON);
        }
        std::map<figure_t, std::shared_ptr<Fact_Interface>> plants;
        std::map<std::string, figure_t> figure_names;
    };

    class Document {
    private:
        uint32_t id_;
        std::string doc_name;
        std::list<std::shared_ptr<figure::Figure>> buffer;

        void Save_private(const std::string& file_name) const;
        void Load_private(const std::string& file_name);
    public:
        Document();
        explicit Document(std::string name);
        void Save(const std::string &file_name) const;
        void Load(const std::string &file_name);
        void Print() const;
        void Remove_figure(uint32_t id);
        void Remove_last_figure();
        void figure_add(figure_t type, std::istream &is);
        uint32_t Get_position(uint32_t id);
        std::shared_ptr<figure::Figure> Get_figure(uint32_t id);
        void Insert_figure(uint32_t pos, std::shared_ptr<figure::Figure>& figure);
        ~Document() = default;
        Factory factory;
    };

}

#endif //OOP_LAB7_DOCUMENT_H