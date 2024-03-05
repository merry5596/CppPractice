/*
 * 파일이름: NormalAccount.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.03.03] 파일버전 0.8
 * 설명: 보통예금계좌 'NormalAccount' 클래스 선언 및 정의
 */

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