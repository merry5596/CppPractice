#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len)
{
    T sum = 0; // 형식적으로 타입 캐스팅하는 것이 좋다. => T sum = (T)0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int intArr[5] = {1, 2, 3, 4, 5};
    double doubleArr[4] = {1.1, 2.2, 3.3, 4.4};
    char charArr[5] = {'a', 'b', 'c', 'd', 'e'};

    cout << SumArray(intArr, 5) << endl;
    cout << SumArray(doubleArr, 4) << endl;

    return 0;
}