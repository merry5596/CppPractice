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
    Point operator-()
    {
        return Point(-xpos, -ypos);
    }

    friend Point operator~(const Point &ref);
};

Point operator~(const Point &ref)
{
    return Point(ref.ypos, ref.xpos);
}

int main(void)
{
    Point pos1(3, 4);
    pos1.ShowPosition();

    Point pos2 = -pos1;
    pos2.ShowPosition();

    Point pos3 = ~pos1;
    pos3.ShowPosition();

    return 0;
}