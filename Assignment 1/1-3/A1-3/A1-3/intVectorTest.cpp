/* Assignment 1-5
 Write a CppUnitLite test that creates a std::vector of int. Add 10 integers to
 the vector with the values 0-9. Use CHECK_EQUAL to verify the vector has the
 correct values. */

#include "TestHarness.h"
#include <iostream>
#include <vector>

TEST(intVector, vector){
    const int VECTORSIZE = 10;
    std::vector<int> values;
    
    // add values to vector
    for (int i = 0; i < VECTORSIZE; i++)
    {
        values.push_back(i);
    }
    
    // verify vector
    for (int j = 0; j < values.size(); j++)
    {
        CHECK_EQUAL(values[j], j);
    }
}