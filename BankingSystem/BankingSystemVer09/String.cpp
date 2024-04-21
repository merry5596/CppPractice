/*
 * 파일이름: String.cpp
 * 작성자: 김혜연
 * 업데이트 정보: [2024.03.03] 파일버전 0.1
 * 설명: char배열을 대신할 'String' 클래스 정의
 */

#include "String.h"

#include <iostream>
#include <cstring>
using namespace std;


String::String() {
	len = 0;
	str = NULL;
}

String::String(const char* s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy_s(str, len, s);
}

String::String(const String& s) {
	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
}

String::~String() {
	if (str != NULL) {
		delete []str;
	}
}

String& String::operator=(const String& s) {
	if (str != NULL) {
		delete []str;
	}
	len = s.len;
	str = new char[len];
	strcpy_s(str, len, s.str);
	return *this;
}

String String::operator+(const String& s) {
	int newStrLen = len + s.len - 1;
	char* newStr = new char[newStrLen];
	strcpy_s(newStr, newStrLen, s.str);
	strcat_s(newStr, newStrLen, s.str);
	String ret = String(newStr);
	delete []newStr;
	return ret;
}

String& String::operator+=(const String& s) {
	len += (s.len - 1);
	char* newStr = new char[len];
	strcpy_s(newStr, len, str);
	strcat_s(newStr, len, s.str);
	if (str != NULL) {
		delete[]str;
	}
	str = newStr;
	return *this;
}

bool String::operator==(const String& s) {
	return strcmp(str, s.str) ? false : true;
}

ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) {
	char tmp[100];
	is >> tmp;
	s = String(tmp);
	return is;
}