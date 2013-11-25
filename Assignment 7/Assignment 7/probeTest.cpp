// Define a probe that can be inserted into a class or function as a test coverage
// device. For a class, the probe is to keep track of the number of instances of the
// class that exist and how many have been created since the program was started. For
// a function, the probe is to track how many times the function is called.
//
// In either case, the probe is to respond with the appropriate tracking information
// when the class instance or function containing the probe is queried. It will be
// necessary to figure out the best way to present the query.
//
// Demonstrate your probe on a class with multiple instances and on several functions.
// The functions should not be class member functions.
//
// Note: the data and function members of the probe cannot be static. The probe itself
// must be declared static in the probed class or function.
// Overload the ostream operator to support printing of information of the class Probe.


#include "TestHarness.h"
#include "probe.h"
#include <iostream>


class testClass{
public:
	testClass();
	~testClass();
	static Probe probe;
};

testClass::testClass(){
	probe++;
};

testClass::~testClass(){
	probe--;
};

Probe testClass::probe;


TEST(objectProbeTest, probe){
	testClass *tc1 = new testClass;
	CHECK_EQUAL(tc1->probe.getTotal(), 1);
	CHECK_EQUAL(tc1->probe.getCurrent(), 1);
	
	testClass *tc2 = new testClass;
	CHECK_EQUAL(tc1->probe.getTotal(), 2);
	CHECK_EQUAL(tc1->probe.getCurrent(), 2);
	CHECK_EQUAL(tc2->probe.getTotal(), 2);
	CHECK_EQUAL(tc2->probe.getCurrent(), 2);
	
	testClass *tc3 = new testClass;
	CHECK_EQUAL(tc1->probe.getTotal(), 3);
	CHECK_EQUAL(tc1->probe.getCurrent(), 3);
	CHECK_EQUAL(tc2->probe.getTotal(), 3);
	CHECK_EQUAL(tc2->probe.getCurrent(), 3);
	CHECK_EQUAL(tc3->probe.getTotal(), 3);
	CHECK_EQUAL(tc3->probe.getCurrent(), 3);
	
		
	delete tc1;
	CHECK_EQUAL(tc2->probe.getCurrent(), 2);
	CHECK_EQUAL(tc2->probe.getTotal(), 3);
	CHECK_EQUAL(tc3->probe.getCurrent(), 2);
	CHECK_EQUAL(tc3->probe.getTotal(), 3);
	delete tc2;
	CHECK_EQUAL(tc3->probe.getCurrent(), 1);
	CHECK_EQUAL(tc3->probe.getTotal(), 3);
	delete tc3;
}

int testFunc(){
	static Probe p;
	p++;
	return p.getTotal();
};

static Probe pr;
void testFunc2(){
	pr++;
	pr--; //without this, current count would give inaccurate results
};


TEST(functionProbeTest, probe){
	CHECK_EQUAL(testFunc(), 1);
	CHECK_EQUAL(testFunc(), 2);
	CHECK_EQUAL(testFunc(), 3);
	CHECK_EQUAL(testFunc(), 4);
	
	for(int i = 0; i < 100000; i++){
		testFunc2();
	}
	CHECK_EQUAL(pr.getTotal(), 100000);
	CHECK_EQUAL(pr.getCurrent(), 0);
}