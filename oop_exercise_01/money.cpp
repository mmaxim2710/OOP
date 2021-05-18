#include "money.h"

unsigned long long Money::roub_get(const Money& a) {
	return a.roub;
}

uint16_t Money::cop_get(const Money& a) {
	return a.cop;
}

void Money::get(std::istream& is) {
	unsigned long long temp_roub; 
    uint16_t temp_cop;
    char temp;
    is >> temp_roub >> temp >> temp_cop;
    this->roub = temp_roub;
    this->cop = temp_cop;
} 

void Money::show(std::ostream& os) const {
	os << roub << ",";
	if(cop <= 0) {
		os << "00" << std::endl;
	}
	else os << cop << std::endl;
}


Money Money::Plus(const Money& a2) {
	Money temp;
	temp.roub = this->roub + a2.roub;
	temp.cop = this->cop + a2.cop;
	if(temp.cop >= 100) {
		temp.roub++;
		temp.cop -= 100;
	}
	return temp;
}

Money Money::Minus(const Money& a2) {
	Money temp;
	temp.roub = this->roub - a2.roub;
	if(this->cop < a2.cop) {
		temp.roub--;
		this->cop += 100;
		temp.cop = this->cop - a2.cop;
		this->cop -= 100;
	}
	else temp.cop = this->cop - a2.cop;
	return temp;
}

double Money::Div(const Money& a2) {
	double temp, a, b;
	a = ((this->roub * 100) + this->cop);
	b = ((a2.roub * 100) + a2.cop);
	temp = a / b;
	return temp;
}

Money Money::DivN(double arg) {
	Money temp;
	double tempN;
	tempN = (((this->roub * 100) + this->cop) / arg) / 100;
	temp.roub = (int)tempN;
	temp.cop = (tempN - (int)tempN) * 100;
	return temp;
}

Money Money::Mult(double arg) {
	Money temp;
	double tempN;
	tempN = (((this->roub * 100) + this->cop) * arg) / 100;
	temp.roub = (int)tempN;
	temp.cop = (tempN - (int)tempN) * 100;
	return temp;
}

bool Money::opLess(const Money& a2) {
	return (this->roub < a2.roub || (this->roub == a2.roub && this->cop < a2.cop));
}

bool Money::opMore(const Money& a2) {
	return (this->roub > a2.roub || (this->roub == a2.roub && this->cop > a2.cop));
}

bool Money::opLessEqual(const Money& a2) {
	return (this->roub <= a2.roub || (this->roub == a2.roub && this->cop <= a2.cop));
}

bool Money::opMoreEqual(const Money& a2) {
	return (this->roub >= a2.roub || (this->roub == a2.roub && this->cop >= a2.cop));
}

bool Money::opEqual(const Money& a2) {
	return (this->roub == a2.roub && this->cop == a2.cop);
}

bool Money::opNotEqual(const Money& a2) {
	return (this-> roub != a2.roub || this->cop !=a2.cop);
}