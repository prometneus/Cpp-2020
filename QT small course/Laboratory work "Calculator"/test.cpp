#include "calculator.h"
#include "calculator_test.h"
#include <QtTest/QTest>
#include <QtTest/QSignalSpy>
#include <QtTest/qtestmouse.h> // Добавил эти три потому что была ошибка undefined reference to
#include <QtTest/qtestkeyboard.h> // В интернетах сказали так сделать, а я чего
#include <QtTest/qtest.h> // Взял и поверил

#include <QDebug>

Calculator_test::Calculator_test(QObject *parent) : QObject(parent)
{ }

void Calculator_test::digitButtonPressed() {
    calculator calc;
//    Перехватываем сигналы калькулятора
//    Объект spy прдставляет список перехваченных сигналов
//    со списками значений их аргументов
    QSignalSpy spy(&calc, SIGNAL(valueChanged(double)));
    //Имитируем действия калькулятора
    calc.DigitButtonPressed(1);
    calc.DigitButtonPressed(0);
//    count() возравщает общее количество перехваченных cигналов
//    Метод takeLast() возвращает список значений аргументов последнего из отслеженных сигналов.
//    Доступ к значениям аргументов других сигналов можно получить с помощью других методов класса QList,
//    от которого частично ведет свое происхождение класс QSignalSpy.
//    Список значений аргументов сигнала возвраща- ется в виде объекта QList<QVariant>.

    qDebug() << spy.count();
    QVERIFY(spy.count() == 2);

    QList<QVariant> args = spy.takeLast();
    QVERIFY(args.at(0) == 10);
}

void Calculator_test::operationButtonPressed() {
    calculator calc;
    QSignalSpy spy(&calc, SIGNAL(valueChanged(double)));
    calc.DigitButtonPressed(1); // вызывается valueChanged
    calc.OperationButtonPressed("+"); //не вызывается
    calc.DigitButtonPressed(1); // вызывается
    calc.DigitButtonPressed(0); // вызывается
    calc.OperationButtonPressed("="); //вызывается
    QVERIFY(spy.count() == 4);
    QList<QVariant> args = spy.takeLast();
    qDebug() << args.at(0);
    QVERIFY(args.at(0) == 11);
}


void Calculator_test::cancelButtonPressed() {
    calculator calc;
    QSignalSpy spy(&calc, SIGNAL(valueChanged(double)));
    calc.DigitButtonPressed(7); // valueChanged сработало
    calc.DigitButtonPressed(1);// valueChanged сработало
    calc.OperationButtonPressed("C");// valueChanged сработало
    calc.DigitButtonPressed(3);// valueChanged сработало
    QVERIFY(spy.count() == 4);
    QList<QVariant> args = spy.at(2);
    QVERIFY(args.at(0) == 0);
    args = spy.takeLast();
    QVERIFY(args.at(0) == 3);
}
