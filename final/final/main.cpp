//
//  main.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include <iostream>
#include "delayedPrint.h"
#include "TestHarness.h"
#include "textGameLoop.h"
#include "testLevel.h"

const bool runTests = false; //change to true to run tests
extern textGameLoop testLevel;

int main(int argc, const char * argv[])
{	
	if(runTests){
		TestResult tr;
		TestRegistry::runAllTests(tr);
	}else{
        gameInit();
		testLevel.begin();
	}
    
//	// force console screen to hold
//	char ch;
//	std::cin >> ch;
    
    return 0;
}




