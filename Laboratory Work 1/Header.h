#pragma once // ����� Header ������������� ���� 1 ���
#include <string>

using namespace std;

typedef struct { // ���������� ��������� ���
	string f;
	string i;
	string o;
} FIO;

class Personal { 
public:
	FIO fio; // ��������� ��������� ��� � �����
	string position;
	string branch;
	double salary = 0;

	Personal(){} // �����������
	~Personal() {} // ����������

	bool operator > (const Personal&) const; // ��������� ������� ���������� ����������
	bool operator < (const Personal&) const;
	bool operator >= (const Personal&) const;
	bool operator <= (const Personal&) const;
	bool operator == (const Personal&) const;
	bool operator != (const Personal&) const;
};

Personal *insertionSort(Personal *prs, int n); // �������� ������� ���������� ���������
Personal *shakerSorting(Personal *prs, int n); // �������� ������� ������-����������
void display(Personal *prs, int n); // �������� ������� ������ ������� �� �����
