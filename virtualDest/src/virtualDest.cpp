//============================================================================
// Name        : virtualLearnE.cpp
// Author      : Pramod Tikare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

class Base {
public:
	virtual void getMyself() {
		std::cout << "Base\n";
	}
	~Base(){
		std::cout << "Destructor Base\n";
	}
private:
	int* array;
};

class Derived : public Base {
public:
	void getMyself(){
		std::cout << "Derived\n";
	}

	~Derived() {
		std::cout << "Destructor Derived\n";
	}
private:
	int* array;
};
int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

	Base *b = new Base;
	Base *d = new Derived;

	b->getMyself();
	d->getMyself();

	delete b;

	// UB if Base destructor is non-virtual
	// Compiler warning :deleting object of polymorphic class type ‘Base’ which has non-virtual destructor might cause undefined behaviour
	delete d;
	return 0;
}
