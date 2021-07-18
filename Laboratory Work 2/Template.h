#pragma once
#include <iostream>

using namespace std;

template <typename Type>
class Queue {
	struct node {
		Type data; // ���� � ������ ��� �������� �������� ���������� ��������
		node* next = NULL; // ��������� �� ��������� �������
	};
private:
	node* pointer; // ��������� �� ��������� ������� ��� �������
public:
	Queue() : pointer(NULL) {} // ����������� �� ���������
	explicit Queue(Type data) { push(data); } // ����������� �� ����������
	Queue(const Queue<Type>& q) { // ����������� �����������
		*this = q; // ������������� �������� ������������
	}
	~Queue() { // ����������, ������ ���������� ������ ������� �������
		cout << "Destroyer" << endl;
		while (!isempty()) { this->pop(); } //���� ������� �� �����, ������� �������� ������
	} 
	
	void push(Type data) { // ���������� ���� � �������
		node* one = new node();
		one->data = data;
		if (!pointer) { // ���� ��������� ����
			pointer = one; // ������� �����
			pointer->next = pointer; // "��������", ��� ��� ������� ����� ����
		}
		else {
			one->next = pointer->next; // ������������� ����� ��� ������ ��������
			pointer = pointer->next = one; // ������������� ����� ��� ���������: ��������� ������� ����� one
		}
	}

	Type& show() { // ����������� �������� ��������
		if (size() != 0) {
			if (pointer) return pointer->next->data; // ���� ��������� ����������, �� ������� ������ ������� �������� �������
		}
	}

	bool isempty() const { // �������� �� �������
		return(!pointer); // ���� ��������� �� ������� ����������, �� ������� �� �����
	}

	void clear() { // ������� �������
		if (size() != 0) {
			while (!this->isempty()) {// ���� ������� �� �����
				this->pop(); // ������� ����������� �� ������
				cout << "Queue was cleared" << endl;
			}
		}
	}

	void pop() { // ����� ������� ������� �� ������
			if (pointer == pointer->next) { // ���� ������ ��� ���������
				pointer = NULL;
				delete pointer; // ������� ���������
				return;
			}
			else {
				node* temp = pointer->next; // ���������� ��������� �� ��������� �������
				pointer->next = temp->next; // ������ ��������� ������� ����� pointer ����� ����� �������
				temp = NULL; // ������� ���������
				delete temp; // ������� ���������
			}
	}

	int size() const { // ����������� �������
		int count = 0; // �������
		if (!pointer) { // ���� ������� �����, ������� 0
			count = 0;
			return count;
		}
		const node* iter = pointer->next; // �������������� �������
		do {
			count++;
			iter = iter->next; // �������� �������
		} while (iter != pointer->next); // ���� �� ������� ������ ����
		return count;
	}

	 friend ostream& operator << (ostream& os, Queue<Type>& q) { // ���������� ��������� ������
		 if (q.size() != 0) {
			 os << "Queue's filling:" << endl;
			 const node* iter = q.pointer->next;
			 do {
				 os << iter->data << endl; // �������� ���������� �������
				 iter = iter->next; // �������� �������
			 } while (iter != q.pointer->next); // ���� ��������� ����� �� ������ ��������� �� ������ �������
		 }
		return os;
	}
	
	friend istream& operator >> (istream& is, Queue<Type>& q) { // ���������� ��������� �����
		Type x; // ������� ����������, � ������� ����� ���-�� ��������
		is >> x;
		q.push(x); // �������� ������� ���������� ���� � �������
		return is;
	}
	
	const Queue<Type>& operator=(const Queue<Type>& q) { // ���������� �������� ������������
		if (this == &q) return *this;
		pointer = q.pointer; // ����������� ���������
		return *this;
	}
};
