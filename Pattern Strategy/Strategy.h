#pragma once
#include <iostream>

class QuackBehaviour {
public:
	virtual void quack() = 0;
	virtual ~QuackBehaviour() { std::cout << "Quack Destructor" << std::endl; }
};

class Quack : public QuackBehaviour {
public:
	void quack() {
		std::cout << "Quack!" << std::endl;
	}
};

class Squeak : public QuackBehaviour {
public:
	void quack() {
		std::cout << "Squeak!" << std::endl;
	}
};

class MuteQuack : public QuackBehaviour {
public:
	void quack() {
		std::cout << "I was mutted by my homies" << std::endl;
	}
};

class FlyBehaviour {
public:
	virtual void fly() = 0;
	virtual ~FlyBehaviour() { std::cout << "Fly Destructor" << std::endl; }
};

class FlyWithWings : public FlyBehaviour {
public:
	void fly() {
		std::cout << "I fly using wings" << std::endl;
	}
};

class FlyNoWay : public FlyBehaviour {
public:
	void fly() {
		std::cout << "I cannot fly" << std::endl;
	}
};

class Duck{
private:
	QuackBehaviour* qb;
	FlyBehaviour* fb;
public:
	Duck() {}
	//Duck(QuackBehaviour* b, FlyBehaviour* f) : qb(b), fb(f) {}
	~Duck() { std::cout << "Duck Destructor" << std::endl; delete qb; delete fb; }
	virtual void display() = 0;
	void swim() {
		std::cout << "I swim" << std::endl;
	}
	void performFly() {
		fb->fly();
	}
	void performQuack() {
		qb->quack();
	}
	void SetFlyBehaviour(FlyBehaviour* fly) {
		fb = fly;
	}
	void SetQuackBehaviour(QuackBehaviour* quack) {
		qb = quack;
	}
};

class RedheadDuck : public Duck {
public:
	void display() {
		std::cout << "I am a RedheadDuck" << std::endl;
	}
	RedheadDuck() {
		SetQuackBehaviour(new Quack);
		SetFlyBehaviour(new FlyWithWings);
	}
};

class MallardDuck : public Duck {
public:
	MallardDuck() {
		SetQuackBehaviour(new Quack);
		SetFlyBehaviour(new FlyWithWings);
	}
	void display() {
		std::cout << "I am a MallardDuck" << std::endl;
	}
};

class RubberDuck : public Duck {
public:
	void display() {
		std::cout << "I am a RubberDuck" << std::endl;
	}
	RubberDuck() {
		SetQuackBehaviour(new Squeak);
		SetFlyBehaviour(new FlyNoWay);
	}
};

class DecoyDuck : public Duck {
public:
	void display() {
		std::cout << "I am a DecoyDuck" << std::endl;
	}
	DecoyDuck() {
		SetQuackBehaviour(new MuteQuack);
		SetFlyBehaviour(new FlyNoWay);
	}
};
