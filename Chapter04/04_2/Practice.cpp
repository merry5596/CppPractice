#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    Point center;
    int radius;

public:
    void Init(int x, int y, int r)
    {
        center.Init(x, y);
        radius = r;
    }
    void ShowCircleInfo() const
    {
        cout << "radius: " << radius << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle innerCircle;
    Circle outterCircle;

public:
    void Init(int xIn, int yIn, int rIn, int xOut, int yOut, int rOut)
    {
        innerCircle.Init(xIn, yIn, rIn);
        outterCircle.Init(xOut, yOut, rOut);
    }
    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        innerCircle.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        outterCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}