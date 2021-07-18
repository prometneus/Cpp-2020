#include <iostream>

class badDenumerator {
protected:
	int num, den;
public:
	badDenumerator(int k = 0, int l = 0) : num(k), den(l) {}
	void message();
};

 void badDenumerator::message() {
	std::cout << "You slammed the Universe by dividing by zero c: " << std::endl;
	std::cout << "Now you need to say sorry to all dead people and start entering 2 new numbers again" << std::endl;
}

int division(int a, int b)
{
	if (b == 0) throw badDenumerator(a,b);
	else return a / b;
}

int main(void) {
	int numerator, denumerator, result = 0;
	std::cout << "Enter the numerator and then denominator ";
	while (std::cin >> numerator >> denumerator)
	{
		try
		{
			result = division(numerator, denumerator);
		}
		catch (badDenumerator &baad)
		{
			baad.message();
			std::cout << "Or press any letter on the keyboard to quit " << std::endl;
			continue;
		}

		std::cout << "Oh, everything was OK, so the result is - " << result << std::endl;
		std::cout << "Enter a new pair of numerator and denominator or enter any letter to quit" << std::endl;
	}
	return 0;
}