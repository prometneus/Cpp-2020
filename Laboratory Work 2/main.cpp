#include <iostream>
#include <cctype> // Для isdigit
#include "Class.h"
#include "Template.h"

int main(void) {
	char choice;
	tryAgain: // Устанавливаем метку, на которую будем возвращаться при неправильном вводе
	cout << "Enter the test you want to start: " << endl;
	cout << "1 -- Test of the template of the container" << endl;
	cout << "2 -- Test of the template for the created class" << endl;
	cout << "Or press any letter to exit" << endl;
	cin >> choice;
	if (isdigit(choice)) { // Позволит выйти из программы при введении буквы с клавиатуры
		switch (choice) // Код символа '1' -- 49, '2' -- 50. Для isdigit
		{
		case 49: { // Тест очереди для стандартных типов данных 
			int n;
			Queue <int> queueint; // int
			cout << "Enter the amount of elements to add in int queue: ";
			cin >> n;

			cout << "Enter " << n << " elements" << endl;
			if (n != 0) {
				for (int i = 0; i < n; i++) {
					cin >> queueint; // Используем перегруженный оператор ввода
				}
			}
			cout << queueint;
			cout << "Size is -- " << queueint.size() << endl;
			if (queueint.size() != 0) {
				cout << "The first element is -- " << queueint.show() << endl;
				cout << "Let's take the first element" << endl;
				queueint.pop();
				if (queueint.size() != 0) {
					cout << "Now the first element is -- " << queueint.show() << " and the size is " << queueint.size() << endl;
				}
				else cout << "The queue is empty!" << endl;
			}

			cout << endl << endl << endl;
			Queue <float> queueflt; // float 
			cout << "Enter the amount of elements to add in float queue: ";
			cin >> n;
			cout << "Enter " << n << " elements" << endl;
			if (n != 0) {
				for (int i = 0; i < n; i++) {
					float x;
					cin >> x;
					queueflt.push(x); // Используем функцию для ввода
				}
			}
			if(queueflt.size() != 0){
			cout << "In queue there are: " << endl;
			while (!queueflt.isempty()) {
				cout << queueflt.show() << endl;
				queueflt.pop();
			}
			}

			cout << endl << endl << endl;
			Queue <double> queuedbl1; // double
			Queue <double> queuedbl2;
			cout << "Enter the amount of elements to add in double queue: ";
			cin >> n;
			cout << "Enter " << n << " elements" << endl;
			if (n != 0) {
				for (int i = 0; i < n; i++) {
					cin >> queuedbl1; // Используем перегруженный оператор ввода
				}
			}
			if (queuedbl1.size() != 0) {
				queuedbl2 = queuedbl1; // Перегруженная операция присваивания
				cout << "For queue2 " << queuedbl2; // Перегруженная операция вывода
			}
		}
		break;

		case 50: { // Тест очереди для пользовательского класса
			long rub;
			int kop;
			Money cash1, cash2;
			Queue<Money> q, r;
			cin >> q; // Перегруженный оператор ввода для шаблона контейнера
			cout << "Enter the amount of rubles and kopecks " << endl;
			cin >> rub >> kop;
			cash1 = Money(rub, kop); // Будет использован конструктор с параметрами
			cout << "Function of printing for the class Money check: " << endl;
			cash1.print();
			q.push(cash1); // Функция добавления элемента в очередь (в конец очереди)
			cin >> cash2; // Перегруженный оператор ввода для класса 
			q.push(cash2);
			cout << q << endl; // Перегруженный оператор вывода для очереди
			cout << "The first element of the queue is " << q.show() << endl;
			cout << "The size of the queue 1 equals to " << q.size() << endl;
			r = q; // Перегруженный оператор присваивания
			cout << endl << endl;
			cout << "The size of the queue 2 equals to " << r.size() << endl;
			cout << "Let's check if queues are the same" << endl;
			cout << r;
			cout << "Let's take the first element an look at a new first " << endl;
			r.pop();
			cout << r.show() << endl;
			cout << "Right now queue has " << r.size() << " elements. " << r;
			cout << "Queue here will be cleared. 1 element -- 1 phrase about success" << endl;
			r.clear();
			cout << r;
		}
		break;
		default: {
			cout << "Wrong choice, try again." << endl;
			goto tryAgain; // Возвращаемся на метку сверху для повторного ввода
		}
		}
	}
	else return 0;
	return 0;
}
