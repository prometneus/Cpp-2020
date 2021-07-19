#ifndef CALCULATOR_TEST_H
#define CALCULATOR_TEST_H

#include <QObject>

class Calculator_test: public QObject {
    Q_OBJECT
    public:
        explicit Calculator_test(QObject *parent = 0);
    private slots:
        void digitButtonPressed();
        void operationButtonPressed();
        void cancelButtonPressed();
    };

#endif // CALCULATOR_TEST_H
