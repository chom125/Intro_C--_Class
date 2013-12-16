//
//  delayedPrint.cpp
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "delayedPrint.h"


namespace delayedPrint{
	const int PRINT_DELAY = 20;
	
	void delay(int msecs) {
		clock_t endTime;
		endTime = clock() + msecs * CLOCKS_PER_SEC/1000;
		while(clock() < endTime) { /* do nothing */ }
	};

	void print(std::ostream& os, const std::string str){
		//print one character at a time with a specified delay
		std::string::const_iterator it;
		for(it = str.begin(); it != str.end(); ++it){
			os << *it;
			os.flush();
			delay(PRINT_DELAY);
		};
	};
	
	void clear(std::ostream& os){
		os << std::string( 100, '\n');
	};
}