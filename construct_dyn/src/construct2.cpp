#include <iostream>
#include "point.h"

using namespace std;

int main()
{
    cout << "Hello again!" << endl;

    point p1(3,2);	// Normal constructor
//    point p1;
    p1.getPoint();
    point p2;		// Default constructor
    p2.getPoint();
    p2 = p1;		// Copy assignment
    p2.getPoint();
    point p3 = p2;	// No default construction, direct assignment
    p3.getPoint();

    point p4(p1);
    p4.getPoint();
    return 0;
}
