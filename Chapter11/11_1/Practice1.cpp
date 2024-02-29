#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet; // 총알 수
public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs; // 수갑 수
    Gun *pistol;   // 소유 권총
public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if (bnum > 0)
        {
            pistol = new Gun(bnum);
        }
        else
        {
            pistol = NULL;
        }
    }
    // 복사 생성자 for 깊은 복사
    Police(const Police &cpy)
    {
        handcuffs = cpy.handcuffs;
        if (cpy.pistol != NULL)
        {
            pistol = new Gun(*(cpy.pistol)); // Gun의 디폴트 복사 생성자 호출
        }
        else
        {
            pistol = NULL;
        }
    }
    ~Police()
    {
        if (pistol != NULL)
        {
            delete pistol;
        }
    }

    // 대입 연산자 for 깊은 복사
    Police &operator=(const Police &ref)
    {
        handcuffs = ref.handcuffs;
        if (pistol != NULL)
        {
            delete pistol;
        }
        if (ref.pistol != NULL)
        {
            pistol = new Gun(*(ref.pistol));
        }
        else
        {
            pistol = NULL;
        }
        return *this;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if (pistol == NULL)
        {
            cout << "Hut BBANG!" << endl;
        }
        else
        {
            pistol->Shot();
        }
    }
};

int main(void)
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3); // 권총을 소유하지 않은 경찰
    pman2.Shot();
    pman2.PutHandcuff();

    pman2 = pman1;
    pman2.Shot();
    pman2.PutHandcuff();

    Police pman3 = pman2;
    pman3.Shot();
    pman3.PutHandcuff();

    return 0;
}