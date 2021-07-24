#pragma once
#include <iostream>

using namespace std;

template <class Deque>
class Iterator {
public:
	using ValueType = typename Deque::ValueType; // Упрощаю себе задачу, чтобы прописывать на одно слово меньше

	ValueType* myptr;

	Iterator(ValueType* ptr) : myptr(ptr) {}
	~Iterator() {}

	Iterator& operator++() { // Перегрузка оператора ++ (постфиксный инкремент)
		myptr = myptr->next;
		return *this;
	}
	
	Iterator operator++(int) { // Префиксный инекремент
		Iterator temp = *this;
		++(*this);
		return temp;
	}

	Iterator& operator--() { // Постфиксный декремент
		myptr = myptr->prev;
		return *this;
	}

	Iterator operator--(int) { // Префиксный декремент
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

	bool empty() { // Метод, проверяющий контейнер на пустоту
		if (myptr) return false; // Ведь если там ничего нет, то и указывать не на что, а значит myptr будет NULL
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

	void operator= (const Iterator& second) { // Перегрузка оператора присваивания
		this->myptr = second.myptr;
	}
};

template <class Type> // Реализация шаблона контейнера двусторонней очереди
class Deque {
public:
	using iterator = Iterator<Deque<Type>>; // Чтобы не прописывать так много

	struct Node { // Создание списка, на котором будет базироваться двусторонняя очередь
		Node* next, * prev;
		Type data;
		explicit Node(const Type& data) : next(NULL), prev(NULL), data(data) {}
		Node() {};
		static Node* create(Type data) { // Функция создания нового узла списка
			Node* unit = new Node;
			unit->data = data;
			unit->prev = unit->next = NULL;
			return unit;
		}
	};

	Node* head, *tail;
	int volume; // Переменная для хренения объема контейнера

	using ValueType = Node;


	explicit Deque() : head(NULL), tail(NULL), volume(0) {}
	~Deque() { clear(); }

	const Type& getfirst() const { return head->data; } // Метод, позволяющий получить элемент с начала очереди

	const Type& getlast() const { return tail->data; } // С конца очереди

	bool isempty() const { return head == NULL; } // Метод, проверяющий пустоту контейнера

	int size() const { return volume; } // Метод, возвращающий размер deque

	void insertfirst(const Type& value) { // Метод, позволяющий вставить элемент в начало
		Node* unit = new Node(value); // Создание нового узла списка
		if (!head) head = tail = unit; // Если дека пуста, то там появится элемент, который будет и последним, и первым одновременно
		else { // Если не пуста
			unit->next = head; // Следующий за новым элементом теперь -- бывшая голова
			head->prev = unit; // А предыдущий элемент головы -- новый
			head = unit; // Новый элемент -- новая голова списка
		}
		volume++; // Увеличить объем, так как добавили элемент
	}

	void insertlast(const Type& value) { // Метод, позволяющий вставить элемент в конец
		Node* unit = new Node(value); // Работает аналогично предыдущему, только с концом
		if (!head) head = tail = unit;
		else {
			unit->prev = tail;
			tail->next = unit;
			tail = unit;
		}
		volume++;
	}

	void popfirst() { // Метод, позволяющий извлечь элемент из начала
		if (head) { // Если голова списка существует
			Node* temp = head; // Буферный элемент
			head = head->next; // Смещаем голову
			delete temp;
		}
		if (!head) tail = NULL; // А если был убран последний элемент, то деки не осталось в принципе, поэтому зануляем указали
		--volume; // Уменьшаем объём
	}

	void poplast() { // Метод, позволяющий извлечь элемент из конца
		if (tail) { // Если конец вообще существует
			Node* temp = tail;
			tail = tail->prev;
			delete temp;
		}
		if (!tail) head = NULL;
		--volume;
	}

	void clear() { // Метод, очищающий очередь целиком 
		while (!isempty() || head) popfirst(); // Пока очередь не пуста или существует голова списка, достаём первый элемент
	}

	void show() { // Метод, выводящий очередь на экран
		Node* temp = head;
		while (temp != tail->next) { // Перемещаемся по списку внутри деки и выводим элемент на экран
			cout << temp->data << endl;
			temp = temp->next; // Смещаемся на следующий элемент
		}
	}


	friend ostream& operator<<(ostream& os, Deque<Type>& deq) { // Перегрузка оператора вывода
		deq.show(); // Просто используется функция вывода содержимого на экран
		return os;
	}

	friend istream& operator>>(istream& is, Deque<Type>& deq) { // Перегрузка оператора ввода
		int n = 0;
		Type elem = 0;
		cout << "Enter the amount of elements in deque: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Enter element: ";
			cin >> elem;
			deq.insertlast(elem); // Добавление нового элемента будет идти в конец дека
		}
		return is;
	}

	// Итераторы пошли

	iterator begin() noexcept { // Начало -- голова списка, на котором построена двусвязная очередь
		return iterator(head);
	}

	iterator end() noexcept { // Конец -- хвост
		return iterator(tail);
	}

	iterator erase(iterator pos) { // Метод erase удаляет элемент, стоящий на pos
		if (pos.myptr) {
			Node* temp = pos->next;
			if (pos == head) popfirst();
			else {
				pos->prev->next = pos->next; // Переназначаем связи, исключая pos из цепочки 
				pos->next->prev = pos->prev;
				--volume; // Уменьшаем объем
				delete pos.myptr;
			}
			return temp; // Возвращаем итератор на следущий за pos элемент
		}
		else return begin();
	}

	iterator erase(iterator begin, iterator end) { // Эта версия erase удаляет элементы от begin и до end
		while (begin != end) begin = erase(begin);
		return end;
	}

	iterator insert(iterator pos, const Type& key) { // Функция insert вставляет элемент перед pos
			Node* unit = Node::create(key); // Создаётся новый узел списка для деки
			unit->prev = pos->prev; // Перед(!) pos
			unit->next = pos.myptr; // Установка связей
			pos->prev->next = unit; // Следующий за предыдущим для pos теперь станет новый элемент с данными key
			pos->prev = unit; 
			pos.myptr = unit;
			++volume;
			return pos;
	}

	void swap(Deque* dq) {
		int tmpvol = this->volume; // Буфер для обмена
		iterator beginiter = this->begin(); // Начало становится началом
		iterator enditer = this->end(); // Конец -- концом
		this->head = dq->head; // Обмениваем голову у первого контейнера на голову второго
		this->tail = dq->tail; // Хвост первого на хвост второго
		this->volume = dq->volume; // Задаём размер
		dq->head = beginiter.myptr; // Второму отдаём указатель на голову первого
		dq->tail = enditer.myptr; // Указатель на хвост первого
		dq->volume = tmpvol; // И объём из буфера
	}
};
