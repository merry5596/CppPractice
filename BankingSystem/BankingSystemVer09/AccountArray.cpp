/*
 * 파일이름: AccountArray.cpp
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.27] 파일버전 0.1
 * 설명: 배열 클래스인 'BoundCheckAccountPtrArray' 클래스 정의
 */

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int n) : len(n) {
	arr = new ACCOUNT_PTR[len];
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray() {
	delete []arr;
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int index) {
	if (index < 0 || index >= len) {
		cout << "AcountArray index out of bound exception." << endl;
		exit(1);
	}
	return arr[index];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[] (int index) const {
	if (index < 0 || index >= len) {
		cout << "AcountArray index out of bound exception." << endl;
		exit(1);
	}
	return arr[index];
}

int BoundCheckAccountPtrArray::GetArrLen() const {
	return len;
}