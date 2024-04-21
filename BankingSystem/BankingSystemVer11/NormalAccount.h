#pragma once

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interestRate;

public:
    NormalAccount(int id, String name, int amount, int interestRate) : Account(id, name, amount), interestRate(interestRate) {}
    ~NormalAccount() {}

    virtual void AddMoney(const int money) {
        Account::AddMoney(money);                          // 원금 추가
        Account::AddMoney(money * (double)(interestRate / 100.0)); // 이자 추가
    }
};