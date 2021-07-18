#include <string>
#include <iostream> // Для cin & cout
#include <fstream> // Для файлового вывода
#include "Header.h"

using namespace std;

bool Personal::operator >(const Personal& prs) const {
	if ((*this >= prs) && !(*this == prs)) return true; //  Перегрузка логической инверсией
	return false; // Если больше/равно и если НЕ равно, то больше
}

bool Personal::operator <(const Personal& prs) const {
	if (!(*this >= prs)) return true; //  Перегрузка логической инверсией
	return false; // Если НЕ больше/равно, то меньше
}

bool Personal::operator >=(const Personal& prs) const {
	if (fio.f > prs.fio.f) // Если фамилия >, то тру
		return true;
	else if (fio.f == prs.fio.f) // Если фамилии равны, то перейти к другому полю для сравнения
		if (fio.i > prs.fio.i) // Если имя >, то тру
			return true;
		else if (fio.i == prs.fio.i) // Если имена равны, то перейти к другому полю для сравнения
			if (fio.o > prs.fio.o)
				return true;
			else if (fio.o == prs.fio.o)
				if (salary > prs.salary)
					return true;
				else if (salary == prs.salary)
					if (branch > prs.branch)
						return true;
					else if (branch == prs.branch)
						if (position > prs.position)
							return true;
	return false;
}

bool Personal::operator <=(const Personal& prs)const
{
	if (!(*this >= prs) || *this == prs) //  Перегрузка логической инверсией 
		return true; // Если НЕ больше/равно, то меньше. Или равно
	return false;
}

bool Personal::operator !=(const Personal& prs) const {
	if (!(*this == prs)) return true; //  Перегрузка логической инверсией
	return false; // Если НЕ равно
}

bool Personal::operator ==(const Personal& prs) const { // Перегрузка проверкой для каждого поля структуры/класса
	if (fio.f == prs.fio.f) // Если совпало имя
	 if (fio.i == prs.fio.i) // И фамилия
		if (fio.o == prs.fio.o) // И отчество
			if (salary == prs.salary) // И зарплата
				if (branch == prs.branch) // И место работы
					if (position == prs.position) return true; // И должность, то только тогда элементы равны
	return false;
}

Personal *insertionSort(Personal* prs, int n) {
	for (int i = 1; i < n; ++i) {
		Personal element = prs[i]; // Инициализируем временную переменную текущим значением эл - та массива
		int j = i; // Адрес предыдущего элемента
		while (j > 0 && prs[j - 1] > element) { // Пока индекс != 0 и предыдущий элемент > текущего
			prs[j] = prs[j - 1]; // Меняем местами
			--j;
		}
		prs[j] = element;
	}
	return prs;
}

Personal *shakerSorting(Personal* prs, int n) {
	int left = 0; // Устанавливаем каретку на первый элемент слева
	int right = n - 1; // И на последний справа
	while (left <= right) { // Пока правый больше левого
		for (int i = right; i > left; --i) { // Проход пузырьком справа налево в поисках наименьшего
			if (prs[i - 1] > prs[i]) {
				swap(prs[i - 1], prs[i]); // Меняем местами
			}
		}
		++left; // Первый элемент будет минимальным, уже можно не учитывать, поэтому начнем со второго
		for (int i = left; i < right; ++i) { // Пока левый меньше правого
			if (prs[i] > prs[i + 1]) { // Проход пузырьком слева направо в поисках максимального
				swap(prs[i], prs[i + 1]); // Меняем местами
			}
		}
		--right; // последний элемент будет максимальным, поэтому будем искать максимальный элемент среди неотсортированных
	}
	return prs;
}

void display(Personal* prs, int n) { // Функция вывода содержимого базы данных
	for (int i = 0; i < n; i++) {
		cout << "FIO:" << prs[i].fio.f << " " << prs[i].fio.i << " " << prs[i].fio.o << endl;
		cout << prs[i].branch << " " << prs[i].position << " " << prs[i].salary << endl;
		cout << endl;
	}
}