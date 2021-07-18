#pragma once
#include <iostream>
using namespace std;

class Money {
private:
	long rubles;
	int kopecks;

public:
	Money() : rubles(0), kopecks(0) {} // ����������� �� ���������
	Money(long int one, int two) : rubles(one+=two/100), kopecks(two = two % 100) {} // ����������� �� �������� ���������
	~Money() {} // ����������

	void print() { // ������� ������ �� �����
		cout << rubles << "," << kopecks << endl;
	}

	friend istream& operator>>(istream& is, Money& cash) { // ������������� ������� ���������� ��������� �����
		cout << "Enter the amount of rubles and kopecks: ";
		is >> cash.rubles;
		is >> cash.kopecks;
		if (cash.kopecks / 100 != 0) { // ���� ������ ������ 100, ��
			cash.rubles += cash.kopecks / 100; // ����� ����� �� ������� �� 100 ��� ���-�� ������
			cash.kopecks = cash.kopecks % 100; // ������� �� ������� �� 100 - ���-�� ���������� ������
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const Money& cash) { // ������������� ������� ���������� ��������� ������
		os << cash.rubles << "," << cash.kopecks;
		return os;
	}

	const Money& operator=(const Money& cash) { // ���������� �������� ������������
		rubles = cash.rubles; // ������������ �� �����
		kopecks = cash.kopecks;
		return *this;
	}

	bool operator==(const Money& cash) const {
		return (rubles == cash.rubles and kopecks == cash.kopecks);
	}

	bool operator!=(const Money& cash) const {
		return !(*this == cash); // ���������� ���������� ���������
	}

	bool operator>=(const Money& cash) const {
		if (rubles > cash.rubles) // ������������� �� ������
			return true;
		else if (rubles == cash.rubles) // ���� ��� ����� - ������� �������
			if (kopecks > cash.kopecks)
			return true;
		return false;
	}

	bool operator>(const Money& cash) const {
		return ((*this >= cash) && (*this != cash)); // >= � != ���� >
	}

	bool operator<(const Money& cash) const {
		return !(*this >= cash); // !(>=) ���� <
	}

	bool operator<=(const Money& cash) const {
		return (!(*this >= cash) || *this == cash); // !(>=) ��� == ���� < ��� == (<=)
	}
};
