/*
객체지향에서 '전역'의 개념은 가급적 사용하지 않는 것이 좋다.
전역함수들을 컨트롤 클래스로 묶어서 없애보자.
1. AccountHandler 클래스 정의하여 전역함수들을 이 클래스의 멤버에 포함시킨다.
2. Account 객체의 저장을 위해 선언한 배열과 변수도 이 클래스의 멤버에 포함시킨다.
3. AccountHandler 클래스 기반으로 프로그램이 실행되도록 main 함수 변경한다.
*/

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    SHOWALL,
    EXIT
};

// Entity 클래스
class Account
{
private:
    int accId;
    char *name;
    int amount;

public:
    Account(int id, char *nm, int amnt);
    Account(const Account &copy);

    int GetAccId() const;
    int GetAmount() const;
    void AddMoney(const int money);
    void SubtractMoney(const int money);
    void ShowAccInfo() const;
    ~Account();
};

Account::Account(int id, char *nm, int amnt) : accId(id), amount(amnt)
{
    name = new char[strlen(nm) + 1];
    strcpy(name, nm);
}
Account::Account(const Account &copy) : accId(copy.accId), amount(copy.amount)
{
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
}
int Account::GetAccId() const
{
    return accId;
}
int Account::GetAmount() const
{
    return amount;
}
void Account::AddMoney(const int money)
{
    amount += money;
    cout << "입금 완료. 계좌 잔액: " << amount << endl
         << endl;
}
void Account::SubtractMoney(const int money)
{
    if (money > amount)
    {
        cout << "출금 실패. 계좌의 잔액보다 출금액이 큽니다." << endl
             << endl;
    }
    else
    {
        amount -= money;
        cout << "출금 완료. 계좌 잔액: " << amount << endl
             << endl;
    }
}
void Account::ShowAccInfo() const
{
    cout << "계좌ID: " << accId << endl;
    cout << "이 름: " << name << endl;
    cout << "잔액: " << amount << endl
         << endl;
}
Account::~Account()
{
    delete[] name;
}

// 컨트롤 클래스
class AccountHandler
{
private:
    Account *pAccArr[100];
    int accNum;

public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    int GetAccIndex(int findingId) const;
    ~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0)
{
}

void AccountHandler::ShowMenu(void) const
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int amount;
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> amount;

    pAccArr[accNum] = new Account(id, name, amount);

    cout << "입금 완료. 계좌 잔액: " << pAccArr[accNum]->GetAmount() << endl
         << endl;

    accNum++;
}

void AccountHandler::DepositMoney(void)
{
    int findingId;
    int accountIndex;
    int money;

    cout << "[입    금]" << endl;
    cout << "계좌ID: ";
    cin >> findingId;
    accountIndex = GetAccIndex(findingId);
    if (accountIndex != -1)
    {
        cout << "입금액: ";
        cin >> money;
        pAccArr[accountIndex]->AddMoney(money);
    }
}

void AccountHandler::WithdrawMoney(void)
{
    int findingId;
    int accountIndex;
    int money;

    cout << "[출    금]" << endl;
    cout << "계좌ID: ";
    cin >> findingId;
    accountIndex = GetAccIndex(findingId);
    if (accountIndex != -1)
    {
        cout << "출금액: ";
        cin >> money;
        pAccArr[accountIndex]->SubtractMoney(money);
    }
}

void AccountHandler::ShowAllAccInfo(void) const
{
    for (int i = 0; i < accNum; i++)
    {
        pAccArr[i]->ShowAccInfo();
    }
}

int AccountHandler::GetAccIndex(int findingId) const
{
    for (int i = 0; i < accNum; i++)
    {
        if (pAccArr[i]->GetAccId() == findingId)
        {
            return i;
        }
    }
    cout << "계좌를 찾을 수 없습니다." << endl
         << endl;
    return -1;
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
    {
        delete pAccArr[i];
    }
}

int main(void)
{
    AccountHandler accHandler;
    int option;

    accHandler.ShowMenu();
    cout << "선택: ";
    cin >> option;

    while (option != EXIT)
    {
        cout << endl;

        if (option == MAKE)
        {
            accHandler.MakeAccount();
        }
        if (option == DEPOSIT)
        {
            accHandler.DepositMoney();
        }
        if (option == WITHDRAW)
        {
            accHandler.WithdrawMoney();
        }
        if (option == SHOWALL)
        {
            accHandler.ShowAllAccInfo();
        }
        accHandler.ShowMenu();
        cout << "선택: ";
        cin >> option;
    }

    cout << "프로그램을 종료함" << endl;
    return 0;
}
