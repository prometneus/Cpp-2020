#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QLabel>
#include "Converter.h"
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    QLabel lbl(&w);
    lbl.setNum(0);
    lbl.move(200, 40); // Данные -- "координаты" (горизонталь, вертикаль)

    QPushButton cmd1(&w); // Кнопка
    cmd1.setText("Caballero into sq.meters"); // Надпись // Кабальеро -- площадь
    cmd1.move(50, 100);
    cmd1.resize(200, 30); // Изменение размеров, чтобы помещались надписи

    QPushButton cmd2(&w);
    cmd2.setText("Ounce into grams"); // Унция
    cmd2.move(50, 180);
    cmd2.resize(200, 30);

    QPushButton cmd3(&w);
    cmd3.setText("Meh niswt into meters"); // Королевский локоть -- длина
    cmd3.move(50, 140);
    cmd3.resize(200, 30);

    QPushButton cmd4(&w);
    cmd4.setText("Rømer into celsius"); // Температура Рёмера
    cmd4.move(50, 220);
    cmd4.resize(200, 30);

    QPushButton cmd5(&w);
    cmd5.setText("Cubemeters into liters"); // Кубометры
    cmd5.move(50, 260);
    cmd5.resize(200, 30);

    QLineEdit text(&w); // Строка для ввода
    text.move(50, 40);

    converter convertirovanie;
    // Связи кнопок, нажатия на них и функций перевода
    QObject::connect(&text, SIGNAL(textChanged(const QString)), &convertirovanie, SLOT(set_number(const QString)));
    QObject::connect(&cmd1, SIGNAL(clicked()), &convertirovanie, SLOT(execute_caballero_sqmeters()));
    QObject::connect(&cmd2, SIGNAL(clicked()), &convertirovanie, SLOT(execute_ounce_gram()));
    QObject::connect(&cmd3, SIGNAL(clicked()), &convertirovanie, SLOT(execute_mehniswt_metr()));
    QObject::connect(&cmd4, SIGNAL(clicked()), &convertirovanie, SLOT(execute_romer_celsius()));
    QObject::connect(&cmd5, SIGNAL(clicked()), &convertirovanie, SLOT(execute_cubemeter_liter()));
    QObject::connect(&convertirovanie, SIGNAL(counter_changed(double)), &lbl, SLOT(setNum(double)));
    w.show(); // Обеспечивает вывод
    return a.exec();
}
