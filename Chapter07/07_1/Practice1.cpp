#include <iostream>
using namespace std;

class Car
{ // 기본 연료 자동차
private:
    int gasolineGauge;

public:
    Car(int gGauge) : gasolineGauge(gGauge)
    {
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{ // 하이브리드 자동차
private:
    int electricGauge;

public:
    HybridCar(int gGauge, int eGauge) : Car(gGauge), electricGauge(eGauge)
    {
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{ // 하이브리드 워터카
private:
    int waterGauge;

public:
    HybridWaterCar(int gGauge, int eGauge, int wGauge) : HybridCar(gGauge, eGauge), waterGauge(wGauge)
    {
    }
    void ShowCurrentGauge()
    {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};

int main(void)
{
    HybridWaterCar hwCar(50, 60, 70);
    hwCar.ShowCurrentGauge();
    return 0;
}