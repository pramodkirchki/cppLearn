#include <iostream>
#include "point.h"

using namespace std;

int main()
{
    cout << "Hello again!" << endl;

    point p1(3,2);
    p1.getPoint();
    point p2;
    p2.getPoint();
    p2 = p1;
    point p3 = p2;
    p3.getPoint();

    return 0;
}
