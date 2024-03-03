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

    friend Point operator-(const Point &pos1, const Point &pos2);
    friend bool operator==(const Point &pos1, const Point &pos2);
    friend bool operator!=(const Point &pos1, const Point &pos2);

    Point &operator+=(const Point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;

        return *this;
    }

    Point &operator-=(const Point &pos)
    {
        xpos -= pos.xpos;
        ypos -= pos.ypos;

        return *this;
    }
};

Point operator-(const Point &pos1, const Point &pos2)
{
    return Point(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
}

bool operator==(const Point &pos1, const Point &pos2)
{
    return ((pos1.xpos == pos2.xpos) && (pos2.ypos == pos2.ypos)) ? true : false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    return (pos1 == pos2) ? false : true;
}

int main(void)
{
    Point pos1(10, 20);
    Point pos2(3, 4);
    cout << "pos1 & pos2 : " << endl;
    pos1.ShowPosition();
    pos2.ShowPosition();

    Point pos3 = pos1 - pos2;
    cout << "pos1 - pos2: " << endl;
    pos3.ShowPosition();

    Point pos4 = pos1 += pos2;
    cout << "pos1 += pos2; pos1: " << endl;
    pos4.ShowPosition();

    Point pos5 = pos1 -= pos2;
    cout << "pos1 -= pos2; pos1: " << endl;
    pos5.ShowPosition();

    if (pos1 == pos2)
    {
        cout << "같아" << endl;
    }
    else if (pos1 != pos2)
    {
        cout << "달라" << endl;
    }

    return 0;
}