#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    friend istream &operator>>(istream &is, Point &pos);
    friend ostream &operator<<(ostream &os, const Point &pos);
};

istream &operator>>(istream &is, Point &pos)
{
    is >> pos.xpos >> pos.ypos;
    return is;
}

ostream &operator<<(ostream &os, const Point &pos)
{
    os << "[" << pos.xpos << ", " << pos.ypos << "]";
    return os;
}

int main(void)
{
    Point pos1;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos1;
    cout << pos1 << endl;

    Point pos2;
    cout << "x, y 좌표 순으로 입력: ";
    cin >> pos2;
    cout << pos2 << endl;

    return 0;
}