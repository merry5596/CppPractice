#include <iostream>
#include <cstring>
using namespace std;

// 고용인
class Employee
{
private:
    char name[100];

public:
    Employee(char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0;
    virtual void ShowSaleryInfo() const = 0;
};

// 정규직
class PermanentWorker : public Employee
{
private:
    int salery;

public:
    PermanentWorker(char *name, int money) : Employee(name), salery(money) {}
    virtual int GetPay() const
    {
        return salery;
    }
    virtual void ShowSaleryInfo() const
    {
        ShowYourName();
        cout << "salery: " << GetPay() << endl
             << endl;
    }
};

// 영업직
class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    virtual int GetPay() const
    {                                                                       // 함수 overriding이 일어남!
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio); // PermanentWorker의 GetPay 함수 호출
    }
    virtual void ShowSaleryInfo() const
    { // 함수 overriding이 일어남!
        ShowYourName();
        cout << "salery: " << GetPay() << endl
             << endl; // SalesWorker의 GetPay 함수 호출
    }
};

namespace RISK_LEVEL
{
    enum
    {
        RISK_A = 30,
        RISK_B = 20,
        RISK_C = 10
    };
}

// 외국인
class ForeignSalesWorker : public SalesWorker
{
private:
    const double riskLevel;

public:
    ForeignSalesWorker(char *name, int money, double ratio, int riskLvl) : SalesWorker(name, money, ratio), riskLevel(riskLvl)
    {
    }
    int GetRiskPay() const
    {
        return (int)(SalesWorker::GetPay() * (riskLevel / 100.0));
    }
    virtual int GetPay() const
    {                                                // 함수 overriding이 일어남!
        return SalesWorker::GetPay() + GetRiskPay(); // PermanentWorker의 GetPay 함수 호출
    }
    virtual void ShowSaleryInfo() const
    { // 함수 overriding이 일어남!
        ShowYourName();
        cout << "salery: " << SalesWorker::GetPay() << endl;
        cout << "risk pay: " << GetRiskPay() << endl;
        cout << "sum: " << GetPay() << endl
             << endl;
    }
};

// 임시직
class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(char *name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    { // 함수 overriding이 일어남!
        return workTime * payPerHour;
    }
    void ShowSaleryInfo() const
    { // 함수 overriding이 일어남!
        ShowYourName();
        cout << "salery: " << GetPay() << endl
             << endl;
    }
};

class EmployeeHandler
{
private:
    Employee *empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee *emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSaleryInfo() const
    {
        for (int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSaleryInfo();
        }
    }
    void ShowTotalSalery() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
        {
            sum += empList[i]->GetPay();
        }
        cout << "Salery sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};

int main(void)
{
    EmployeeHandler handler;

    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSaleryInfo();

    return 0;
}