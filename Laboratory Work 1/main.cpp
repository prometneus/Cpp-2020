#include <string>
#include <iostream>
#include <fstream> // ��� ��������� ������
#include <ctime> // ��� clock
#include <cstdlib> // ��������� �xit
#include "Header.h"

using namespace std; // ������������ ����

int main() {
	unsigned long start, end, zeit1, zeit2; // ��� ��������� ����������
	int i = 0;
	ifstream f;

	f.open("Accounting.txt"); // ���������� � ������
	if (!f.is_open()) { // ���� �� ��������, ������� �������� �� ������
		cout << "File didn't open" << endl;
		exit(EXIT_FAILURE);
	}
	f.get(); // ������� ������ ��� �������� ����� �� �������
	if (f.eof()) { // ���� ���� ����, �������� �� ����
		cout << "File is empty" << endl;
		f.close(); // ������� ����
		return 1;
	}
	f.seekg(0, ios::beg); // ��������� � ������ �����
	
	int n;
	f >> n; // ���������� ������� ���� ������
	cout << "Database size " << n << endl << endl;

	Personal* p = new Personal[n];
	Personal* ap = new Personal[n];
	while (i < n && !f.eof()) { // ���������� ������ �� �����
		f >> p[i].fio.f;
		f >> p[i].fio.i;
		f >> p[i].fio.o;
		f >> p[i].salary;
		f >> p[i].branch;
		f >> p[i].position;
		f.get(); // ����� ������ �������� �� ����� ������
		i++; // ��� �����
	}

	f.close(); // �������� �����

	for (int i = 0; i < n; i++) {
		ap[i] = p[i]; // ����������� ������ ��� ����������
	}
	
	/*cout << "Massive" << endl; // ����� ������������ ����������� ���� ������
	display(p, n);
	cout << endl;*/

	start = clock(); // �������� ������ ����������
	p = insertionSort(p, n);
	end = clock(); // �������� �����
	zeit1 = end - start; // ����������� �� ���������� �����
	cout << "Time of insertion Sort - " << zeit1 << endl;
	
	start = clock();
	ap = shakerSorting(ap, n);
	end = clock();
	zeit2 = end - start;
	cout << "Time of shaker Sorting - " << zeit2 << endl;

	start = clock(); // ��������� ������� ���������� ��������� �� ��������������� �������
	p = insertionSort(p, n);
	end = clock(); 
	zeit1 = end - start; 
	cout << endl << "Time of insertion Sort on sorted array - " << zeit1 << endl;

	start = clock(); // ��������� ������� ���������� �������� �� ��������������� �������
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

	delete[] p; // ������������ ������
	delete[] ap;
}
