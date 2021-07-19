#include "Converter.h"

converter::converter(): QObject(), m_Value(0) {}


void converter::set_number(const QString tmp) {
    QString val = tmp;
    m_Value = val.toDouble();
}

void converter::execute_caballero_sqmeters() {
    emit counter_changed(m_Value * 386374);
}

void converter::execute_mehniswt_metr() {
    emit counter_changed(m_Value * 0.525);
}

void converter::execute_ounce_gram() {
    emit counter_changed(m_Value * 453.59);
}

void converter::execute_romer_celsius() {
    emit counter_changed((double)40/21 * (m_Value - 7.5));
}

void converter::execute_cubemeter_liter() {
    emit counter_changed(m_Value * 1000);
}
