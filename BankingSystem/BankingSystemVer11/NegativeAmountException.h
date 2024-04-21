#pragma once
#include "BankingException.h"
#include <iostream>
using namespace std;

class NegativeAmountException : public BankingException {
private:
	int money;
public:
	NegativeAmountException(const int money) : money(money) {}
	void ShowExceptionMessage() const {
		cout << money << "원은 잘못된 금액입니다. 양수의 금액을 입력해주세요." << endl;
	}
};