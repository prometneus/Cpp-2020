#include <iostream>
#include <string>
using namespace std;

double summary(double a, double b) {
	return a + b;
}

double substitution(double a, double b) {
	return a - b;
}

double multiplication(double a, double b) {
	return a * b;
}

double arithmeticmean(double a, double b) {
	return (a + b) / 2;
}

double calculate(double a, double b, double (*function)(double, double)) {
	return function(a, b);
}

int main(void) {
	double a, b;
	cout << "Enter the number a, a = ";
	cin >> a;
	cout << "Enter the number b, b = ";
	cin >> b;
	double (*function[4])(double, double);
	function[0] = *summary;
	function[1] = *substitution;
	function[2] = *multiplication;
	function[3] = *arithmeticmean;
	for (int i = 0; i < 4; i++) {
		cout << "Function " << i + 1 << " " << calculate(a, b, function[i]) << endl;
	}
}
