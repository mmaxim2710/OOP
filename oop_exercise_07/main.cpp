#include <iostream>
#include "interface.h"

bool quit (Editor& editor) {
    char c;
    std::cout << "You want save file? y/n: ";
    std::cin >> c;
    if (c == 'N' || c == 'n') {
        return true;
    }
    else if (c == 'Y' || c == 'y') {
        std::string name;
        std::cout << "Enter name for savefile: ";
        std::cin >> name;
        try {
            editor.Save_document(name);
            std::cout << "Successfully saved in " << name << '\n';
        } catch  (std::runtime_error& err) {
            std::cout << err.what() << "\n";
            return false;
        }
        return true;
    } else {
        std::cout << "so yes or no?\n";
        return false;
    }
}

void man () {
    std::cout << "create: create new document\n"
    << "save: save document to file\n"
    << "load: load document from file\n"
    << "add: add figure\n"
    << "print: print the document\n"
    << "delete: delete figure by it`s ID\n"
    << "undo: undo previous operation\n"
    << "quit: close program and exit\n";
}

bool create(Editor& editor) {
    char c;
    if (editor.Document_exist()) {
        std::cout << "Save document? y/n\n";
        std::cin >> c;
        if (c == 'N' || c == 'n') {
        }
        else if (c == 'Y' || c == 'y') {
            std::string name;
            std::cout << "Enter the name for file: ";
            std::cin >> name;
            try {
                editor.Save_document(name);
                std::cout << "Successfully saved in " << name << '\n';
            } catch  (std::runtime_error& err) {
                std::cout << err.what() << "\n";
                return false;
            }
        } else {
            std::cout << "yes or no?\n";
            return false;
        }
    }
    std::string document_name;
    std::cout << "Enter the name of project\n";
    std::cin >> document_name;
    editor.Create_document(document_name);
    std::cout << "Document " << document_name << " is created\n";
    return true;
}

bool load(Editor& editor) {
    char c;
    if (editor.Document_exist()) {
        std::cout << "Save document? y/n\n";
        std::cin >> c;
        if (c == 'N' || c == 'n') {
        }
        else if (c == 'Y' || c == 'y') {
            std::string name;
            std::cout << "Enter the name for file: ";
            std::cin >> name;
            try {
                editor.Save_document(name);
                std::cout << "Successfully saved in " << name << '\n';
            } catch  (std::runtime_error& err) {
                std::cout << err.what() << "\n";
                return false;
            }
        } else {
            std::cout << "so yes or no?\n";
            return false;
        }
    }
    std::string file_name;
    std::cout << "Enter name of load file\n";
    std::cin >> file_name;
    try {
        editor.Load_document(file_name);
        std::cout << "Successfully loaded from " << file_name << "\n";
    } catch (std::runtime_error& err) {
        std::cout << err.what() << "\n";
        return false;
    }
    return true;
}

bool save(Editor& editor) {
    std::string file_name;
    std::cout << "Enter name for savefile: ";
    std::cin >> file_name;

    try {
        editor.Save_document(file_name);
        std::cout << "Successfully saved in " << file_name << '\n';
    } catch (std::runtime_error& err) {
        std::cout << err.what() << "\n";
        return false;
    }
    return true;
}

void add (Editor& editor) {
    std::string name;
    std::cin >> name;
    editor.Insert_figure(editor.get_document()->factory.figure_names[name], std::cin);
    std::cout << "Figure is added\n";
}

bool remove(Editor& editor) {
    uint32_t id;
    std::cout << "enter ID of figure you want to delete (from 1 to ...): ";
    std::cin >> id;

    try {
        editor.Remove_figure(id);
        std::cout << "Figure with ID " << id << " is removed\n";
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
        return false;
    }
    return true;
}

int main() {
    Editor editor;
    std::string cmd;

    while (cmd != "quit") {
        std::cin >> cmd;
        if (cmd == "quit") {
           if (quit(editor)) return 0;
        } else if (cmd == "man") {
            man();
        } else if (cmd == "create") {
            create(editor);
        } else if (cmd == "save") {
            save(editor);
            std::cout << "Saved successfully" << std::endl;
        } else if (cmd == "load") {
            load(editor);
        } else if (cmd == "add") {
            add(editor);
        } else if (cmd == "delete") {
            remove(editor);
        } else if (cmd == "undo") {
            editor.Undo();
            //std::cout << "Undo done\n";
        } else if (cmd == "print") {
            editor.Print_document();
        }
    }
    return 0;
}