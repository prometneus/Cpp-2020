#include <iostream>
#include <string>
using namespace std;

class Time
{
private: // ������� ���������� ������
    int hr;
    int min;

public:
    Time() { setTime(0, 0); } // ����������� ��� ���������� �� ���������
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

    void printDate() { cout  << day << "." << month << "." << year; } // ����� �� �����
};

class Event {
protected: // ��������� ������� Time � Date
    Time mytime;
    Date mydate;

private:
    string myeventName; // �������� �������

public:
    Event() { setEvent("", Time(0, 0), Date(0, 0, 0)); } // "" - ������ �������� � ������������ �� ���������
    Event(string event, Time time, Date date) { setEvent(event, time, date); } // ����������� � �����������, ���� �� ��������

    void setEvent(string str, Time time, Date date) { // ����� ��������� ������ � �������
        myeventName = str;
        mytime = time;
        mydate = date;
    }

    void printEvent() { // ����� �� �����
        cout << "Event " << myeventName;
        cout << " will be held on ";
        mydate.printDate();
        cout << " at ";
        mytime.printTime();
    }
};

int main() {
    int d, m, y;
    Time time = Time(21, 40); // �������������� �����
    Date date = Date(12, 12, 12); // �������������� ����
    string str; // ���������� ��� �������� �������� ������
    cout << "Enter the name of event: ";
    getline(cin, str);
    cout << endl;
    Event event = Event(str, time, date); // ������� ����� ��������� ������
    event.printEvent(); // ����� ������ �� ������ �� �����
    date.getDate(d, m, y); // �������� ��������� � ��������� ������ ������
    cout << endl << "Private date: " << d << ", " << m << " and " << y << endl;
    return 0;
}
