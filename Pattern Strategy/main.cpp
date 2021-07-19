#include <iostream>
#include "Pattern.h"

template <class Type>
void function(const Type& ytka)
{
	ytka->display();
	ytka->swim();
	ytka->performQuack();
	ytka->performFly();
}

int main()
{
	Duck* MDuck = new MallardDuck();
	Duck* RedDuck = new RedheadDuck();
	Duck* RubDuck = new RubberDuck();
	Duck* DDuck = new DecoyDuck();
	std::cout << "_________________________________________" << std::endl;
	function(MDuck);
	std::cout << "_________________________________________" << std::endl;
	function(RedDuck);
	std::cout << "_________________________________________" << std::endl;
	function(RubDuck);
	std::cout << "_________________________________________" << std::endl;
	function(DDuck);
	std::cout << "_________________________________________" << std::endl;
	delete MDuck;
	delete RedDuck;
	delete RubDuck;
	delete DDuck;
	return 0;
}