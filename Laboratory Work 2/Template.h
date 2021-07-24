#pragma once
#include <iostream>

using namespace std;

template <typename Type>
class Queue {
	struct node {
		Type data; // Поле в списке для хранения значений введенного элемента
		node* next = NULL; // Указатель на следующий элемент
	};
private:
	node* pointer; // Указатель на следующий элемент для очереди
public:
	Queue() : pointer(NULL) {} // Конструктор по умолчанию
	explicit Queue(Type data) { push(data); } // Конструктор со значениями
	Queue(const Queue<Type>& q) { // Конструктор копирования
		*this = q; // Перегруженный оператор присваивания
	}
	~Queue() { // Деструктор, внутри происходит полная очистка очереди
		cout << "Destroyer" << endl;
		while (!isempty()) { this->pop(); } //Пока очередь не пуста, достаем элементы сверху
	} 
	
	void push(Type data) { // Добавление узла в очередь
		node* one = new node();
		one->data = data;
		if (!pointer) { // Если указатель пуст
			pointer = one; // Создаем связь
			pointer->next = pointer; // "Кольцуем", так как элемент всего один
		}
		else {
			one->next = pointer->next; // Устанавливаем связь для нового элемента
			pointer = pointer->next = one; // Устанавливаем связь для указателя: следующий элемент будет one
		}
	}

	Type& show() { // Определение верхнего элемента
		if (size() != 0) {
			if (pointer) return pointer->next->data; // Если указатель существует, то вернуть данные первого элемента очереди
		}
	}

	bool isempty() const { // Проверка на пустоту
		return(!pointer); // Если указатель на элемент существует, то очередь НЕ пуста
	}

	void clear() { // Очистка очереди
		if (size() != 0) {
			while (!this->isempty()) { // Если очередь не пуста
				this->pop(); // Достаем поэлементно из начала
				cout << "Queue was cleared" << endl;
			}
		}
	}

	void pop() { // Берет элемент очереди из начала
			if (pointer == pointer->next) { // Если больше нет элементов
				pointer = NULL;
				delete pointer; // Очищаем указатель
				return;
			}
			else {
				node* temp = pointer->next; // Запоминаем указатель на следующий элемент
				pointer->next = temp->next; // Теперь следующий элемент после pointer будет через элемент
				temp = NULL; // Очищаем указатель
				delete temp; // Очищаем указатель
			}
	}

	int size() const { // Определение размера
		int count = 0; // Счетчик
		if (!pointer) { // Если очередь пуста, вернуть 0
			count = 0;
			return count;
		}
		const node* iter = pointer->next; // Инициализируем каретку
		do {
			count++;
			iter = iter->next; // Сдвигаем каретку
		} while (iter != pointer->next); // Пока не пройдет полный круг
		return count;
	}

	 friend ostream& operator << (ostream& os, Queue<Type>& q) { // Перегрузка оператора вывода
		 if (q.size() != 0) {
			 os << "Queue's filling:" << endl;
			 const node* iter = q.pointer->next;
			 do {
				 os << iter->data << endl; // Выыводим содержимое очереди
				 iter = iter->next; // Сдвигаем каретку
			 } while (iter != q.pointer->next); // Пока указатель снова не станет указывать на первый элемент
		 }
		return os;
	}
	
	friend istream& operator >> (istream& is, Queue<Type>& q) { // Перегрузка оператора ввода
		Type x; // Создаем переменную, в которую будет что-то передано
		is >> x;
		q.push(x); // Вызываем функцию добавления узла в очередь
		return is;
	}
	
	const Queue<Type>& operator=(const Queue<Type>& q) { // Пергерузка операции присваивания
		if (this == &q) return *this;
		pointer = q.pointer; // Присваиваем указатели
		return *this;
	}
};
