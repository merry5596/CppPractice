#pragma once

class BankingException {
public:
	virtual void ShowExceptionMessage() const = 0;
};