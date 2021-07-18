#include <iostream>

int division(int a, int b, int* result) {
	if (b == 0) return false;
	else {
		*result = a / b;
		return true;
	}
}

int main(void) {
	int num, denum, result = 0;
	std::cout << "Enter the numerator: ";
	std::cin >> num;
	std::cout << "Enter the denominator: ";
	std::cin >> denum;
	if (division(num, denum, &result)) {
		std::cout << "Result is equal to " << result << std::endl;
	}
	else std::cout << "Denominator equals to zero -> division is impossible." << std::endl;
	return 0;
}