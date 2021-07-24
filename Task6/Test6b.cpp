#include <iostream>
#include <string>
using namespace std;

class Time
{
private: // Скрытые переменные класса
    int hr;
    int min;

public:
    Time() { setTime(0, 0); } // Конструктор без параметров
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
        cout << "Time: " << hr << ":" << min;
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

    void printDate() { cout << "Date: " << day << "." << month << "." << year; } // Вывод на экран
};

class Event : private Time, Date { // Закрытое наследование
private:
    string myeventName;

public:
    Event() : Time(), Date() { setEvent(""); }
    explicit Event(string str, Date date, Time time) : Time(time), Date(date) { setEvent(str); } // Конструктор с параметрами, если их передают 

    void setEvent(string str) { myeventName = str; }

    void printEvent() { // Вывод на экран
        cout << "Event name is " << myeventName;
        cout << endl;
        printDate(); // Использование наследованной реализации из Date
        cout << endl;
        printTime(); // Использование наследованноой реализации из Time 
        cout << endl;
    }
};

int main() {
    int hours, minutes;
    Time t(21, 40);
    Date d(27, 05, 2018);
    Event e("Emergenza 2018", d, t); // Создаем событие с такими данными
    e.printEvent(); // Чуть измененный вывод
    t.getTime(hours, minutes); // Проверка работы обращения к приватным данным
    cout << "Private data is " << hours << " and " << minutes << endl;
    return 0;
}
