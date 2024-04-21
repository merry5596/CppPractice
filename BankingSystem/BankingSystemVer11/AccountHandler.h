#pragma once

#include "BoundCheckArray.h"
#include "Account.h"

class AccountHandler
{
private:
    BoundCheckArray<Account*> accountArr;
    int accountCnt;

public:
    AccountHandler();
    ~AccountHandler();

    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccountInfo() const;
    int GetAccountIndex(const int id) const;
};