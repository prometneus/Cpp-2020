#include "calculator.h"

void calculator::DigitButtonPressed(int pNum) {
   if (frac==0) {
       double mNextNumber = displayValue*10 + pNum;
       if (displayValue < mMaxValue) {
           displayValue = mNextNumber;
           emit valueChanged(displayValue);
       }
       else return;
   }
   else {
       double mNextNumber = displayValue+pNum*pow(10,(-1) * frac);
       ++frac;
       if (displayValue < mMaxValue) {
           displayValue = mNextNumber;
           emit valueChanged(displayValue);
       }
       else return;
   }
}

void calculator::OperationButtonPressed(const QString(value))
{
    if (value == "C") { // Если нажата С, то зануление всего
        displayValue = 0, mSum = 0, frac = 0, power = 1, lop = '0', counter = 0;
        emit valueChanged(displayValue);
    }

    else if (value == "+") { // Операция суммирования
        qDebug() << value;
        frac = 0;
        power = 0;
        if (lop == '0') mSum = displayValue; // Если не было ранее операций, то заносим число с дисплея
        else if(counter == false) { // Это проверка, чтобы не уйти в бесконечный цикл
            qDebug() << "Passed";
            counter = true; // Вот тут я обеспечиваю незаход лишний раз
            this->OperationButtonPressed(lop);
            counter = false;
        }
        else mSum += displayValue; // Если всё в порядке, выполняем операцию
        lop = '+'; // Заносим её в строку последних операций
        displayValue = 0; // Зануляем выражение на экране, чтобы числа не склеивались
        qDebug() << lop;
    }

    else if (value == "-") { // Остальные функции -- копипаст с суммы, но с изменёнными знаками на необходимые
        if (lop == '0') mSum = displayValue;
        else if(counter == false) {
            counter = true;
            this->OperationButtonPressed(lop);
            counter = false;
        }
        else mSum -= displayValue;
        lop = '-';
        displayValue = 0;
    }

    else if (value == "*") {
        qDebug() << "Before" << mSum;
        if (lop == '0') { mSum = displayValue;
        qDebug() << "Entered" << mSum; }
        else if(counter == false) {
            counter = true;
            this->OperationButtonPressed(lop);
            counter = false;
        }
        else mSum *= displayValue;
        lop = '*';
        displayValue = 0;
    }

    else if (value == "/") {
        if (lop == '0') mSum = displayValue;
        else if(counter == false) {
            counter = true;
            this->OperationButtonPressed(lop);
            counter = false;
        }
        else {
            if (displayValue != 0) mSum /= displayValue;
            else qDebug() << "Why do you divide by zero?";
        }
        lop = '/';
        displayValue = 0;
    }

    else if(value == "=") { // Если нажато равно, то уже должно быть выполнено действие
            counter = true; // Изменяем, чтобы не войти в цикл
            this->OperationButtonPressed(lop); // Заходим в функцию и выполняем операцию
            displayValue = mSum; // Приравниваем
            frac = 0, power = 1, lop = '0', counter = false;
            emit valueChanged(displayValue); // Извещаем об изменении
        }

    else if(value == ".") frac = 1; // Если нажата точка, то число превращается в дробное, поэтому для него нужен другой на экран
        // Но все операции проводились с double, поэтому структурных изменений в них не требуется
}
