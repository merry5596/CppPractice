#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);
int GetAccIndex(int findingId);

class Account
{
private:
    int accId;
    char *name;
    int amount;

public:
    Account(int id, char *nm, int amnt) : accId(id), amount(amnt)
    {
        name = new char[strlen(nm) + 1];
        strcpy(name, nm);
    }
    int GetAccId() const
    {
        return accId;
    }
    int GetAmount() const
    {
        return amount;
    }
    void AddMoney(const int money)
    {
        amount += money;
        cout << "입금 완료. 계좌 잔액: " << amount << endl
             << endl;
    }
    void SubtractMoney(const int money)
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
    void ShowAccInfo() const
    {
        cout << "계좌ID: " << accId << endl;
        cout << "이 름: " << name << endl;
        cout << "잔액: " << amount << endl
             << endl;
    }
    ~Account()
    {
        delete[] name;
    }
};

Account *pAccArr[100];
int accNum = 0;

int main(void)
{
    int option;

    ShowMenu();
    cout << "선택: ";
    cin >> option;

    while (option != 5)
    {
        cout << endl;

        if (option == 1)
        {
            MakeAccount();
        }
        if (option == 2)
        {
            DepositMoney();
        }
        if (option == 3)
        {
            WithdrawMoney();
        }
        if (option == 4)
        {
            ShowAllAccInfo();
        }
        ShowMenu();
        cout << "선택: ";
        cin >> option;
    }

    cout << "프로그램을 종료함" << endl;
    return 0;
}

void ShowMenu()
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
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

void DepositMoney()
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

void WithdrawMoney()
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

void ShowAllAccInfo()
{
    for (int i = 0; i < accNum; i++)
    {
        pAccArr[i]->ShowAccInfo();
    }
}

int GetAccIndex(int findingId)
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