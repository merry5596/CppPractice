/*
 * 파일이름: AccountArray.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.27] 파일버전 0.1
 * 설명: 배열 클래스인 'BoundCheckAccountPtrArray' 클래스 선언
 */
#pragma once

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray {
private:
	ACCOUNT_PTR* arr;
	int len;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& copy) {}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& ref) {}
public:
	BoundCheckAccountPtrArray(int n = 100);
	~BoundCheckAccountPtrArray();
	ACCOUNT_PTR& operator[] (int index);
	ACCOUNT_PTR operator[] (int index) const;
	int GetArrLen() const;
};