/*
 * 파일이름: Account.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.04.21] 파일버전 11.0
 * 설명: Entity 클래스인 'Account' 클래스 선언
 */

#pragma once
#include "NegativeAmountException.h"
#include "BalanceLackException.h"
#include "String.h"

class Account
{
private:
    int id;
    String name;
    int amount;

public:
    Account(int id, String name, int amount);

    int GetId() const;
    int GetAmount() const;
    void SetAmount(const int value);

    virtual void AddMoney(const int money) throw (NegativeAmountException);
    void SubtractMoney(const int money) throw (NegativeAmountException, BalanceLackException);
    void ShowAccountInfo() const;
};