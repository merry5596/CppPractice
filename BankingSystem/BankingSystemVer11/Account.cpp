#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, String name, int amount) : id(id), name(name), amount(amount)
{
}

int Account::GetId() const
{
    return id;
}

int Account::GetAmount() const
{
    return amount;
}

void Account::SetAmount(const int value)
{
    amount = value;
}

void Account::AddMoney(const int money)
{
    if (money < 0) {
        throw NegativeAmountException(money);
    }
    amount += money;
    cout << "입금 완료. 계좌 잔액: " << amount << endl
        << endl;
}

void Account::SubtractMoney(const int money)
{
    if (money < 0) {
        throw NegativeAmountException(money);
    }
    if (money > amount)
    {
        throw BalanceLackException(money);
    }
    amount -= money;
    cout << "출금 완료. 계좌 잔액: " << amount << endl
        << endl;
}

void Account::ShowAccountInfo() const
{
    cout << "계좌ID: " << id << endl;
    cout << "이 름: " << name << endl;
    cout << "잔액: " << amount << endl
        << endl;
}