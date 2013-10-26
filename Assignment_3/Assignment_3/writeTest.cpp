#include "TestHarness.h"
#include "write.h"

TEST(writeTest, write){
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