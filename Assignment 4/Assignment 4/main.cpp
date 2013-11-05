// Assignment 4-1
// Constructor and destructor tests

#include <iostream>

class SimpleClass{
	
public:
	SimpleClass(){
		std::cout << "SimpleClass constructor invoked" << std::endl;
	};
	
	SimpleClass(SimpleClass& src){
		std::cout << "SimpleClass copy constructor invoked" << std::endl;
	};
	
	~SimpleClass(){
		std::cout << "SimpleClass destructor invoked" << std::endl;
	};
};

//prototypes
void f1(SimpleClass aSimpleClass);
void f2(SimpleClass aSimpleClass);
void f3(SimpleClass& aSimpleClass);
void f4(SimpleClass* aSimpleClass);

//definitions
void f1(SimpleClass aSimpleClass){
	SimpleClass scf1;
	f2(scf1);
};

void f2(SimpleClass aSimpleClass){
	SimpleClass *scf2 = new SimpleClass();
	f3(*scf2);
	delete scf2;
};

void f3(SimpleClass& aSimpleClass){
	f4(&aSimpleClass);
};

void f4(SimpleClass* aSimpleClass){};

int main(int argc, const char * argv[])
{
	SimpleClass sc;
	f1(sc);
}

// Output:
// SimpleClass constructor invoked
// SimpleClass copy constructor invoked
// SimpleClass constructor invoked
// SimpleClass copy constructor invoked
// SimpleClass constructor invoked
// SimpleClass destructor invoked
// SimpleClass destructor invoked
// SimpleClass destructor invoked
// SimpleClass destructor invoked
// SimpleClass destructor invoked
//
// Default constructor invoked 3 times
// Copy constructor invoked 2 times
// Destructor invoked 5 times
//
// The default constructor is invoked in main when sc is instantiated. The copy constructor
// is first invoked in the call to f1. The default constructor is again called within f1. The copy
// constructor is invoked in the call to f2. The default constructor is called for the last time
// with the creation of *scf2 in f2. Since f3 and f4 use reference objets, the constructors are
// not invoked. The destructors are called as the variables go out of scope; this essentially happens
// in reverse order, with sc within main being the last call
