#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stack>
#include "doc.h"
#include "com.h"

class Editor {

private:
    std::stack<std::shared_ptr<Command>> History_;
    std::shared_ptr<document_class::Document> document_;

public:
    Editor(): document_(nullptr), History_() {}

    ~Editor() = default;

    void Create_document(const std::string& name) {
        document_ = std::make_shared<document_class::Document>(name);
        while(!History_.empty())
            History_.pop();
    }


    void Save_document(const std::string& filename) {
        document_->Save(filename);
    }

    std::shared_ptr<document_class::Document> get_document() {
        return document_;
    }

    void Load_document(const std::string& filename) {
        document_ = std::make_shared<document_class::Document>("NoName");
        document_->Load(filename);
        while(!History_.empty())
            History_.pop();
    }


    void Insert_figure(figure_t type, std::istream& is) {
        std::shared_ptr<Command> command = std::shared_ptr<Command>(new Command_insert(type, is));
        command->Set_Doc(document_);
        command->Run();
        History_.push(command);
    }

    void Remove_figure(uint32_t id) {
        std::shared_ptr<Command> command = std::shared_ptr<Command>(new Command_remove(id));
        command->Set_Doc(document_);
        command->Run();
        History_.push(command);
    }

    void Print_document() {
        document_->Print();
    }

    bool Document_exist() {
        return document_ != nullptr;
    }

    void Undo() {
        if (History_.empty()) {
            std::cout << "History is empty" << std::endl;
        } else {
            std::shared_ptr<Command> last_cmd = History_.top();
            last_cmd->Abort();
            History_.pop();
        }
    }
};

#endif