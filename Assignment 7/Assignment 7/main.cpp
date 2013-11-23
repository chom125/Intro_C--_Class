//
//  main.cpp
//  Assignment 7
//
//  Created by Steve Minor on 11/23/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "TestHarness.h"
#include <iostream>

int main()
{
	// random number generator used in some tests
	srand(::time_t(NULL));
    
    TestResult tr;
    TestRegistry::runAllTests(tr);
    
	// force console screen to hold
	char ch;
	std::cin >> ch;
    
    return 0;
}



