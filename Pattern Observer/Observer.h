#pragma once
#include <iostream>
#include <list>
#include <string>

class Observer;
class Citizens;

/*class Subject {
public:
	virtual void registerObserver(Observer& checkist) = 0;
	virtual void removeObserver(Observer& checkist) = 0;
	virtual void notify() = 0;
	virtual void changes() = 0;
	virtual void set(std::string persona, std::string status, int amount) = 0;
};*/

class Observer { // �����������
public:
	virtual void update(Citizens&) = 0;
};

class Citizens /*: public Subject*/ {
protected:
	std::list <Observer*> observers;
	std::string persona;
	std::string status;
	int amount = 0;
public:
	Citizens() {}
	~Citizens() { observers.clear(); }
	void registerObserver(Observer& checkist) { // �������� �����������
		std::cout << "Checkist started working " << std::endl;
		observers.push_back(&checkist);
	}
	
	void removeObserver(Observer& checkist) { // ������� �����������
		std::cout << "Checkist stopped looking after this person " << std::endl;
		observers.remove(&checkist);
	}

	void notify() { // ���������
		std::cout << "ALARM " << std::endl;
		for (auto& Observer : observers)
		{
			Observer->update(*this);
		}
	}

	void changes() {
		std::cout << "Found changes in persona's personal files " << std::endl;
		notify();
	}

	void set(std::string prs, std::string stat, int number) { // ���������� ����� ��������
		persona = prs;
		status = stat;
		amount = number;
		changes();
	}

	std::string getName() { // ���������� ���
		return persona;
	}

	std::string getStatus() { // ������
		return status;
	}

	int getAmount() { // ���������� �������
		return amount;
	}
};


class NameCheckist : public Observer {
private:
	Citizens* ppl;
	std::string imya;
public:
	NameCheckist() {
		ppl = new Citizens;
	}
	~NameCheckist() { delete ppl; }
	void CurrentStatusDisplay() {
		ppl = new Citizens;
	}

	void subscribe(Citizens& pepl) { // ��������� �����������
		pepl.registerObserver(*this);
	}

	void unsubscribe(Citizens& pepl) { // �������� �����������
		pepl.removeObserver(*this);
	}

	void display() { // ����� ������ � �������� �� �����
		std::cout << "Current name of the person -- " << imya <<  std::endl;
	}

	void update(Citizens& pepl) { // �������� ������
		//std::cout << "ENTER UPDATE" << std::endl;
		Citizens& curr = dynamic_cast<Citizens&> (pepl);
		imya = curr.getName(); // �������� ����� ���
		display();
	}
};

class StatusCheckist : public Observer {
	Citizens* ppl;
	std::string status;
public:
	StatusCheckist() {
		ppl = new Citizens;
	}
	~StatusCheckist() { delete ppl; }
	void CurrentStatusDisplay() {
		ppl = new Citizens;
	}

	void subscribe(Citizens& pepl) { // ��������� �����������
		pepl.registerObserver(*this);
	}

	void unsubscribe(Citizens& pepl) { // �������� �����������
		pepl.removeObserver(*this);
	}

	void display() { // ����� ������ � �������� �� �����
		std::cout << "Current status of the person -- " << status << std::endl;
	}

	void update(Citizens& pepl) { // �������� ������
		//std::cout << "ENTER UPDATE" << std::endl;
		Citizens& curr = dynamic_cast<Citizens&> (pepl);
		status = curr.getStatus(); // �������� ����� ���
		display();
	}
};

class NumberCheckist : public Observer {
	Citizens* ppl;
	int number = 0;
public:
	NumberCheckist() {
		ppl = new Citizens;
	}
	~NumberCheckist() { delete ppl; }
	void CurrentStatusDisplay() {
		ppl = new Citizens;
	}

	void subscribe(Citizens& pepl) { // ��������� �����������
		std::cout << this << std::endl;
		pepl.registerObserver(*this);
	}

	void unsubscribe(Citizens& pepl) { // �������� �����������
		pepl.removeObserver(*this);
	}

	void display() { // ����� ������ � �������� �� �����
		std::cout << "Current number of griveances of the person -- " << number << std::endl;
	}

	void update(Citizens& pepl) { // �������� ������
		//std::cout << "ENTER UPDATE" << std::endl;
		Citizens& curr = dynamic_cast<Citizens&> (pepl);
		number = curr.getAmount(); // �������� ����� ���
		display();
	}
};