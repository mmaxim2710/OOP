#include <iostream>
#include "money.h"

#define UNUSED(variable) (void)variable

int main(int argc, char** argv) {
	
	Money a1;
	Money a2;
	float arg;

	std::cout << "First summ:" << std::endl;
	//a1.get(std::cin);
	std::cin >> a1;
	std::cout << "Second summ:" << std::endl;
	//a2.get(std::cin);
	std::cin >> a2;
	std::cout << "Number to div and multiply" << std::endl;
	std::cin >> arg;
	if(arg == 0){
		std::cout << "cannot be divided by zero" << std::endl;
		return 0;
	}
	std::cout << std::endl;
	
	//a1.show(std::cout);
	std::cout << a1;
	//a2.show(std::cout);
	std::cout << a2;

	//(a1 + a2).show(std::cout);
	std::cout << a1 + a2;

	//(a1 - a2).show(std::cout);
	std::cout << a1 - a2;

	std::cout << a1 / a2 << std::endl;

	//(a1 / arg).show(std::cout);
	std::cout << a1 / arg;

	//(a1 * arg).show(std::cout);
	std::cout << a1 * arg << std::endl;

	if(a1 < a2) std::cout << "<:" << std::endl;
	else std::cout << "<: false" << std::endl;

	if(a1 > a2) std::cout << ">: true" << std::endl;
	else std::cout << ">: false" << std::endl;

	if(a1 <= a2) std::cout << "<=: true" << std::endl;
	else std::cout << "<=: false" << std::endl;

	if(a1 >= a2) std::cout << ">=: true" << std::endl;
	else std::cout << ">=: false" << std::endl;

	if(a1 == a2) std::cout << "==: true" << std::endl;
	else std::cout << "==: false" << std::endl;

	if(a1 != a2) std::cout << "!=: true" << std::endl;
	else std::cout << "!=: false" << std::endl;


	long double sum;
	std::cout << "insert summ (+50 cops): ";
	std::cin >> sum;
	std::cout << sum + 50.00_toCop << std::endl;

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}

// перегрузить оператор вывода