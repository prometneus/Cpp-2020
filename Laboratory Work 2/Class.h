#pragma once
#include <iostream>
using namespace std;

class Money {
private:
	long rubles;
	int kopecks;

public:
	Money() : rubles(0), kopecks(0) {} // Конструктор по умолчанию
	Money(long int one, int two) : rubles(one+=two/100), kopecks(two = two % 100) {} // Конструктор по заданным значениям
	~Money() {} // Деструктор

	void print() { // Функция вывода на экран
		cout << rubles << "," << kopecks << endl;
	}

	friend istream& operator>>(istream& is, Money& cash) { // Дружественная функция перегрузки оператора ввода
		cout << "Enter the amount of rubles and kopecks: ";
		is >> cash.rubles;
		is >> cash.kopecks;
		if (cash.kopecks / 100 != 0) { // Если копеек больше 100, то
			cash.rubles += cash.kopecks / 100; // Целая часть от деления на 100 это кол-во рублей
			cash.kopecks = cash.kopecks % 100; // Остаток от деления на 100 - кол-во оставшихся копеек
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const Money& cash) { // Дружественная функция перегрузки оператора вывода
		os << cash.rubles << "," << cash.kopecks;
		return os;
	}

	const Money& operator=(const Money& cash) { // Перегрузка операции присваивания
		rubles = cash.rubles; // Присваивание по полям
		kopecks = cash.kopecks;
		return *this;
	}

	bool operator==(const Money& cash) const {
		return (rubles == cash.rubles and kopecks == cash.kopecks);
	}

	bool operator!=(const Money& cash) const {
		return !(*this == cash); // Перегрузка логической инверсией
	}

	bool operator>=(const Money& cash) const {
		if (rubles > cash.rubles) // Рассматриваем по рублям
			return true;
		else if (rubles == cash.rubles) // Если они равны - смотрим копейки
			if (kopecks > cash.kopecks)
			return true;
		return false;
	}

	bool operator>(const Money& cash) const {
		return ((*this >= cash) && (*this != cash)); // >= и != дает >
	}

	bool operator<(const Money& cash) const {
		return !(*this >= cash); // !(>=) дает <
	}

	bool operator<=(const Money& cash) const {
		return (!(*this >= cash) || *this == cash); // !(>=) или == дает < или == (<=)
	}
};
