// Write a CppUnitLite test that uses new to allocate an array of 10 integers.
// Initialize the array with the values 0 to 9. Use CHECK_EQUAL to verify the array
// has the correct values. Use delete to deallocate the array.

#include "TestHarness.h"
#include <iostream>

TEST(intArray, Array){
    const int ARRAYSIZE = 10;
    int* myArray = new int[ARRAYSIZE];
    
    // initialize array
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        myArray[i] = i;
    }
    
    //verify array
    for (int j = 0; j < ARRAYSIZE; j++)
    {
        CHECK_EQUAL(myArray[j], j);
    }
    
    delete [] myArray;
}