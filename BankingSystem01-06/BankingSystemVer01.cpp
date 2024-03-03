#include <iostream>

using namespace std;

const int NAME_LEN = 20;

void showMenu(void);
void makeAccount(void);
void depositMoney(void);
void withdrawMoney(void);
void showAllAccInfo(void);
int getAccIndex(int findingId);

typedef struct
{
    int accId;
    char name[NAME_LEN];
    int amount;
} Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
    int option;

    showMenu();
    cout << "선택: ";
    cin >> option;

    while (option != 5)
    {
        cout << endl;

        if (option == 1)
        {
            makeAccount();
        }
        if (option == 2)
        {
            depositMoney();
        }
        if (option == 3)
        {
            withdrawMoney();
        }
        if (option == 4)
        {
            showAllAccInfo();
        }
        showMenu();
        cout << "선택: ";
        cin >> option;
    }

    cout << "프로그램을 종료함" << endl;
    return 0;
}

void showMenu()
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void makeAccount()
{
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> accArr[accNum].accId;
    cout << "이 름: ";
    cin >> accArr[accNum].name;
    cout << "입금액: ";
    cin >> accArr[accNum].amount;
    cout << "입금 성공. 계좌 잔액: " << accArr[accNum].amount << endl
         << endl;

    accNum++;
}

void depositMoney()
{
    int findingId;
    int accountIndex;
    int money;

    cout << "[입    금]" << endl;
    cout << "계좌ID: ";
    cin >> findingId;
    accountIndex = getAccIndex(findingId);
    if (accountIndex == -1)
    {
        cout << "계좌를 찾을 수 없습니다." << endl
             << endl;
    }
    else
    {
        cout << "입금액: ";
        cin >> money;

        accArr[accountIndex].amount += money;
        cout << "입금 성공. 계좌 잔액: " << accArr[accountIndex].amount << endl
             << endl;
    }
}

void withdrawMoney()
{
    int findingId;
    int accountIndex;
    int money;

    cout << "[출    금]" << endl;
    cout << "계좌ID: ";
    cin >> findingId;
    accountIndex = getAccIndex(findingId);
    if (accountIndex == -1)
    {
        cout << "계좌를 찾을 수 없습니다." << endl
             << endl;
    }
    else
    {
        cout << "출금액: ";
        cin >> money;
        if (money > accArr[accountIndex].amount)
        {
            cout << "출금 실패. 계좌의 잔액보다 출금액이 큽니다." << endl
                 << endl;
        }
        else
        {

            accArr[accountIndex].amount -= money;
            cout << "출금 성공. 계좌 잔액: " << accArr[accountIndex].amount << endl
                 << endl;
        }
    }
}

void showAllAccInfo()
{
    for (int i = 0; i < accNum; i++)
    {
        cout << "계좌ID: " << accArr[i].accId << endl;
        cout << "이 름: " << accArr[i].name << endl;
        cout << "잔액: " << accArr[i].amount << endl
             << endl;
    }
}

int getAccIndex(int findingId)
{
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].accId == findingId)
        {
            return i;
        }
    }
    return -1;
}