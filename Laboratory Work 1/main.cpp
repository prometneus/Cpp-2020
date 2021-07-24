#include <string>
#include <iostream>
#include <fstream> // Для файлового вывода
#include <ctime> // Для clock
#include <cstdlib> // Поддержка еxit
#include "Header.h"

using namespace std; // Пространство имен

int main() {
	unsigned long start, end, zeit1, zeit2; // Для временнЫх переменных
	int i = 0;
	ifstream f;

	f.open("Accounting.txt"); // Ассоциация с файлом
	if (!f.is_open()) { // Если не открылся, вывести сведения об ошибке
		cout << "File didn't open" << endl;
		exit(EXIT_FAILURE);
	}
	f.get(); // Поймать пробел для проверки файла на пустоту
	if (f.eof()) { // Если файл пуст, написать об этом
		cout << "File is empty" << endl;
		f.close(); // Закрыть файл
		return 1;
	}
	f.seekg(0, ios::beg); // Вернуться в начало файла
	
	int n;
	f >> n; // Считывание размера базы данных
	cout << "Database size " << n << endl << endl;

	Personal* p = new Personal[n];
	Personal* ap = new Personal[n];
	while (i < n && !f.eof()) { // Считывание данных из файла
		f >> p[i].fio.f;
		f >> p[i].fio.i;
		f >> p[i].fio.o;
		f >> p[i].salary;
		f >> p[i].branch;
		f >> p[i].position;
		f.get(); // Ловим символ перехода на новую строку
		i++; // Шаг цикла
	}

	f.close(); // Закрытие файла

	for (int i = 0; i < n; i++) {
		ap[i] = p[i]; // Копирование данных для сортировок
	}
	
	/*cout << "Massive" << endl; // Вывод изначального содержимого базы данных
	display(p, n);
	cout << endl;*/

	start = clock(); // Засекаем начало сортировки
	p = insertionSort(p, n);
	end = clock(); // Засекаем конец
	zeit1 = end - start; // Затраченное на сортировку время
	cout << "Time of insertion Sort - " << zeit1 << endl;
	
	start = clock();
	ap = shakerSorting(ap, n);
	end = clock();
	zeit2 = end - start;
	cout << "Time of shaker Sorting - " << zeit2 << endl;

	start = clock(); // Измерение времени сортировки вставками на отсортированном массиве
	p = insertionSort(p, n);
	end = clock(); 
	zeit1 = end - start; 
	cout << endl << "Time of insertion Sort on sorted array - " << zeit1 << endl;

	start = clock(); // Измерение времени сортировки шейкером на отсортированном массиве
	ap = shakerSorting(ap, n);
	end = clock();
	zeit2 = end - start;
	cout << "Time of shaker Sorting on sorted array - " << zeit2 << endl;

	/*cout << endl << "Sorted Massive Insertion" << endl;
	display(p, n);
	cout << endl;

	cout << endl << "Sorted Massive Shaker" << endl;
	display(ap, n);
	cout << endl;*/

	delete[] p; // Освобождение памяти
	delete[] ap;
}
