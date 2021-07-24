#include <iostream>
#include <string>
using namespace std;

class Time
{
private: // Скрытые переменные класса
    int hr;
    int min;

public:
    Time() { setTime(0, 0); } // Конструктор без параметров по умолчанию
    Time(int a, int b) { setTime(a, b); } // Конструктор с параметрами, если их передают

    void setTime(int a, int b) { // Сбор данных
        hr = a;
        min = b;
    }

    void getTime(int& k, int& l) { // Взятие данных
        k = hr;
        l = min;
    }

    void printTime() { // Вывод данных
        cout << hr << ":" << min;
    }
};


class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date() { setDate(0, 0, 0); } // Конструктор без параметров
    Date(int a, int b, int c) { // Конструктор с параметрами, если их передают
        setDate(a, b, c);
    }

    void setDate(int a, int b, int c) { 
        day = a;
        month = b;
        year = c;
    }

    void getDate(int& x, int& y, int& z) {
        x = day;
        y = month;
        z = year;
    }

    void printDate() { cout  << day << "." << month << "." << year; } // Вывод на экран
};

class Event {
protected: // Включение классов Time и Date
    Time mytime;
    Date mydate;

private:
    string myeventName; // Название события

public:
    Event() { setEvent("", Time(0, 0), Date(0, 0, 0)); } // "" - пустое название в конструкторе по умолчанию
    Event(string event, Time time, Date date) { setEvent(event, time, date); } // Конструктор с параметрами, если их передают

    void setEvent(string str, Time time, Date date) { // Метод установки данных о событии
        myeventName = str;
        mytime = time;
        mydate = date;
    }

    void printEvent() { // Вывод на экран
        cout << "Event " << myeventName;
        cout << " will be held on ";
        mydate.printDate();
        cout << " at ";
        mytime.printTime();
    }
};

int main() {
    int d, m, y;
    Time time = Time(21, 40); // Инициализируем время
    Date date = Date(12, 12, 12); // Инициализируем дату
    string str; // Переменная для хранения названия ивента
    cout << "Enter the name of event: ";
    getline(cin, str);
    cout << endl;
    Event event = Event(str, time, date); // Создаем ивент используя данные
    event.printEvent(); // Вывод данных об ивенте на экран
    date.getDate(d, m, y); // Проверка обращения к приватным данным класса
    cout << endl << "Private date: " << d << ", " << m << " and " << y << endl;
    return 0;
}
