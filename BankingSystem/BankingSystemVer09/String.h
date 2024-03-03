/*
 * 파일이름: String.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.03.03] 파일버전 0.1
 * 설명: char배열을 대신할 'String' 클래스 선언
 */

#pragma once

#include "BankingCommonDecl.h"

class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};