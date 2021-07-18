#include <iostream>
#include <string>
using namespace std;

class Time
{
private: // ������� ���������� ������
    int hr;
    int min;

public:
    Time() { setTime(0, 0); } // ����������� ��� ����������
    Time(int a, int b) { setTime(a, b); } // ����������� � �����������, ���� �� ��������

    void setTime(int a, int b) { // ���� ������
        hr = a;
        min = b;
    }

    void getTime(int& k, int& l) { // ������ ������
        k = hr;
        l = min;
    }

    void printTime() { // ����� ������
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
    Date() { setDate(0, 0, 0); } // ����������� ��� ����������
    Date(int a, int b, int c) { // ����������� � �����������, ���� �� ��������
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

    void printDate() { cout << "Date: " << day << "." << month << "." << year; } // ����� �� �����
};

class Event : private Time, Date { // �������� ������������
private:
    string myeventName;

public:
    Event() : Time(), Date() { setEvent(""); }
    explicit Event(string str, Date date, Time time) : Time(time), Date(date) { setEvent(str); } // ����������� � �����������, ���� �� �������� 

    void setEvent(string str) { myeventName = str; }

    void printEvent() { // ����� �� �����
        cout << "Event name is " << myeventName;
        cout << endl;
        printDate(); // ������������� ������������� ���������� �� Date
        cout << endl;
        printTime(); // ������������� �������������� ���������� �� Time 
        cout << endl;
    }
};

int main() {
    int hours, minutes;
    Time t(21, 40);
    Date d(27, 05, 2018);
    Event e("Emergenza 2018", d, t); // ������� ������� � ������ �������
    e.printEvent(); // ���� ���������� �����
    t.getTime(hours, minutes); // �������� ������ ��������� � ��������� ������
    cout << "Private data is " << hours << " and " << minutes << endl;
    return 0;
}
