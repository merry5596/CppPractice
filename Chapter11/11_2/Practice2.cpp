#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int len;
    int *arr;
    BoundCheckIntArray(const BoundCheckIntArray &cpy) {}
    BoundCheckIntArray &operator=(const BoundCheckIntArray &ref) {}

public:
    BoundCheckIntArray(int n) : len(n)
    {
        arr = new int[n];
    }
    ~BoundCheckIntArray()
    {
        delete[] arr;
    }
    int &operator[](int index)
    {
        if (index < 0 || index >= len)
        {
            cout << "Out of bound" << endl;
            exit(1);
        }
        return arr[index];
    }
    int operator[](int index) const
    {
        if (index < 0 || index >= len)
        {
            cout << "Out of bound" << endl;
            exit(1);
        }
        return arr[index];
    }
};

typedef BoundCheckIntArray *BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
    int len;
    BoundCheckIntArrayPtr *arr2d; // BoundCheckIntArray 포인터의 배열 (배열의 각 요소는 BoundCheckIntArray의 주소값을 담음)

    BoundCheck2DIntArray(const BoundCheck2DIntArray &cpy) {}
    BoundCheck2DIntArray &operator=(const BoundCheck2DIntArray &ref) {}

public:
    BoundCheck2DIntArray(int n, int m) : len(n)
    {
        arr2d = new BoundCheckIntArrayPtr[n];
        for (int i = 0; i < n; i++)
        {
            arr2d[i] = new BoundCheckIntArray(m);
        }
    }
    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i < len; i++)
        {
            delete arr2d[i];
        }
        delete[] arr2d;
    }
    BoundCheckIntArray &operator[](int index) // BoundCheckIntArray의 참조값 반환
    {
        if (index < 0 || index >= len)
        {
            cout << "out of bound" << endl;
            exit(1);
        }
        return *arr2d[index];
    }
};

int main(void)
{
    BoundCheck2DIntArray arr2d(3, 4);

    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
        {
            arr2d[n][m] = n + m;
        }
    }

    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
        {
            cout << arr2d[n][m] << ' ';
        }
        cout << endl;
    }

    return 0;
}