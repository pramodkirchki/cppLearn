//============================================================================
// Name        : inlineLearn.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * 1. To check inlining : Compiler inlines the virtual function if the calls are made using object.
 * If called using pointer, the virtual function is to be dynamically resolved. Hence, not inlined.
 *
 *2. A call to a virtual function is resolved according to the underlying type of object for
 *	   which it is called.
 *
 *3. A call to a nonvirtual function is resolved according to the type of the pointer or reference.
 */

#include <iostream>

class Base
{
  public:
	// Needs to be called for existing object. Hence cannot be static
	virtual void getMyself()
	{
		std::cout << "This is Base\n";
	}
	void printName()
	{
		std::cout << "Non virtual Base\n";
	}
	virtual ~Base() {}

  private:
};

class Derived : public Base
{
  public:
	// Overrides of virtual functions are always virtual
	void getMyself()
	{
		std::cout << "This is Derived\n";
	}
	void printName()
	{
		std::cout << "Non virtual Derived\n";
	}

  private:
};

class AnotherDerived : public Derived
{
  public:
	void getMyself()
	{
		std::cout << "Second Derived\n";
	}

  private:
};
int main()
{
	std::cout << "!!!Hello World!!!\n"; // prints !!!Hello World!!!

	// Base bL;
	// Derived dL;
	// bL.getMyself();
	// dL.getMyself();

	Base *b = new Base;
	Derived *d = new Derived;
	// Derived *d2 = new AnotherDerived;

	// // getMyself() is virtual. Call resolved based on the object type
	b->getMyself();
	d->getMyself();
	// d2->getMyself();

	// // printName() is non-virtual. Call resolved based on the pointer type
	// d->printName();
	// d->printName();
	// d2->printName();

	// // Use of scope resolution to suppress the virtual call mechanism
	// d2->Base::getMyself();
	return 0;
}
