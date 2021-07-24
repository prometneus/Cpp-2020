#include <string> // Для строк
#include <iostream> // Для ввода-вывода
#include <vector> // Для контейнера вектор
#include <algorithm> // Для сортировки

std::vector <std::string> input(std::vector <std::string> numbers, int amount) { // Создание функции ввода количества элементов в векторе
	std::string temp;
	std::cin.ignore(); // Игнор пробела
	for (int i = 0; i < amount; i++) { // Цикл по вводу номеров исходя из введенного количества
		std::cout << "Enter the phone number" << std::endl;
		getline(std::cin, temp);
		numbers.push_back(temp); // Помещение строки в вектор
	}
	return numbers;
}

std::vector <std::string> correcting(std::vector <std::string> numbers, int amount) {
	int counter; // Счетчик для поиска пробелов
	for (int i = 0; i < amount; i++) {
		counter = numbers[i].find(" "); // Поиск пробелов, возвращает кол-во символов перед найденным пробелом
		while (counter != -1) { // Если не нашлось пробелов, .find возвращает -1
			numbers[i].erase(counter, 1);// Стирает часть строки с позиции counter размером 1
			counter = numbers[i].find(" "); //Новый поиск пробелов
		}
		if (numbers[i].length() == 10) // Если всего 10 символов, то нужно добавить +7 в начало
			numbers[i].insert(0, "+7");
		if (numbers[i].length() == 11) // Если символов 11, то в начале стоит либо 7, либо 8
			if (numbers[i][0] == '8') { // Если стоит 8
				numbers[i][0] = '7'; // То заменяем 8 на 7
				numbers[i].insert(0, "+"); // И добавляем + в начало
			}
			else numbers[i].insert(0, "+"); // Если стоит 7, то просто добавляем +
	}
	return numbers;
}

void containingData(std::vector <std::string> numbers, int amount) { // Функция вывода на экран измененных номеров
	std::sort(numbers.begin(), numbers.end()); // Сортируем номера для вывода в порядке возрастания встроенной Быстрой сортировкой
	for (int i = 0; i < amount; i++) {
		std::cout << numbers[i] << std::endl;
	}
}

int main() {
	std::vector <std::string> numbers;
	std::vector <std::string> done;
	int amount;
	std::cout << "Enter the amount of numbers to add:" << std::endl;
	std::cin >> amount;
	if (amount == 0) { // Если введено количество номеров 0
		"Written that no numbers need to enter"; // Вывести сообщение об этом
		return 0; // И прекратить работу программы
	}
	numbers = input(numbers, amount); // Ввод
	done = correcting(numbers, amount); // Изменение
	std::cout << "Changed numbers" << std::endl;
	containingData(done, amount); // Вывод измененных
}
