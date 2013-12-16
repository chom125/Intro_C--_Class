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

//change to true to run tests
const bool runTests = true;

int main(int argc, const char * argv[])
{	
	if(runTests){
		TestResult tr;
		TestRegistry::runAllTests(tr);
	}else{
//		std::string myName = "It is a long established fact that a reader will be distracted\n"
//		"by the readable content of a page when looking at its layout. The point of using Lorem\n"
//		"Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using\n"
//		"'Content here, content here', making it look like readable English. Many desktop\n"
//		"publishing packages and web page editors now use Lorem Ipsum as their default model\n"
//		"text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy.\n"
//		"Various versions have evolved over the years, sometimes by accident, sometimes on purpose\n"
//		"(injected humour and the like).";
//		
//		using namespace delayedPrint;
//		print(std::cout, myName);
		
	}
    
//	// force console screen to hold
//	char ch;
//	std::cin >> ch;
    
    return 0;
}




