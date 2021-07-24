#include <iostream>
#include <string>

class DonBallon 
{
public:
    double volume;
    double weight;
    double molar;

    DonBallon() {
        volume = 10;
        weight = 5;
        molar = 5;
    };

    ~DonBallon() {};
    double GetPressure(int temp) // Получить давление
    {
        return ((8.31 * weight * temp) / (molar * volume));
    }

    double AmountOfMatter() // Молярная масса вещества
    {
        return (weight / molar);
    }

    std::string ToString() // Приведение к строкам
    {
        std::string data;
        data = "volume = " + std::to_string(volume) + "\nweight = " + std::to_string(weight) + "\nmolar = " + std::to_string(molar);
        return data;
    }
};

class Tank // Интерфейс баллонов
{
public:
    virtual ~Tank() {} // Виртуальный деструктор
    virtual double CalculateDP(int T0, int dT) = 0;
    virtual void ModifMass(double dM) = 0;
    virtual std::string getData() = 0;
};

class Adapter : public Tank // Адаптер
{
protected:
    DonBallon* one_ballon;
public:
    Adapter(DonBallon* ballon) : one_ballon(ballon) {}
    ~Adapter() { delete one_ballon; }

    double CalculateDP(int T0, int dT) { // Зачем здесь вообще начальное Т0? Я ведь должен был учить физику, поэтому
        double mol = one_ballon->AmountOfMatter(); // могу сказать, что изменение давления пропорционально изменению температуры
        return ((mol * 8.31 * (T0 + dT) - mol * 8.31 * T0 )/ one_ballon->volume); // Да и из этой формулы прекрасно видно, как сокращаются слагаемые с Т0
    } // Но раз по заданию надо, я сделаю...

    void ModifMass(double dM) // Изменить массу
    {
        one_ballon->weight += dM;
    }

    std::string getData()
    {
        return "volume = " + std::to_string(one_ballon->volume) + "\nweight = " + std::to_string(one_ballon->weight) + "\nmolar mass = " + std::to_string(one_ballon->molar);
    }
};

int main()
{
    int T0 = 100;
    int dT = 173;
    DonBallon* jar = new DonBallon;
    Tank* ballon = new Adapter(jar);
    std::cout << ballon->getData() << std::endl;
    std::cout << "Amount of matter in tank: " << jar->AmountOfMatter() << std::endl;
    std::cout << "Pressure before any changes: " << jar->GetPressure(T0) << std::endl;
    ballon->ModifMass(-3);
    std::cout << "\nPressure change after mass decrease by 3: " << ballon->CalculateDP(T0, dT) << std::endl;
    return 0;
}
