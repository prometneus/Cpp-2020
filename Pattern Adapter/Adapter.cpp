#include <iostream>
#include <string>
//using namespace std;

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
    double GetPressure(int temp) // �������� ��������
    {
        return ((8.31 * weight * temp) / (molar * volume));
    }

    double AmountOfMatter() // �������� ����� ��������
    {
        return (weight / molar);
    }

    std::string ToString() // ���������� � �������
    {
        std::string data;
        data = "volume = " + std::to_string(volume) + "\nweight = " + std::to_string(weight) + "\nmolar = " + std::to_string(molar);
        return data;
    }
};

class Tank // ��������� ��������
{
public:
    virtual ~Tank() {} // ����������� ����������
    virtual double CalculateDP(int T0, int dT) = 0;
    virtual void ModifMass(double dM) = 0;
    virtual std::string getData() = 0;
};

class Adapter : public Tank // �������
{
protected:
    DonBallon* one_ballon;
public:
    Adapter(DonBallon* ballon) : one_ballon(ballon) {}
    ~Adapter() { delete one_ballon; }

    double CalculateDP(int T0, int dT) { // ����� ����� ������ ��������� �0? � ���� ������ ��� ����� ������, �������
        double mol = one_ballon->AmountOfMatter(); // ���� �������, ��� ��������� �������� ��������������� ��������� �����������
        return ((mol * 8.31 * (T0 + dT) - mol * 8.31 * T0 )/ one_ballon->volume); // �� � �� ���� ������� ��������� �����, ��� ����������� ��������� � �0
    } // �� ��� �� ������� ����, � ������...

    void ModifMass(double dM) // �������� �����
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