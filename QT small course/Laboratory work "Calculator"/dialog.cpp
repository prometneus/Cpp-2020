#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"
#include <QSignalMapper>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSignalMapper * digit_mapper = new QSignalMapper(0);
// Соединение кнопочек с цифрами
    digit_mapper->setMapping(ui->pushButton_0, 0);
    connect(ui->pushButton_0, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_1, 1);
    connect(ui->pushButton_1, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_2, 2);
    connect(ui->pushButton_2, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_3, 3);
    connect(ui->pushButton_3, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_4, 4);
    connect(ui->pushButton_4, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_5, 5);
    connect(ui->pushButton_5, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_6, 6);
    connect(ui->pushButton_6, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_7, 7);
    connect(ui->pushButton_7, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_8, 8);
    connect(ui->pushButton_8, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_9, 9);
    connect(ui->pushButton_9, SIGNAL(clicked()), digit_mapper, SLOT(map()));



    QSignalMapper * sign_mapper = new QSignalMapper(0);
// Соединение кнопок с операциями и функций, отвещающих за операции
    connect(ui->pushButton_plus, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper ->setMapping(ui->pushButton_plus, "+");

    connect(ui->pushButton_minus, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper->setMapping(ui->pushButton_minus, "-");

    connect(ui->pushButton_div, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper->setMapping(ui->pushButton_div, "/");

    connect(ui->pushButton_mult, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper->setMapping(ui->pushButton_mult, "*");

    connect(ui->pushButton_cancel, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper->setMapping(ui->pushButton_cancel, "C");

    connect(ui->pushButton_eq, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper->setMapping(ui->pushButton_eq, "=");

    connect(ui->pushButton_dot, SIGNAL(clicked()), sign_mapper, SLOT(map()));
    sign_mapper->setMapping(ui->pushButton_dot, ".");

    calculator * calc = new calculator(0);
    // Связь дисплея и вывода на него, операции, цифры
    connect(digit_mapper, SIGNAL(mappedInt(int)), calc, SLOT(DigitButtonPressed(int)));
    connect(calc, SIGNAL(valueChanged(double)), ui->lcdNumber, SLOT(display(double)));
    connect(sign_mapper, SIGNAL(mappedString(QString)), calc, SLOT(OperationButtonPressed(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

