/*
 * 파일이름: BankingCommonDecl.h
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.27] 파일버전 0.8
 * 설명: 공통헤더 및 상수선언들
 */

#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };

enum { NORMAL = 1, CREDIT = 2 };

enum { GRADE_A = 7, GRADE_B = 4, GRADE_C = 2 };