#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <math.h>

class Shape {
protected:
	char* name = new char[15];
public: 
	Shape() { // ����������� �������� ������
		char temp[] = "Shape";
		strcpy(name, temp); // ����������� �����
	}
	virtual double Area() {
		return Area();
	}
	virtual Shape& operator =(const Shape& shape){ // ���������� ��������� =
		if (this == &shape)
			return *this;
		if (strlen(name) == strlen(shape.name))
			strcpy(name, shape.name);
		else {
			delete[] name;
			name = new char[strlen(shape.name) + 1];
			strcpy(name, shape.name);
		return *this;
	}
		Shape(const Shape & shape) { // ����������� �����������
			delete[] name;
			name = new char(strlen(shape.name) + 1);
			strcpy(name, shape.name);
		} 
	virtual ~Shape() { delete[] name; }
};

	class Circle : public Shape {
	protected:
		double radius = 0;
	public:
		double Area() { // ������� �������� �������
			return 3.14 * radius * radius;
		}
		void Data(double r) { // ������� ����� ������
			radius = r;
			char temp[] = "Circle";
			strcpy(name, temp);
		}
		Circle(double radius) { Data(radius); } // ����������� ������� �� ��������� ������
		Circle& operator=(const Circle& circle) { // ���������� ��������� = ��� �����
			if (this == &circle)
				return *this;
			Shape::operator=(circle);
			radius = circle.radius;
			return *this;
		}
	}
	Circle(const Circle& circle) { // ���������� ������������ ����������� ��� �����
		radius = circle.radius;
		strcpy(name, circle.name);
	}
};

class Square : public Shape {
protected:
	double a = 0;
public:
	double Area() {
		return a * a;
	}
	void Data(double b) {
		a = b;
		char temp[] = "Square";
		strcpy(name, temp);
	}
	Square(double a) { Data(a); }
	Square& operator=(const Square& square) {
		if (this == &square)
			return *this;
		a = square.a;
		return *this;
	}
	Square(const Square& square) {
		a = square.a;
		strcpy(name, square.name);
	}
};

class Triangle : public Shape {
protected:
	double a = 0;
	double b = 0;
	double c = 0;

public:
	double Area() {
		double p = (a + b + c) / 2; 
		double S = sqrt(p * (p - a) * (p - b) * (p - c));
		return S;
	}

	void Data(double k, double l, double m) {
		a = k; b = l; c = m;
		char temp[] = "Triangle";
		strcpy(name, temp);
	}
	Triangle(double a, double b, double c) { Data(a, b, c); }
	Triangle& operator=(const Triangle& triangle) {
		a = triangle.a;
		b = triangle.b;
		c = triangle.c;
		return *this;
	}
	Triangle(const Triangle& triangle) {
		a = triangle.a;
		b = triangle.b;
		c = triangle.c;
		strcpy(name, triangle.name);
	}
};

int main() {
	Shape *examples[3]; // ������������� ������� ���������� (������� ������������)
	examples[0] = new Circle(3); // ��������� �� ����
	examples[1] = new Square(4);
	examples[2] = new Triangle(3, 4, 5);
	for (int i = 0; i < 3; ++i) { // ��������� � ������� �������� ������� ��� ������� ������������ �������
		std::cout << "Object number " << (i + 1) << " " << examples[i]->Area() << std::endl; 
		delete examples[i]; // ������� ������
	}
}