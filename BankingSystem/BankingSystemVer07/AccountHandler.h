/*
 * 파일이름: AccountHandler.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.15] 파일버전 0.7
 * 설명: Control 클래스인 'AccountHandler' 클래스 선언
 */

#pragma once

#include "Account.h"

class AccountHandler
{
private:
    Account* accountArr[100];
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