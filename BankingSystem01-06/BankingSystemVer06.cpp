/*
추가 클래스
1. NormalAccount 보통예금계좌
 이율 정보 추가 (생성자로)
2. HighCreditAccount 신용신뢰계좌
 이율 정보 추가 (생성자로)
 신용정보 A,B,C 추가
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
    void SetAmount(int value);
    virtual void AddMoney(const int money);
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
void Account::SetAmount(int value)
{
    amount = value;
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

// 보통예금게좌
class NormalAccount : public Account
{
private:
    int interRate;

public:
    NormalAccount(int id, char *nm, int amnt, int iRate);
    virtual void AddMoney(const int money);
};

NormalAccount::NormalAccount(int id, char *nm, int amnt, int iRate) : Account(id, nm, amnt), interRate(iRate) {}
void NormalAccount::AddMoney(const int money)
{
    Account::AddMoney(money);                       // 원금 추가
    Account::AddMoney(money * (interRate / 100.0)); // 이자 추가
}
namespace CREDIT_GRADE
{
    enum
    {
        A = 7,
        B = 4,
        C = 2
    };
}

// 신용신뢰게좌
class HighCreditAccount : public NormalAccount
{
private:
    int creditGrade;

public:
    HighCreditAccount(int id, char *nm, int amnt, int iRate, int grade);
    virtual void AddMoney(const int money);
};

HighCreditAccount::HighCreditAccount(int id, char *nm, int amnt, int iRate, int grade) : NormalAccount(id, nm, amnt, iRate)
{
    switch (grade)
    {
    case 1:
        creditGrade = CREDIT_GRADE::A;
        break;
    case 2:
        creditGrade = CREDIT_GRADE::B;
        break;
    case 3:
        creditGrade = CREDIT_GRADE::C;
        break;
    default:
        break;
    }
}
void HighCreditAccount::AddMoney(const int money)
{
    NormalAccount::AddMoney(money);
    Account::AddMoney(money * (creditGrade / 100.0));
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
    int opt;
    int id;
    char name[NAME_LEN];
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

    if (opt == 1)
    {
        pAccArr[accNum] = new NormalAccount(id, name, amount, interest);
    }
    else if (opt == 2)
    {
        cout << "신용등급(1toA, 2toB, 3toC): ";
        cin >> credit;
        pAccArr[accNum] = new HighCreditAccount(id, name, amount, interest, credit);
    }

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
