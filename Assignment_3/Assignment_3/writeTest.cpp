// Assignment 3-2
// Create a C++ header file named write.h which contains function prototypes for three functions
// named write. Write the implementations for each write function in a file named write.cpp. Each
// write function takes two arguments. The first argument is always std::ostream& os. The second
// arguments are an int, a float, and a std::string respectively. Each write function should stream
// its second argument to the passed in std::ostream. Write unit tests that pass a std::stringstream
// as the first argument to each function and verify its operation. Write additional code that calls
// each write function and passes std::cout as the first argument. Here's the prototype for the first
// write overload:
// void write(std::ostream& os, int value);
// Notice that both std::stringstream and std::cout may be passed as the first argument. Both inherit
// from std::ostream and thus may be used where ever a std::ostream& is used. This is our first use
// of inheritance in C++. We'll do much more with inheritance as the course progresses.

#include "TestHarness.h"
#include "write.h"
#include <iostream>

TEST(writeSSTest, write){
	int iValue = 4;
	float fValue = 4.4;
	std::string sValue = "four";
	
	std::stringstream ss;
	
	write(ss, iValue);
	CHECK_EQUAL(ss.str(), "4");
	empty(ss);
	
	write(ss, fValue);
	CHECK_EQUAL(ss.str(), "4.4");
	empty(ss);
	
	write(ss, sValue);
	CHECK_EQUAL(ss.str(), "four");
	empty(ss);
}

TEST(writeCoutTest, write){
	std::cout << "std::cout test follows: " << std::endl;
	
	int iValue = 5;
	float fValue = 5.5;
	std::string sValue = "five";
	
	write(std::cout, iValue);
	if( !std::cout){
		CHECK_FAIL("could not stream value");
	}
	
	std::cout << std::endl;
	
	write(std::cout, fValue);
	if( !std::cout){
		CHECK_FAIL("could not stream value");
	}
	std::cout << std::endl;
	
	write(std::cout, sValue);
	if( !std::cout){
		CHECK_FAIL("could not stream value");
	}
	
	std::cout << std::endl;
	std::cout << "std::cout test complete" << std::endl;
}