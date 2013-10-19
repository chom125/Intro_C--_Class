//Assignment 2-1
//Write a function that swaps (exchanges the values of two integers.
//Use int* as the argument type.Write another swap function
//using int& as the argument type.

#include "TestHarness.h"
#include <iostream>

//pointer args
void swap(int* a, int* b){
	int c = *a;
	*a = *b;
	*b = c;
}

//ref args
void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}

TEST(swapTestPtr, intptr){
    //original values
    const int origA = 5;
    const int origB = 6;
    
    int a = origA;
    int b = origB;
	
	swap(&a, &b);

    CHECK_EQUAL(b, origA);
    CHECK_EQUAL(a, origB);
}

TEST(swapTestRef, intref){
    //original values
    const int origA = 5;
    const int origB = 6;
    
    int a = origA;
    int b = origB;
	
	swap(a, b);
	
    CHECK_EQUAL(b, origA);
    CHECK_EQUAL(a, origB);
}