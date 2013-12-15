//
//  delayedPrint.h
//  final
//
//  Created by Steve Minor on 12/14/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__timer__
#define __final__timer__

#include <iostream>
#include <ctime>
#include <string>

namespace delayedPrint{
	extern const int PRINT_DELAY;
	void delay(int msecs);
	void print(std::ostream& os, const std::string str);
}


#endif /* defined(__final__timer__) */
