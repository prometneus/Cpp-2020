//Создать класс Date для работы с датами в формате «день.месяц.год».
// Дата представляется структурой с полями типа unsigned int для года, месяца и дня.
// Определить конструктор по умолчанию, конструктор, принимающий в качестве параметров 3 числа, конструктор,
// принимающий строку вида «день.месяц.год», конструктор копирования, деструктор, оператор присваивания.
// Перегрузить операторы прибавления целого числа дней «+», вычитания целого числа дней «-»,
// вычитания из одной даты другой, выводящей количество дней между датами, сравнения на равенство «==»,
// оператор «<<» для работы со стандартным потоком вывода.
// Продемонстрировать работу программы на примере: Date bday(“21.05.1995”),
// today(2,4,2020), today-bday, today+10, bday-5.


#include <iostream>
#include <string>
#include <vector>

struct Date {
    unsigned int day = 0, month = 0, year = 0;
};

class DreiNummern {
public:
    Date date_;
    DreiNummern() = default; // По умолчанию

    DreiNummern (unsigned int f1,unsigned int f2, unsigned int f3) { //От трёх чисел
        date_.day = f1;
        date_.month = f2;
        date_.year = f3;
    }

    DreiNummern(std::string str) { // Конструктор для строки
        std::vector<std::string> result;
        int pos = 0;
        while (1) {
            auto end = str.find('.', pos);
            if (end == str.npos) {
                result.push_back(str.substr(pos));
                break;
            } else {
                result.push_back(str.substr(pos, end - pos));
                pos = end + 1;
            }
        }
        date_.day = atoi(result[0].c_str()); //str to int
        date_.month = atoi(result[1].c_str());
        date_.year = atoi(result[2].c_str());
    }

    DreiNummern(const DreiNummern& other) { //Копирование
        date_.day = other.date_.day;
        date_.month = other.date_.month;
        date_.year = other.date_.year;
    }

    ~DreiNummern() = default;

    bool operator == (DreiNummern& d1) {
        return (this->date_.day == d1.date_.day and this->date_.month == d1.date_.month
        and this->date_.year == d1.date_.year);
    }

    DreiNummern& operator= (Date& d1) {
        date_.day = d1.day;
        date_.month = d1.month;
        date_.year = d1.year;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& os, const DreiNummern& d) {
        os <<  "Day: " << d.date_.day << " Month: " << d.date_.month << " Year: " << d.date_.year;
        return os;
    }

    DreiNummern& operator+ (unsigned int a) { // для дней
        int days = date_.year * 365 + date_.month * 30 + date_.day + a;
        date_.year = days / 365; // целочисленное -- года
        days %= 365; // остаток в дни
        date_.month = days / 30; // целочисленное в месяцы
        days %= 30; // остаток в дни
        date_.day = days;
        return *this;
    }

    DreiNummern& operator- (unsigned int a) { // для дней
        int days = date_.year * 365 + date_.month * 30 + date_.day - a;
        date_.year = days / 365; // целочисленное -- года
        days %= 365; // остаток в дни
        date_.month = days / 30; // целочисленное в месяцы
        days %= 30; // остаток в дни
        date_.day = days;
        return *this;
    }

    friend DreiNummern operator-(const DreiNummern& d1, const DreiNummern& d2) { // для разницы дат
        DreiNummern oof;
        int days = d1.date_.year * 365 + d1.date_.month * 30 + d1.date_.day -
                (d2.date_.year * 365 + d2.date_.month * 30 + d2.date_.day);
        std::cout << "days difference: " << days << std::endl;
        oof.date_.year = days / 365;
        days %= 365;
        oof.date_.month = days / 30;
        days %= 30;
        oof.date_.day = days;
        return oof;
    }

    template<class T>
    T sum (T a, T b) { return a + b;};
};

int main() {
    DreiNummern bday("21.05.1995"), today(2,4,2020);
    std::cout << "Today - bday = " << today-bday << std::endl;
    std::cout << "Today + 10 = " << today + 10 << std::endl;
    std::cout << "Bday - 5 = " << bday - 5 << std::endl;
    if (bday == today) {
        std::cout << "yes";
    } else std::cout << "no" ;
    bday = today;
    std::cout << std::endl;
    if (bday == today) {
        std::cout << "yes";
    } else std::cout << "no" ;
    std::cout << "Copy";
    DreiNummern copy(today);
    std::cout << copy;
    return 0;
}
