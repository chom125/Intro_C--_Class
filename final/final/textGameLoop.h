//
//  textGameLoop.h
//  final
//
//  Created by Steve Minor on 12/15/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __final__textGameLoop__
#define __final__textGameLoop__

#include <string>
#include <iostream>

class textGameLoop{
public:
	textGameLoop();
	void begin();
	void end();
private:
	std::string input;
	bool isFinished;
	
};

#endif /* defined(__final__textGameLoop__) */
