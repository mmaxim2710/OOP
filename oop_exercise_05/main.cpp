#include <iostream>
#include <algorithm>
#include "containers/stack.h"
#include "octagon.h"

int main() {
    size_t number;
    float S;
    //size_t n = 0;
    char option = 'a';
    containers::stack<Octagon<int>> q;
    Octagon<int> oct{};
    while (option != '0') {
        std::cout << "0. Exit\n"
        << "1. Add element in stack\n"
        << "2. Add element into number of position\n"
        << "3. Delete element from the number of position\n"
        << "4. Print out current stack\n"
        << "5. Print out number of elements, which area less than value\n";
        std:: cin >> option;
        switch (option) {
            case '0':
                break;   
            case '1': {
                std::cout << "enter octagon (have to enter dots consequently): " << std::endl;
                oct = Octagon<int>(std::cin);
                q.push(oct);
                break;
            }
            case '2': {
                std::cout << "enter position to insert to: ";
                std::cin >> number;
                std::cout << "enter octagon: ";
                oct = Octagon<int>(std::cin);
                q.insert_by_number(number, oct);
                break;
            }
            case '3': {
                std::cout << "enter position to delete: ";
                std::cin >> number;
                q.delete_by_number(number);
                break;
            }
            case '4': {
                std::for_each(q.begin(), q.end(), [](Octagon<int> &X) { X.print(std::cout); });
                break;
            }
            case '5': {
                std::cout << "enter max area: ";
                std::cin >> S;
                std::cout <<"number of elements with area < than " << S << ": " << std::count_if(q.begin(), q.end(), [=](Octagon<int>& X){return X.area() < S;}) << std::endl;
                break;
            }
            default:
                std::cout << "Incorrect option." << std::endl;
                break;
        }
    }
    return 0;
}