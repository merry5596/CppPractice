#pragma once

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int creditGrade;

public:
    HighCreditAccount(int id, String name, int amount, int interestRate, int grade) : NormalAccount(id, name, amount, interestRate)
    {
        switch (grade)
        {
        case 1:
            creditGrade = GRADE_A;
            break;
        case 2:
            creditGrade = GRADE_B;
            break;
        case 3:
            creditGrade = GRADE_C;
            break;
        default:
            break;
        }
    }
    ~HighCreditAccount() {}

    virtual void AddMoney(const int money)
    {
        NormalAccount::AddMoney(money);
        Account::AddMoney(money * (creditGrade / 100.0));
    }
};