/*************
* To illustrate using the normal, copy constructors and 
* copy assignments. No dynamic memory in the classes. refer to other example for this.
* 
* Copy constructors are called in the following scenarios (from geeksforgeeks)
* 1.    When an object of a class is created using another object of the same class.
* 2.    When a function is called by passing the object by value.
* 3.    When a function returns an object by value.
* 4.    When the compiler generates a temporary object (what does this mean?)
*/
#include <iostream>

class point{
    int x;
    int y;

    public:
    // Normal constructor
        point(int a = 0, int b = 0){
            std::cout << "Normal constructor called" << std::endl;
            x = a;
            y = b;
        }
        // copy constructor. In this case, copy constructor is not required, since compiler does the same thing.
        // But, in cases where there are dynamically allocated memories, user should define a copy constructor.
        // pass by reference instead of pass by value (because pass by value in itself should call a copy constructor (refer 2))
        // const to avoid side affects on the RHS.      
        point(const point& p){
            std::cout << "copy constructor called" << std::endl;
            x = p.x;
            y = p.y;
        }
        // assignment operator.
        // In this case, LHS = RHS = instance of/ a reference to an instance of the same class.
        // pass by reference instead of pass by value (because pass by value in itself should call a copy constructor (refer 2))
        // const to avoid side affects on the RHS.
        point& operator=(const point&);
        void getPoint() const;
        // friend function. can be placed in public or private. Can access private data anyhow
        friend point addPoints(const point& p, const point& q);
};

// SHALLOW copy since no pointers in class.
inline point& point::operator=(const point& p){
    std::cout << "copy assignment called" << std::endl;
    if(this != &p){
        x = p.x;
        y = p.y;
    }
     return *this;  // this is a pointer. we need to dereference to get a reference to point.
}

// No need to specify friend again here.
point addPoints(const point& p, const point& q)
{
    return point(p.x + q.x, p.y + q.y);     // Normal constructor called
}
inline void point::getPoint() const {
    std::cout << "X is : " << x << std::endl << "Y is : " << y << std::endl;
}

void displayPoint(const point& p) {
    p.getPoint();
}
int main()
{
    std::cout << "Hi there!" << std::endl;
    point p1(1,2);  // Normal constructor called
    p1.getPoint();
    point p2 = p1;  // copy constructor called
    point p3;       // Normal constructor called and insitialized to default values
    p3 = p2;        // Copy assignment called.
    p3.getPoint();
    point p4 = addPoints(p1, p2);   // Normal constructor called while returning
    p4.getPoint();
    displayPoint(p4);
    return 0;
}