#include <string>
#include <iostream> // ��� cin & cout
#include <fstream> // ��� ��������� ������
#include "Header.h"

using namespace std;

bool Personal::operator >(const Personal& prs) const {
	if ((*this >= prs) && !(*this == prs)) return true; //  ���������� ���������� ���������
	return false; // ���� ������/����� � ���� �� �����, �� ������
}

bool Personal::operator <(const Personal& prs) const {
	if (!(*this >= prs)) return true; //  ���������� ���������� ���������
	return false; // ���� �� ������/�����, �� ������
}

bool Personal::operator >=(const Personal& prs) const {
	if (fio.f > prs.fio.f) // ���� ������� >, �� ���
		return true;
	else if (fio.f == prs.fio.f) // ���� ������� �����, �� ������� � ������� ���� ��� ���������
		if (fio.i > prs.fio.i) // ���� ��� >, �� ���
			return true;
		else if (fio.i == prs.fio.i) // ���� ����� �����, �� ������� � ������� ���� ��� ���������
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
	if (!(*this >= prs) || *this == prs) //  ���������� ���������� ��������� 
		return true; // ���� �� ������/�����, �� ������. ��� �����
	return false;
}

bool Personal::operator !=(const Personal& prs) const {
	if (!(*this == prs)) return true; //  ���������� ���������� ���������
	return false; // ���� �� �����
}

bool Personal::operator ==(const Personal& prs) const { // ���������� ��������� ��� ������� ���� ���������/������
	if (fio.f == prs.fio.f) // ���� ������� ���
	 if (fio.i == prs.fio.i) // � �������
		if (fio.o == prs.fio.o) // � ��������
			if (salary == prs.salary) // � ��������
				if (branch == prs.branch) // � ����� ������
					if (position == prs.position) return true; // � ���������, �� ������ ����� �������� �����
	return false;
}

Personal *insertionSort(Personal* prs, int n) {
	for (int i = 1; i < n; ++i) {
		Personal element = prs[i]; // �������������� ��������� ���������� ������� ��������� �� - �� �������
		int j = i; // ����� ����������� ��������
		while (j > 0 && prs[j - 1] > element) { // ���� ������ != 0 � ���������� ������� > ��������
			prs[j] = prs[j - 1]; // ������ �������
			--j;
		}
		prs[j] = element;
	}
	return prs;
}

Personal *shakerSorting(Personal* prs, int n) {
	int left = 0; // ������������� ������� �� ������ ������� �����
	int right = n - 1; // � �� ��������� ������
	while (left <= right) { // ���� ������ ������ ������
		for (int i = right; i > left; --i) { // ������ ��������� ������ ������ � ������� �����������
			if (prs[i - 1] > prs[i]) {
				swap(prs[i - 1], prs[i]); // ������ �������
			}
		}
		++left; // ������ ������� ����� �����������, ��� ����� �� ���������, ������� ������ �� �������
		for (int i = left; i < right; ++i) { // ���� ����� ������ �������
			if (prs[i] > prs[i + 1]) { // ������ ��������� ����� ������� � ������� �������������
				swap(prs[i], prs[i + 1]); // ������ �������
			}
		}
		--right; // ��������� ������� ����� ������������, ������� ����� ������ ������������ ������� ����� �����������������
	}
	return prs;
}

void display(Personal* prs, int n) { // ������� ������ ����������� ���� ������
	for (int i = 0; i < n; i++) {
		cout << "FIO:" << prs[i].fio.f << " " << prs[i].fio.i << " " << prs[i].fio.o << endl;
		cout << prs[i].branch << " " << prs[i].position << " " << prs[i].salary << endl;
		cout << endl;
	}
}