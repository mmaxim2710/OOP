#include <iostream>
#include <vector>
#include "point.h"
#include "figure.h"
#include "octagon.h"
#include "triangle.h"
#include "square.h"

void help() {
    std::cout << "add = add figure" << std::endl;
    std::cout << "delete = delete figure" << std::endl;
    std::cout << "print = show information about figure" << std::endl;
    std::cout << "print_all = show information about all figures" << std::endl;
    std::cout << "size = the size of our array of figures" << std::endl;
    std::cout << "all_area = the sum area of all figures" << std::endl;
    std::cout << "exit = exit" << std::endl;
}

void simple_add(std::vector<Figure*>& figures) {
    std::cout << "Press o to add octagon, t to add triangle, s to add square" << std::endl;
    std::string info;
    Figure* f = nullptr;
    std::cin >> info;
    try {
    if(info == "t") {
        std::cout << "Insert 3 coordinates of triangle" << std::endl;
        f = new Triangle(std::cin);
    } else if (info == "s") {
        std::cout << "Insert 4 coordinates of square" << std::endl;
        f = new Square(std::cin);
    } else if (info == "o") {
        std::cout << "Insert 8 coordinates of octagon" << std::endl;
            f = new Octagon(std::cin);
        }
    }
    catch (std::logic_error& err) {
        std::cout << err.what() << std::endl;
    }
    if(f != nullptr) {
        figures.push_back(dynamic_cast<Figure*>(f));
    }
}

/* std::vector<Figure*> delete_el(std::vector<Figure*>& figures, int del) {
    int i = 0;
    std::vector<Figure*> n_figures;
    while(i < figures.size()) {
        if(i != del) {
            n_figures.push_back(figures[i]);
        }
        i++;
    }
    figures.clear();
    return n_figures;   
} */

int main() {
    std::vector<Figure*> figures;
    std::string data;
    int i;
    help();
    while(std::cin >> data) {
        if(data == "add") {
            simple_add(figures);
        } else if(data == "delete") {
            std::cout << "Index = ";
            std::cin >> i;
            if(i < 0 || i >= figures.size()) {
                std::cout << "Incorrect index" << std::endl;
            } else {
                //delete figures[i];
                //figures = delete_el(figures, i);
                figures.erase(figures.begin() + i);
            }
        } else if(data == "print") {
            std::cout << "Index = ";
            std::cin >> i;
            if(i < 0 || i >= figures.size()) {
                std::cout << "Incorrect index" << std::endl;
            } else {
                std::cout << "Coordinates:" << std::endl;
                std::cout << *figures[i];
                std::cout << "Center:" << std::endl;
                std::cout << figures[i]->center();
                std::cout << "Area:" << std::endl;
                std::cout << figures[i]->area() << std::endl;
            }
        } else if(data == "print_all") {
            for(int j = 0; j < figures.size(); j++) {
                std::cout << j << " figure" << std::endl;
                std::cout << *figures[j] << std::endl;
                std::cout << "Center:" << std::endl;
                std::cout << figures[j]->center();
                std::cout << "Area:" << std::endl;
                std::cout << figures[j]->area() << std::endl;
            }
        } else if(data == "size") {
            std::cout << figures.size() << std::endl;
        } else if(data == "all_area") {
            double b;
            for(int j = 0; j < figures.size(); j++) {
                b += figures[j]->area();
            }
            std::cout << "Area of all figures: " << b << std::endl;
        } else if(data == "exit") {
            for(int j = 0; j < figures.size(); j++) {
                delete figures[j];
            }
            return 0;
        }
    }
    return 0;
}

//