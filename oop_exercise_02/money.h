#ifndef D_MONEY_H_
#define D_MONEY_H_

#include <iostream>

class Money {
	private:
		unsigned long long roub; // количество рублей
		uint16_t cop; // количество копеек
	public:
		Money() {
			roub = 0;
			cop = 0;
		}
		unsigned long long roub_get(const Money& a);
		uint16_t cop_get(const Money& a);
		void get(std::istream& is); // Получить сумму std::istream&
		void show(std::ostream& os) const; // Вывести сумму
		Money operator+(const Money& a2); // сложение сумм
		Money operator-(const Money& a2); // вычитание сумм
		double operator/(const Money& a2); // Деление 2х сумм
		Money operator/(double arg); // Деление суммы на число
		Money operator*(double arg); // Умножение суммы на число
		bool operator<(const Money& a2); // <
		bool operator>(const Money& a2); // >
		bool operator<=(const Money& a2); // <=
		bool operator>=(const Money& a2); // >=
		bool operator==(const Money& a2); // ==
		bool operator!=(const Money& a2); // !=
		friend std::ostream& operator<<(std::ostream& os, const Money& a2);
		friend std::istream& operator>>(std::istream& is, Money& a);
};

long double operator""_toCop(long double cop);

#endif