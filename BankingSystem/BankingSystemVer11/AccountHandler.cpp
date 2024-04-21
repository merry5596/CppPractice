#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : accountCnt(0) {}
AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accountCnt; i++)
    {
        delete accountArr[i];
    }
}

void AccountHandler::ShowMenu() const
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
{
    int opt;
    int id;
    String name;
    int amount;
    int interest;
    int credit;

    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
    cout << "선택: ";
    cin >> opt;
    if (opt == 1)
    {
        cout << "[보통예금계좌 개설]" << endl;
    }
    else if (opt == 2)
    {
        cout << "[신용신뢰계좌 개설]" << endl;
    }
    else
    {
        cout << "그런거업어" << endl;
        return;
    }
    cout << "계좌ID: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> amount;
    cout << "이자율: ";
    cin >> interest;

    if (opt == NORMAL)
    {
        accountArr[accountCnt] = new NormalAccount(id, name, amount, interest);
    }
    else if (opt == CREDIT)
    {
        cout << "신용등급(1toA, 2toB, 3toC): ";
        cin >> credit;
        accountArr[accountCnt] = new HighCreditAccount(id, name, amount, interest, credit);
    }

    cout << "입금 완료. 계좌 잔액: " << accountArr[accountCnt]->GetAmount() << endl
        << endl;

    accountCnt++;
}

void AccountHandler::DepositMoney()
{
    int findingId;
    int accountIndex;
    int money;

    cout << "[입    금]" << endl;
    cout << "계좌ID: ";
    cin >> findingId;
    accountIndex = GetAccountIndex(findingId);
    while (accountIndex != -1)
    {
        cout << "입금액: ";
        cin >> money;
        try {
            accountArr[accountIndex]->AddMoney(money);
            break;
        }
        catch (BankingException& e) {
            e.ShowExceptionMessage();
        }
    }
}

void AccountHandler::WithdrawMoney()
{
    int findingId;
    int accountIndex;
    int money;

    cout << "[출    금]" << endl;
    cout << "계좌ID: ";
    cin >> findingId;
    accountIndex = GetAccountIndex(findingId);
    while (accountIndex != -1)
    {
        cout << "출금액: ";
        cin >> money;
        try {
            accountArr[accountIndex]->SubtractMoney(money);
            break;
        }
        catch (BankingException& e) {
            e.ShowExceptionMessage();
        }
    }
}

void AccountHandler::ShowAllAccountInfo() const
{
    for (int i = 0; i < accountCnt; i++)
    {
        accountArr[i]->ShowAccountInfo();
    }
}

int AccountHandler::GetAccountIndex(const int id) const
{
    for (int i = 0; i < accountCnt; i++)
    {
        if (accountArr[i]->GetId() == id)
        {
            return i;
        }
    }
    cout << "계좌를 찾을 수 없습니다." << endl
        << endl;
    return -1;
}
