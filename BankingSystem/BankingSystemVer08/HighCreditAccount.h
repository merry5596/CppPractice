/*
 * 파일이름: HighCreditAccount.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.15] 파일버전 0.7
 * 설명: 신용신뢰계좌 'HighCreditAccount' 클래스 선언 및 정의
 */

#pragma once

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int creditGrade;

public:
    HighCreditAccount(int id, char* name, int amount, int interestRate, int grade) : NormalAccount(id, name, amount, interestRate)
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