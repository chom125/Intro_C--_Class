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

//change to true to run tests
const bool runTests = true;
extern textGameLoop gymLevel;

int main(int argc, const char * argv[])
{	
	if(runTests){
		TestResult tr;
		TestRegistry::runAllTests(tr);
	}else{
        gameInit();
		gymLevel.begin();
	}
    
//	// force console screen to hold
//	char ch;
//	std::cin >> ch;
    
    return 0;
}




