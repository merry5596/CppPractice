/*
 * 파일이름: Account.cpp
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.15] 파일버전 0.7
 * 설명: Entity 클래스인 'Account' 클래스 정의
 */

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, char* name, int amount) : id(id), amount(amount)
{
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

Account::Account(const Account& copy) : id(copy.id), amount(copy.amount)
{
    this->name = new char[strlen(copy.name) + 1];
    strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
}

Account::~Account()
{
    delete[] name;
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
    amount += money;

    cout << "입금 완료. 계좌 잔액: " << amount << endl
        << endl;
}

void Account::SubtractMoney(const int money)
{
    if (money > amount)
    {
        cout << "출금 실패. 계좌의 잔액보다 출금액이 큽니다." << endl
            << endl;
    }
    else
    {
        amount -= money;
        cout << "출금 완료. 계좌 잔액: " << amount << endl
            << endl;
    }
}

void Account::ShowAccountInfo() const
{
    cout << "계좌ID: " << id << endl;
    cout << "이 름: " << name << endl;
    cout << "잔액: " << amount << endl
        << endl;
}