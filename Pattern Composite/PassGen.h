#pragma once
#define _CRT_SECURE_NO_WARNINGS //Для дурацкого strcpy
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class password_generator {
public:
	virtual string generate() { return ""; };
	virtual int length() = 0;
	virtual string allowed_chars() = 0;
	virtual void add(password_generator*) {};
	virtual ~password_generator() {};
};

class digit_generator : public password_generator {
protected:
	int len;
public:
	digit_generator(int smth = 0) { len = smth; }
	int length() { return len; }
	string allowed_chars() { return "0123456789"; } // Строка цифр
};

class symbol_generator : public password_generator {
protected:
	int len;
public:
	symbol_generator(int smth = 0) { len = smth; }
	int length() { return len; }
	string allowed_chars() { return "!@#$%^&*-_~"; } // Строка специальных символов
};

class upper_letter_generator : public password_generator {
protected:
	int len;
public:
	upper_letter_generator(int smth = 0) { len = smth; }
	int length() { return len; }
	string allowed_chars() { return "QWERTYUIOPASDFGHJKLZXCVBNM"; } // Строка заглавных букв
};

class lower_letter_generator : public password_generator {
protected:
	int len;
public:
	lower_letter_generator(int smth = 0) { len = smth; }
	int length() { return len; }
	string allowed_chars() { return "qwertyuiopasdfghjklzxcvbnm"; } // Строка строчных букв
};

class composit_password_generator : public password_generator
{
protected:
	vector <password_generator*> criteria_list; // Массив для количества элементов (цифр, символов, букв разной индексации)
	int min_len;

public:
	composit_password_generator(int count) { min_len = count; } // Конструктор

	void add(password_generator* temp) { criteria_list.push_back(temp); }

	int length() { return min_len; } // Метод для нахождения минимальной необходимой длины пароля

	string generate() {
		string final_password = "";
		int number = 0;
		for (unsigned int i = 0; i < criteria_list.size(); i++) { number += criteria_list[i]->length(); }

		if (number < min_len) { // Сравнение с минимально необходимой длиной. В случае неудачи выкидывает из программы.
			cout << "The length of the required password is greater than amount of used symbols, impossible to create such password" << endl;
			exit(-4);
		}
		else { // Здесь создаётся финальный пароль как конкатенция строк. Длина строк соответственна необходимому количеству элементов
			for (unsigned int i = 0; i < criteria_list.size(); i++) {
				for (int j = 0; j < criteria_list[i]->length(); j++) {
					final_password += criteria_list[i]->allowed_chars()[rand() % criteria_list[i]->allowed_chars().length()];
				}
			}

			char *array = new char[final_password.length()]; // Создание массива для переноса строки туда
			strcpy(array, final_password.c_str()); // Посимвольный перенос строки в массив
			for (int i = final_password.length() - 1; i >= 1; i--) // Алгоритм перемешивания массива символов
			{
				int j = rand() % (i + 1);

				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
			final_password = string(array); // Преобразование массива в строку обратно
			return final_password;
		}
	}

	string allowed_chars() { // Функция, возвращающая строку, состояющую из ВСЕХ допустимых символов
		string tmp = "";
		for (unsigned int i = 0; i < criteria_list.size(); i++) {
			tmp += criteria_list[i]->allowed_chars();
		}
		return tmp;
	}

	~composit_password_generator() { // Деструктор
		for (unsigned int i = 0; i < criteria_list.size(); i++) {
			delete criteria_list[i];
		}
		criteria_list.clear();
	}
};
