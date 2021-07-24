#pragma once
#include <iostream>
#include <string>

//Конкретные базы для создания автомобиля в дальнейшем
class dasAuto { // Базовый класс Автомобиль. Просто автомобиль без допов
protected:
	dasAuto* car = 0;
	std::string description;
public:
	dasAuto() : description("Base model") {
		std::cout << "Base model construcor" << std::endl;
	}
	virtual ~dasAuto() { delete car; std::cout << "Base model destrucor" << std::endl; 	}
	inline virtual std::string getDescription() { return description; }
	virtual double price() = 0;
	virtual double power() = 0;
};

class DieselEngine : public dasAuto { // Автомобиль с дизельным двигателем
public:
	DieselEngine() {
		description = "Diesel engine";
		std::cout << "Diesel Engine constructor" << std::endl;
	}
	~DieselEngine() { std::cout << "Diesel Engine destructor" << std::endl; }
	double price() { return 0.4; }
	double power() { return 249; }
};

class PetrolEngine : public dasAuto { // Автомобиль с бензиновым двигателем
public:
	PetrolEngine() {
		description = "Petrol engine";
		std::cout << "Petrol Engine constructor" << std::endl;
	}
	~PetrolEngine() { std::cout << "Petrol Engine destructor" << std::endl; }
	double price() { return 0.6; }
	double power() { return 245; }
};

//Абстрактный декоратор
class CondimentDecorator : public dasAuto {
protected:
	dasAuto* car = NULL;
public:
	CondimentDecorator() {
		std::cout << "Condiment Decorator constructor" << std::endl;
	}
	~CondimentDecorator() { delete car; std::cout << "Condiment Decorator destructor" << std::endl;	}
	virtual std::string getDescription() = 0;
};

class STronicTransmission : public CondimentDecorator { // Коробка передач
public:
	STronicTransmission(dasAuto* wagon) {
		description = "S Tronic transmission";
		car = wagon;
		std::cout << "STronic transmission constructor" << std::endl;
	}
	~STronicTransmission() { std::cout << "STronic transmission destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", S Tronic transmission";
	}
	double price() {
		return 56372 + car->price();
	}
	double power() {
		return 10 + car->power();
	}
};

class TiptronicTransmission : public CondimentDecorator {// Другая коробка передач
public:
	TiptronicTransmission(dasAuto* wagon) {
		description = "Tiptronic transmission";
		car = wagon;
		std::cout << "Tiptronic transmission constructor" << std::endl;
	}
	~TiptronicTransmission() { std::cout << "Tiptronic transmission destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", Tiptronic transmission";
	}
	double price() {
		return 63279 + car->price();
	}
	double power() {
		return 7 + car->power();
	}
};

class SStyle : public CondimentDecorator { // Тип кузова
public:
	SStyle(dasAuto* wagon) {
		std::cout << "S-line design constructor" << std::endl;
		car = wagon;
	}
	~SStyle() { std::cout << "S-line design destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", liftback with S-line design";
	}
	double price() {
		return 2000 + car->price();
	}
	double power() {
		return car->power();
	}
};

class Avant : public CondimentDecorator { // Другой тип кузова
public:
	Avant(dasAuto* wagon) {
		std::cout << "Coupe constructor" << std::endl;
		car = wagon;
	}
	~Avant() { std::cout << "Coupe destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", coupe with Avant design";
	}
	double price() {
		return 1750 + car->price();
	}
	double power() {
		return car->power();
	}
};

class WhiteInterior : public CondimentDecorator { // Белый цвет внутреннего интерьера
public:
	WhiteInterior(dasAuto* wagon) {
		std::cout << "White interior constructor" << std::endl;
		car = wagon;
	}
	~WhiteInterior() { std::cout << "White interior destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", White interior";
	}
	double price() {
		return 970.9 + car->price();
	}
	double power() {
		return car->power();
	}
};

class DarkInterior : public CondimentDecorator { // Темный цвет внутреннего интерьера
public:
	DarkInterior(dasAuto* wagon) {
		std::cout << "Dark interior constructor" << std::endl;
		car = wagon;
	}
	~DarkInterior() { std::cout << "Dark interior destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", Dark interior";
	}
	double price() {
		return 631.4 + car->price();
	}
	double power() {
		return car->power();
	}
};

class EmbeddedСomputer : public CondimentDecorator { // Встроенный компьютер
public:
	EmbeddedСomputer(dasAuto* wagon) {
		std::cout << "Embedded Computer constructor" << std::endl;
		car = wagon;
	}
	~EmbeddedСomputer() { std::cout << "Embedded Computer destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", Computer";
	}
	double price() {
		return 4300 + car->price();
	}
	double power() {
		return 45 + car->power();
	}
};

class DriverAssistanceSystem : public CondimentDecorator { // Система помощи водителю
public:
	DriverAssistanceSystem(dasAuto* wagon) {
		std::cout << "Driver Assistance System constructor" << std::endl;
		car = wagon;
	}
	~DriverAssistanceSystem() { std::cout << "Driver Assistance System destructor" << std::endl; }
	std::string getDescription() {
		return car->getDescription() + ", Driver Assistance System";
	}
	double price() {
		return 3724.41 + car->price();
	}
	double power() {
		return -3 + car->power();
	}
};
