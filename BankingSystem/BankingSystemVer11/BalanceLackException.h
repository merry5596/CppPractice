#pragma once
#include "BankingException.h"
#include <iostream>
using namespace std;

class BalanceLackException : public BankingException {
private:
	int wMoney;
public:
	BalanceLackException(const int money) : wMoney(money) {}
	void ShowExceptionMessage() const {
		cout << "계좌 잔액이 출금 금액 " << wMoney << "보다 적어서 출금할 수 없습니다." << endl;
	}
};