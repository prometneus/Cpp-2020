#ifndef CONVERTER_H
#define CONVERTER_H
#include <QObject>

class converter: public QObject
{
    Q_OBJECT
private:
    double m_Value;
public:
    converter();

signals:
    void counter_changed(double);

public slots:
    void set_number(const QString);
    void execute_caballero_sqmeters();
    void execute_mehniswt_metr();
    void execute_ounce_gram();
    void execute_romer_celsius();
    void execute_cubemeter_liter();
};


#endif // CONVERTER_H
