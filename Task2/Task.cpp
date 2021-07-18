#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Vector {
private:
	float x_ = 10, y_ = 0, z_ = 0;
public:
	Vector(float a, float b, float c) {
		x_ = a;
		y_ = b;
		z_ = c;
	}

	Vector(){}

	float scalar(Vector a, Vector b) {
		return a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_;
	}

	double length(Vector a) {
		return sqrt(a.scalar(a, a));
	}

	double cosinus(Vector a, Vector b) {
		return scalar(a, b) / (length(a) * length(b));
	}

	Vector add(Vector b) {
		return Vector(x_ + b.x_, y_ + b.y_, z_ + b.z_);
	}

	Vector sub(Vector b) {
		return Vector(x_ - b.x_, y_ - b.y_, z_ - b.z_);
	}

	~Vector() { cout << "dist"; }

	void print() {
		cout << "(" << x_ << ", " << y_ << ", " << this->z_ << ")" << endl;
	}
};

int main() {
	Vector a(1, 1, 1);
	Vector b(1, 1, 1);
	Vector v;
	v.print();
	cout << "Scalar product: " << a.scalar(a, b) << endl;
	cout << "Length: " << a.length(a) << "\t" << b.length(b) << endl;
	cout << "Cosinus between the vectors equals to: " << a.cosinus(a, b) << endl;
	v = a.add(b);
	cout << "Coordinates of summary of vectors: ";
	v.print();
	v = a.sub(b);
	cout << "Coordinates of substitution of vectors: ";
	v.print();
}