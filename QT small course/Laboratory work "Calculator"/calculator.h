#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QObject>
#include <QString>
#include <QDebug>

class calculator : public QObject
{
    Q_OBJECT
public:
    explicit calculator(QObject* parent = 0) : QObject(parent), mSum(0),
        displayValue(0), mMaxValue(999999999), frac(0), power(1), lop('0') {}; // Конструктор
signals:
    void valueChanged(double value);
public slots:
    void DigitButtonPressed(int button);
    void OperationButtonPressed(QString value);
private:
    double mSum; // Для сумм
    double displayValue; // То, что на экране
    int mMaxValue, frac, power; // для вывода, а также переменные, содержащие информацию о том, дробное ли это число
    bool counter = false; // Для проверки, не зашли ли мы в операцию ещё раз
    QString lop; // Строка, хранящая в себе информацию о прошлой операции
};

#endif // CALCULATOR_H
