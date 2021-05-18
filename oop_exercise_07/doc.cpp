#include <algorithm>
#include <cstdint>
#include <iostream>
#include "doc.h"

document_class::Document::Document(): id_(1), doc_name(""), buffer(0), factory() {}

document_class::Document::Document(std::string name): id_(1), doc_name(std::move(name)), buffer(0), factory() {}

void document_class::Document::Save(const std::string &file_name) const {
    Save_private(file_name);
}

void document_class::Document::Load(const std::string &file_name) {
    Load_private(file_name);
}

void document_class::Document::Save_private(const std::string &file_name) const {
    std::ofstream os;
    os.open(file_name, std::ios_base::binary | std::ios_base::out);
    if (!os.is_open()) {
        throw std::runtime_error("File is not opened");
    }
    uint32_t format = FORMAT_CODE;
    uint32_t nameLen = doc_name.size();
    os.write((char*)&format, sizeof(format));
    os.write((char*)&nameLen, sizeof(nameLen));
    os.write((char*)(doc_name.c_str()), nameLen);
    std::for_each(buffer.begin(), buffer.end(), [&](const std::shared_ptr<figure::Figure>& shape) {
        shape->save(os);
    });
}

void document_class::Document::Load_private(const std::string &file_name) {
    std::ifstream is;
    is.open(file_name, std::ios_base::binary | std::ios_base::in);
    if (!is.is_open()) {
        throw std::runtime_error("File is not opened");
    }
    uint32_t format;
    uint32_t nameLen;
    is.read((char*)&format, sizeof(format));
    if (format != FORMAT_CODE)
        throw std::runtime_error("Bad file");
    is.read((char*)&nameLen, sizeof(nameLen));
    char* name = new char[nameLen + 1];
    name[nameLen] = 0;
    is.read(name, nameLen);
    doc_name = std::string(name);
    delete[] name;
    figure_t type;
    while(true) {
        is.read((char*)&type, sizeof(type));
        if (is.eof()) break;
        buffer.push_back(factory.plants[type]->Create_figure());
        buffer.back()->load(is);
    }
    id_ = buffer.size();
}

void document_class::Document::Print() const {
    std::for_each(buffer.begin(), buffer.end(), [&](const std::shared_ptr<figure::Figure>& shape) {
        shape->print(std::cout);
    });
}

void document_class::Document::Remove_figure(uint32_t id) {
    auto it = std::find_if(buffer.begin(), buffer.end(), [id](const std::shared_ptr<figure::Figure>& shape) -> bool {
        return id == shape->get_ID();
    });

    if (it == buffer.end())
        throw std::logic_error("Figure with this id doesn't exist");

    buffer.erase(it);
}

void document_class::Document::Remove_last_figure() {
    if (buffer.empty()) {
        throw std::logic_error("Doc is empty");
    }
    buffer.pop_back();
}

void document_class::Document::figure_add(figure_t type, std::istream& is) {
    buffer.push_back(factory.plants[type]->Create_figure(id_++, is));
}

uint32_t document_class::Document::Get_position(uint32_t id) {
    auto it = std::find_if(buffer.begin(), buffer.end(), [id](std::shared_ptr<figure::Figure>& shape) -> bool {
        return id == shape->get_ID();
    });
    return std::distance(buffer.begin(), it);
}

std::shared_ptr<figure::Figure> document_class::Document::Get_figure(uint32_t id)  {
    auto it = std::find_if(buffer.begin(), buffer.end(), [id](std::shared_ptr<figure::Figure>& shape) -> bool {
        return id == shape->get_ID();
    });
    return *it;
}

void document_class::Document::Insert_figure(uint32_t pos, std::shared_ptr<figure::Figure>& figure) {
    auto it = buffer.begin();
    std::advance(it, pos);
    buffer.insert(it, figure);
}