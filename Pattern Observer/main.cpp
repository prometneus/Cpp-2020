#include <iostream>
#include "Observer.h"

int main() {
	Citizens Oleg, Dima; // Объекты, за которыми следят
	NameCheckist n_one, n_two;
	StatusCheckist s_one, s_two;
	NumberCheckist num_one, num_two;
	std::cout << "NameCheckist 1 has an adress " << &n_one << std::endl;
	std::cout << "StatusCheckist 1 has an adress " << &s_one << std::endl;
	std::cout << "NumberCheckist 1 has an adress " << &num_one << std::endl;
	n_one.subscribe(Oleg); // Подписка наблюдателя на объект
	s_one.subscribe(Oleg);
	num_one.subscribe(Oleg);
	Oleg.set("Oleg", "Suspicious", 6); // Установка первоначальных данных
	Oleg.set("Oleg", "Under investigation", 8); // Обновление (установка новых данных)
	Dima.set("Dmitry", "A man of conscience", 0);
	n_one.subscribe(Dima); // Наблюдатель подписывается на второй объект
	s_one.subscribe(Dima);
	num_one.subscribe(Dima);
	n_one.unsubscribe(Oleg); // И отписывается от первого
	s_one.unsubscribe(Oleg);
	num_one.unsubscribe(Oleg);
	std::cout << "NameCheckist 2 has an adress " << &n_two << std::endl;
	std::cout << "StatusCheckist 2 has an adress " << &s_two << std::endl;
	std::cout << "NumberCheckist 2 has an adress " << &num_two << std::endl; //Второй наблюдатель
	n_two.subscribe(Dima);
	s_two.subscribe(Dima);
	num_two.subscribe(Dima);
	n_two.subscribe(Oleg);
	s_two.subscribe(Oleg);
	num_two.subscribe(Oleg); // Подписывается на оба объекта
	Dima.changes();
	n_one.unsubscribe(Dima);
	s_one.unsubscribe(Dima);
	num_one.unsubscribe(Dima);
	return 0;
}