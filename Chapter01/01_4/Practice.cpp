// 컴파일하는 방법
// g++ Practice.cpp comsimple.cpp -o Practice

#include "comsimple.h"
#include <iostream>

using namespace std;

int main(void)
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}