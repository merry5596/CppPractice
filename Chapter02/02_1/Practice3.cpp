#include <iostream>
using namespace std;

void SwapPointer(int *(&ref1), int *(&ref2));

int main(void)
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    SwapPointer(ptr1, ptr2);

    cout << *ptr1 << " " << *ptr2 << endl;
}

void SwapPointer(int *(&ref1), int *(&ref2))
{
    int *tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;

    return;
}