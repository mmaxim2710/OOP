#include <iostream>
#include <algorithm>
#include <map>
#include "octagon.h"
#include "containers/stack.h"
#include "my_allocator.h"

int main() {
    size_t n;
    int S;
    char option = 'a';
    containers::stack<Octagon<int>, allocators::my_allocator<Octagon<int>, 800>> s;
    Octagon<int> oct{};
    while (option != '0') {
        std::cout << "> Choose option (h for help)" << std::endl;
        std:: cin >> option;
        switch (option) {

            case 'h':
                std::cout << "q. Exit\n"
                << "h. Help\n"
                << "1. Push element in stack\n"
                << "2. Delete element from the stack\n"
                << "3. Delete element from the chosen position\n"
                << "4. Print out stack\n"
                << "5. Print out N of elem., which area < than current value" << std::endl;
                break;

            case '1': {
                std::cout << "Put your octagon: " << std::endl;
                oct = Octagon<int>(std::cin);
                s.push(oct);
                break;
            }

            case '2': {
                s.pop();
                break;
            }

            case '3': {
                std::cout << "enter position to delete: ";
                std::cin >> n;
                s.delete_by_number(n);
                break;
            }

            case '4': {
                std::for_each(s.begin(), s.end(), [](Octagon<int> &X) {
                X.print(std::cout); 
                });
                break;
            }

            case '5': {
                std::cout << "Enter number of area for searching: ";
                std::cin >> S;
                std::cout <<"The number of elements with area < than " << S << ": " << std::count_if(s.begin(), s.end(), [=](Octagon<int>& X){return X.area() < S;}) << "\n";
                break;
            }

            case 'q':
                break;

            default:
                std::cout << "no such option. Try m for man" << std::endl;
                break;

        }
    }
    return 0;
}