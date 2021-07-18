#include <string> // ��� �����
#include <iostream> // ��� �����-������
#include <vector> // ��� ���������� ������
#include <algorithm> // ��� ����������

std::vector <std::string> input(std::vector <std::string> numbers, int amount) { // �������� ������� ����� ���������� ��������� � �������
	std::string temp;
	std::cin.ignore(); // ����� �������
	for (int i = 0; i < amount; i++) { // ���� �� ����� ������� ������ �� ���������� ����������
		std::cout << "Enter the phone number" << std::endl;
		getline(std::cin, temp);
		numbers.push_back(temp); // ��������� ������ � ������
	}
	return numbers;
}

std::vector <std::string> correcting(std::vector <std::string> numbers, int amount) {
	int counter; // ������� ��� ������ ��������
	for (int i = 0; i < amount; i++) {
		counter = numbers[i].find(" "); // ����� ��������, ���������� ���-�� �������� ����� ��������� ��������
		while (counter != -1) { // ���� �� ������� ��������, .find ���������� -1
			numbers[i].erase(counter, 1);// ������� ����� ������ � ������� counter �������� 1
			counter = numbers[i].find(" "); //����� ����� ��������
		}
		if (numbers[i].length() == 10) // ���� ����� 10 ��������, �� ����� �������� +7 � ������
			numbers[i].insert(0, "+7");
		if (numbers[i].length() == 11) // ���� �������� 11, �� � ������ ����� ���� 7, ���� 8
			if (numbers[i][0] == '8') { // ���� ����� 8
				numbers[i][0] = '7'; // �� �������� 8 �� 7
				numbers[i].insert(0, "+"); // � ��������� + � ������
			}
			else numbers[i].insert(0, "+"); // ���� ����� 7, �� ������ ��������� +
	}
	return numbers;
}

void containingData(std::vector <std::string> numbers, int amount) {// ������� ������ �� ����� ���������� �������
	std::sort(numbers.begin(), numbers.end()); // ��������� ������ ��� ������ � ������� ����������� ���������� ������� �����������
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
	if (amount == 0) { // ���� ������� ���������� ������� 0
		"Written that no numbers need to enter"; // ������� ��������� �� ����
		return 0; // � ���������� ������ ���������
	}
	numbers = input(numbers, amount); // ����
	done = correcting(numbers, amount); // ���������
	std::cout << "Changed numbers" << std::endl;
	containingData(done, amount); // ����� ����������
}