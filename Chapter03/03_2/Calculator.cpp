#include <iostream>
#include "Calculator.h"
using namespace std;

void Calculator::Init()
{
    addCount = 0;
    minCount = 0;
    mulCount = 0;
    divCount = 0;
}

double Calculator::Add(double a, double b)
{
    addCount++;
    return a + b;
}

double Calculator::Min(double a, double b)
{
    minCount++;
    return a - b;
}

double Calculator::Mul(double a, double b)
{
    mulCount++;
    return a * b;
}

double Calculator::Div(double a, double b)
{
    divCount++;
    return a / b;
}

void Calculator::ShowOpCount()
{
    cout << "덧셈: " << addCount << " 뺄셈: " << minCount << " 곱셈: " << mulCount << " 나눗셈: " << divCount << endl;
}