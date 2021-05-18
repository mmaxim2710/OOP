#include <iostream>
#include "money.h"

#define UNUSED(variable) (void)variable

int main(int argc, char** argv) {
	
	Money a1;
	Money a2;
	double arg;

	std::cout << "First summ:" << std::endl;
	a1.get(std::cin);
	std::cout << "Second summ:" << std::endl;
	a2.get(std::cin);
	std::cout << "Number to div and multiply" << std::endl;
	std::cin >> arg;
	if(arg == 0){
		std::cout << "cannot be divided by zero" << std::endl;
		return 0;
	}
	std::cout << std::endl;

	if(a1.roub_get(a1) < a2.roub_get(a2) || (a1.roub_get(a1) == a2.roub_get(a2) && a1.cop_get(a1) < a2.cop_get(a2))) {
		std::cout << "First summ less than second summ" << std::endl;
		return 0;
	}
	
	a1.show(std::cout);
	a2.show(std::cout);
	
	a1.Plus(a2).show(std::cout);

	a1.Minus(a2).show(std::cout);

	std::cout << a1.Div(a2) << std::endl;

	a1.DivN(arg).show(std::cout);

	a1.Mult(arg).show(std::cout);

	if(a1.opLess(a2)) std::cout << "<:" << std::endl;
	else std::cout << "<: false" << std::endl;

	if(a1.opMore(a2)) std::cout << ">: true" << std::endl;
	else std::cout << ">: false" << std::endl;

	if(a1.opLessEqual(a2)) std::cout << "<=: true" << std::endl;
	else std::cout << "<=: false" << std::endl;

	if(a1.opMoreEqual(a2)) std::cout << ">=: true" << std::endl;
	else std::cout << ">=: false" << std::endl;

	if(a1.opEqual(a2)) std::cout << "==: true" << std::endl;
	else std::cout << "==: false" << std::endl;

	if(a1.opNotEqual(a2)) std::cout << "!=: true" << std::endl;
	else std::cout << "!=: false" << std::endl;

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}