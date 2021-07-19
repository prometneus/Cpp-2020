#include "dialog.h"
#include <QCoreApplication>
#include <QtTest/QTest>
#include "calculator.h"
#include "calculator_test.h"
#include <QApplication>

#include <QtWidgets>


//QTEST_MAIN(Calculator_test);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    QFile file("/home/artem/Calculator/Style/simple.css");
        file.open(QFile::ReadOnly);
        //записываем содержимое файла в строковую переменну/ strCSS
        QString strCSS = QLatin1String(file.readAll());

        //a.setStyleSheet(strCSS);// присваиваем этот стиль
            //qApp->QApplication::setStyleSheet(strCSS);
    w.show();
    return a.exec();
}
