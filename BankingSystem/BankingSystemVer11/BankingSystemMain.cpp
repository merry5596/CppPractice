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
