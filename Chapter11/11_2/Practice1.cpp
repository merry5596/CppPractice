#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    friend ostream &operator<<(ostream &os, const Point &pos);
    friend ostream &operator<<(ostream &os, const Point *ptr);
};

ostream &operator<<(ostream &os, const Point &pos)
{
    cout << "[" << pos.xpos << ", " << pos.ypos << "]";
    return os;
}

ostream &operator<<(ostream &os, const Point *ptr)
{
    cout << "[" << ptr->xpos << ", " << ptr->ypos << "]";
    return os;
}

typedef Point *POINT_PTR;

class BoundCheckPointPtrArray
{
private:
    POINT_PTR *arr;
    int len;

    BoundCheckPointPtrArray(const BoundCheckPointPtrArray &cpy) {}
    BoundCheckPointPtrArray &operator=(const BoundCheckPointPtrArray &ref) {}

public:
    BoundCheckPointPtrArray(int n) : len(n)
    {
        arr = new POINT_PTR[len];
    }
    ~BoundCheckPointPtrArray()
    {
        delete[] arr;
    }
    POINT_PTR &operator[](int index)
    {
        if (index < 0 || index >= len)
        {
            cout << "Out of bound" << endl;
            exit(1);
        }
        return arr[index];
    }
    POINT_PTR operator[](int index) const
    {
        if (index < 0 || index >= len)
        {
            cout << "Out of bound" << endl;
            exit(1);
        }
        return arr[index];
    }
    int GetLen() const
    {
        return len;
    }
};

int main(void)
{
    BoundCheckPointPtrArray arr(3);
    arr[0] = new Point(3, 4);
    arr[1] = new Point(5, 6);
    arr[2] = new Point(7, 8);

    for (int i = 0; i < arr.GetLen(); i++)
    {
        cout << arr[i] << endl;
    }

    delete arr[0];
    delete arr[1];
    delete arr[2];

    return 0;
}