#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

class Calculator
{
private:
    int addCount;
    int minCount;
    int mulCount;
    int divCount;

public:
    void Init();
    double Add(double a, double b);
    double Min(double a, double b);
    double Mul(double a, double b);
    double Div(double a, double b);
    void ShowOpCount();
};

#endif