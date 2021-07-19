#include "PassGen.h"

int main() {
	int n = 0;
	cout << "Enter the minimum length of the password: ";
	cin >> n;
	password_generator* generator = new composit_password_generator(n); // � ������������ ��������� ����������� ����� ������
	n = 0;
	cout << "Enter the number of digits in the password: ";
	cin >> n;
	generator->add(new digit_generator(n)); // ������������� ���������� ���� � ������
	n = 0;
	cout << "Enter the number of symbols in the password: ";
	cin >> n;
	generator->add(new symbol_generator(n)); // ��������
	n = 0;
	cout << "Enter the number of uppercase letters in the password: ";
	cin >> n;
	generator->add(new upper_letter_generator(n)); // ��������� ����
	n = 0;
	cout << "Enter the number of lowercase letters in the password: ";
	cin >> n;
	generator->add(new lower_letter_generator(n)); // ��������� ����
	cout << endl << "Minumum length of password: " << generator->length() << endl;
	cout << "Every allowed symbol to use in a password: " << generator->allowed_chars() << endl << endl;
	cout << "Password 1: " << generator->generate() << endl;
	cout << "Password 2: " << generator->generate() << endl;
	cout << "Password 3: " << generator->generate() << endl;
	delete generator;
	return 0;
}
