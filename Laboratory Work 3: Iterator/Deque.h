#pragma once
#include <iostream>

using namespace std;

template <class Deque>
class Iterator {
public:
	using ValueType = typename Deque::ValueType; // ������� ���� ������, ����� ����������� �� ���� ����� ������

	ValueType* myptr;

	Iterator(ValueType* ptr) : myptr(ptr) {}
	~Iterator() {}

	Iterator& operator++() { // ���������� ��������� ++ (����������� ���������)
		myptr = myptr->next;
		return *this;
	}
	
	Iterator operator++(int) { // ���������� ����������
		Iterator temp = *this;
		++(*this);
		return temp;
	}

	Iterator& operator--() { // ����������� ���������
		myptr = myptr->prev;
		return *this;
	}

	Iterator operator--(int) { // ���������� ���������
		Iterator temp = *this;
		--(*this);
		return temp;
	}

	ValueType& operator*() {
		return *myptr;
	}

	ValueType* operator->() {
		return myptr;
	}

	bool empty() { // �����, ����������� ��������� �� �������
		if (myptr) return false; // ���� ���� ��� ������ ���, �� � ��������� �� �� ���, � ������ myptr ����� NULL
		else return true;
	}


	bool operator == (const Iterator& second) const {
		return myptr == second.myptr;
	}

	bool operator != (const Iterator& second) const {
		return !(*this == second);
	}

	/*bool operator < (const Iterator& second) const {
		if ((*this <= second) and (*this != second)) return true;
		else return false;
	}

	bool operator > (const Iterator& second) const {
		if (!(*this < second) and (*this != second)) return true;
		else return false;
	}*/

	void operator= (const Iterator& second) { // ���������� ��������� ������������
		this->myptr = second.myptr;
	}
};

template <class Type> // ���������� ������� ���������� ������������ �������
class Deque {
public:
	using iterator = Iterator<Deque<Type>>; // ����� �� ����������� ��� �����

	struct Node { // �������� ������, �� ������� ����� ������������ ������������ �������
		Node* next, * prev;
		Type data;
		explicit Node(const Type& data) : next(NULL), prev(NULL), data(data) {}
		Node() {};
		static Node* create(Type data) { // ������� �������� ������ ���� ������
			Node* unit = new Node;
			unit->data = data;
			unit->prev = unit->next = NULL;
			return unit;
		}
	};

	Node* head, *tail;
	int volume; // ���������� ��� �������� ������ ����������

	using ValueType = Node;


	explicit Deque() : head(NULL), tail(NULL), volume(0) {}
	~Deque() { clear(); }

	const Type& getfirst() const { return head->data; } // �����, ����������� �������� ������� � ������ �������

	const Type& getlast() const { return tail->data; } // � ����� �������

	bool isempty() const { return head == NULL; } // �����, ����������� ������� ����������

	int size() const { return volume; } // �����, ������������ ������ deque

	void insertfirst(const Type& value) { // �����, ����������� �������� ������� � ������
		Node* unit = new Node(value); // �������� ������ ���� ������
		if (!head) head = tail = unit; // ���� ���� �����, �� ��� �������� �������, ������� ����� � ���������, � ������ ������������
		else { // ���� �� �����
			unit->next = head; // ��������� �� ����� ��������� ������ -- ������ ������
			head->prev = unit; // � ���������� ������� ������ -- �����
			head = unit; // ����� ������� -- ����� ������ ������
		}
		volume++; // ��������� �����, ��� ��� �������� �������
	}

	void insertlast(const Type& value) { // �����, ����������� �������� ������� � �����
		Node* unit = new Node(value); // �������� ���������� �����������, ������ � ������
		if (!head) head = tail = unit;
		else {
			unit->prev = tail;
			tail->next = unit;
			tail = unit;
		}
		volume++;
	}

	void popfirst() { // �����, ����������� ������� ������� �� ������
		if (head) { // ���� ������ ������ ����������
			Node* temp = head; // �������� �������
			head = head->next; // ������� ������
			delete temp;
		}
		if (!head) tail = NULL; // � ���� ��� ����� ��������� �������, �� ���� �� �������� � ��������, ������� �������� �������
		--volume; // ��������� �����
	}

	void poplast() { // �����, ����������� ������� ������� �� �����
		if (tail) { // ���� ����� ������ ����������
			Node* temp = tail;
			tail = tail->prev;
			delete temp;
		}
		if (!tail) head = NULL;
		--volume;
	}

	void clear() { // �����, ��������� ������� ������� 
		while (!isempty() || head) popfirst(); // ���� ������� �� ����� ��� ���������� ������ ������, ������ ������ �������
	}

	void show() { // �����, ��������� ������� �� �����
		Node* temp = head;
		while (temp != tail->next) { // ������������ �� ������ ������ ���� � ������� ������� �� �����
			cout << temp->data << endl;
			temp = temp->next; // ��������� �� ��������� �������
		}
	}


	friend ostream& operator<<(ostream& os, Deque<Type>& deq) { // ���������� ��������� ������
		deq.show(); // ������ ������������ ������� ������ ����������� �� �����
		return os;
	}

	friend istream& operator>>(istream& is, Deque<Type>& deq) { // ���������� ��������� �����
		int n = 0;
		Type elem = 0;
		cout << "Enter the amount of elements in deque: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Enter element: ";
			cin >> elem;
			deq.insertlast(elem); // ���������� ������ �������� ����� ���� � ����� ����
		}
		return is;
	}

	// ��������� �����

	iterator begin() noexcept { // ������ -- ������ ������, �� ������� ��������� ���������� �������
		return iterator(head);
	}

	iterator end() noexcept { // ����� -- �����
		return iterator(tail);
	}

	iterator erase(iterator pos) { // ����� erase ������� �������, ������� �� pos
		if (pos.myptr) {
			Node* temp = pos->next;
			if (pos == head) popfirst();
			else {
				pos->prev->next = pos->next; // ������������� �����, �������� pos �� ������� 
				pos->next->prev = pos->prev;
				--volume; // ��������� �����
				delete pos.myptr;
			}
			return temp; // ���������� �������� �� �������� �� pos �������
		}
		else return begin();
	}

	iterator erase(iterator begin, iterator end) { // ��� ������ erase ������� �������� �� begin � �� end
		while (begin != end) begin = erase(begin);
		return end;
	}

	iterator insert(iterator pos, const Type& key) { // ������� insert ��������� ������� ����� pos
			Node* unit = Node::create(key); // �������� ����� ���� ������ ��� ����
			unit->prev = pos->prev; // �����(!) pos
			unit->next = pos.myptr; // ��������� ������
			pos->prev->next = unit; // ��������� �� ���������� ��� pos ������ ������ ����� ������� � ������� key
			pos->prev = unit; 
			pos.myptr = unit;
			++volume;
			return pos;
	}

	void swap(Deque* dq) {
		int tmpvol = this->volume; // ����� ��� ������
		iterator beginiter = this->begin(); // ������ ���������� �������
		iterator enditer = this->end(); // ����� -- ������
		this->head = dq->head; // ���������� ������ � ������� ���������� �� ������ �������
		this->tail = dq->tail; // ����� ������� �� ����� �������
		this->volume = dq->volume; // ����� ������
		dq->head = beginiter.myptr; // ������� ����� ��������� �� ������ �������
		dq->tail = enditer.myptr; // ��������� �� ����� �������
		dq->volume = tmpvol; // � ����� �� ������
	}
};
