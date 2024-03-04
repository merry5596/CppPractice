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
};

template <typename T>
void SwapData(T &val1, T &val2)
{
    T tmp = val1;
    val1 = val2;
    val2 = tmp;
}

int main(void)
{
    Point p1(3, 4);
    p1.ShowPosition();

    Point p2(-1, -2);
    p2.ShowPosition();

    SwapData(p1, p2);

    p1.ShowPosition();
    p2.ShowPosition();

    return 0;
}