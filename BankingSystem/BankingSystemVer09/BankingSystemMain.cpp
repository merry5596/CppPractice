/*
* 8단계 목표
* 1. BoundCheckPointPtrArray 클래스 변경하여 적용
* 2. 일부 클래스에 대해 깊은 복사 진행하도록 대입 연산자 오버로딩
*/

/*
 * 파일이름: BankingSystemMain.cpp
 * 작성자: 김혜연
 * 업데이트 정보: [2024.02.15] 파일버전 0.7
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
    AccountHandler accountHandler;
    int option;

    accountHandler.ShowMenu();
    cout << "선택: ";
    cin >> option;

    while (option != EXIT)
    {
        cout << endl;

        if (option == MAKE)
        {
            accountHandler.MakeAccount();
        }
        if (option == DEPOSIT)
        {
            accountHandler.DepositMoney();
        }
        if (option == WITHDRAW)
        {
            accountHandler.WithdrawMoney();
        }
        if (option == SHOWALL)
        {
            accountHandler.ShowAllAccountInfo();
        }
        accountHandler.ShowMenu();
        cout << "선택: ";
        cin >> option;
    }

    cout << "프로그램을 종료함" << endl;
    return 0;
}
