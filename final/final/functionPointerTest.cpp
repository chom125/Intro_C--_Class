#include "testHarness.h"

int foo(){
	return 4;
};

int bar(){
	return 6;
};

TEST(functionPointerTest, function){
	CHECK_EQUAL(4, foo());
	CHECK_EQUAL(6, bar());
	
	int (*pFoo)() = foo; // pFoo points to function foo()
	pFoo = bar;
	
	CHECK_EQUAL((*pFoo)(), 6);
}