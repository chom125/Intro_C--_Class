/* Assignment 1-3 
Write CppUnitLite tests which verifies std::stringstream. These test
will follow the pattern shown in the lesson 1 discussion Use stringstream instead
of atoi and sprintf. */


#include "TestHarness.h"
#include <iostream>

TEST(rwDouble, stringstream){
    // read and write a double
    std::stringstream sValue;
    double dIn = 0.000098;
    double dOut;
    sValue << dIn;
    sValue >> dOut;
    
    if(!sValue){
        CHECK_FAIL("conversion failed");
    }
    
    CHECK_DOUBLES_EQUAL(dIn, dOut, 0.0);
}

TEST(rwFloat, stringstream){
	// read and write a float
    std::stringstream sValue;
    float fIn = 0.00001;
    float fOut;
    sValue << fIn;
    
    if(!sValue){
        CHECK_FAIL("conversion failed");
    }
    
    sValue >> fOut;
    
    if(!sValue){
        CHECK_FAIL("conversion failed");
    }
    
    CHECK_DOUBLES_EQUAL(fIn, fOut, 0.0);
}

TEST(rwString, stringstream){
	// read and write a string
    std::stringstream sValue;
    std::string sIn = "test-string";
    std::string sOut;
    
    sValue << sIn;
    
    if(!sValue){
        CHECK_FAIL("conversion failed");
    }
    
    sValue >> sOut;
    
    if(!sValue){
        CHECK_FAIL("conversion failed");
    }
    
    CHECK_EQUAL(sIn, sOut);
}

TEST(rwChar, stringstream){
	// read and write a char
    std::stringstream sValue;
    sValue << 't';
    
    if(!sValue){
        CHECK_FAIL("conversion failed");
    }
    
    CHECK_EQUAL("t", sValue.str());
}

TEST(intHello, stringstream){
	// Initialize a stringstream with the "Hello". Attempt to stream this value into an
    // int variable. Write a check that verifies this fails.
    std::stringstream sHello("Hello");
    
    int helloConversion;
    
    sHello >> helloConversion;
    
    CHECK(!sHello == true) //passes if conversion fails
}