#include<deque>
#include <iostream>

class S
{
    public:
    S() : x{42} {}
    S(S &s) {std::cout << "copy constructor\n";}
    S(S const&) { std::cout << "const copy constructor\n";}
    S(S &&) { std::cout << "Move constructor\n";}
    S& operator=(S& other) {std::cout << "copy assignment constructor\n"; return *this;}
    S& operator=(S&& other) {std::cout << "Move assignment constructor\n"; return *this;}

    private:
    int x;
};

std::deque<S> v;

void printfunc(S && s)
{
    v.emplace_back(std::move(s));
}

void func(S && s)
{
    printfunc(std::forward<S>(s));
}

int main()
{
    S s;
    func(std::move(s));
    return 0;
}