#ifndef COM_H
#define COM_H

#include <stack>
#include <utility>
#include "doc.h"

class Command {
protected:
    std::shared_ptr<document_class::Document> document_;
public:
    virtual ~Command() = default;
    virtual void Run() = 0;
    virtual void Abort() = 0;
    void Set_Doc(std::shared_ptr<document_class::Document> doc) { document_ = std::move(doc); }
};

class Command_insert: public Command {
private:
    figure_t fig_type_;
    std::istream& is_;
public:
    Command_insert(figure_t type, std::istream& is): fig_type_(type), is_(is) {}

    void Run() override { 
        document_->figure_add(fig_type_, is_);
        }
    void Abort() override { 
        document_->Remove_last_figure();
        }
};

class Command_remove : public Command {
private:
    uint32_t id_;
    uint32_t position_;
    std::shared_ptr<figure::Figure> figure;
public:
    explicit Command_remove(uint32_t id): id_(id), position_(0), figure(nullptr) {}

    void Run() override {
        figure = document_->Get_figure(id_);
        position_ = document_->Get_position(id_);
        document_->Remove_figure(id_);
    }

    void Abort() override {
        document_->Insert_figure(position_, figure);
    }
};

#endif //COM_H