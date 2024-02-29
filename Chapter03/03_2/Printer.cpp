#include <iostream>
#include <cstring>
#include "Printer.h"
using namespace std;

void Printer::SetString(char *s)
{
    strcpy(str, s);
}

void Printer::ShowString()
{
    cout << str << endl;
}