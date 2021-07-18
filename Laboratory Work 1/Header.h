#pragma once // Чтобы Header использовался лишь 1 раз
#include <string>

using namespace std;

typedef struct { // Объявление структуры ФИО
	string f;
	string i;
	string o;
} FIO;

class Personal { 
public:
	FIO fio; // Включение структуры ФИО в класс
	string position;
	string branch;
	double salary = 0;

	Personal(){} // Конструктор
	~Personal() {} // Деструктор

	bool operator > (const Personal&) const; // Прототипы функций перегрузки операторов
	bool operator < (const Personal&) const;
	bool operator >= (const Personal&) const;
	bool operator <= (const Personal&) const;
	bool operator == (const Personal&) const;
	bool operator != (const Personal&) const;
};

Personal *insertionSort(Personal *prs, int n); // Прототип функции сортировки вставками
Personal *shakerSorting(Personal *prs, int n); // Прототип функции шейкер-сортировки
void display(Personal *prs, int n); // Прототип функции вывода массива на экран
