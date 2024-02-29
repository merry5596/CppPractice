#include <iostream>
using namespace std;

void addOne(int &ref)
{
    ref++;
}

void changeSign(int &ref)
{
    ref = ref * -1;
}

int main(void)
{
    int num = 5;
    addOne(num);
    cout << num << endl;
    changeSign(num);
    cout << num << endl;

    return 0;
}
