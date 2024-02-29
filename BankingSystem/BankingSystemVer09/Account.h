/*
 * 파일이름: Account.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.27] 파일버전 0.8
 * 설명: Entity 클래스인 'Account' 클래스 선언
 */

#pragma once

class Account
{
private:
    int id;
    char* name;
    int amount;

public:
    Account(int id, char* name, int amount);
    Account(const Account& copy);
    ~Account();
    Account& operator=(const Account& ref);

    int GetId() const;
    int GetAmount() const;
    void SetAmount(const int value);

    virtual void AddMoney(const int money);
    void SubtractMoney(const int money);
    void ShowAccountInfo() const;
};