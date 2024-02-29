#include <iostream>

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2);

using namespace std;

int main(void)
{
    Point *p1 = new Point;
    p1->xpos = 5;
    p1->ypos = 10;

    Point *p2 = new Point;
    p2->xpos = 7;
    p2->ypos = 10;

    Point &pref = PntAdder(*p1, *p2);

    cout << pref.xpos << endl;
    cout << pref.ypos << endl;

    delete p1;
    delete p2;
    delete &pref;

    return 0;
}

Point &PntAdder(const Point &p1, const Point &p2)
{
    Point *p = new Point;
    p->xpos = p1.xpos + p2.xpos;
    p->ypos = p1.ypos + p2.ypos;
    return *p;
}