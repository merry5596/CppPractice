/*
 * 파일이름: AccountHandler.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.03.05] 파일버전 0.9
 * 설명: Control 클래스인 'AccountHandler' 클래스 선언
 */

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