//
//  CharQueue2.h
//  Assignment 5
//
//  Created by Steve Minor on 11/11/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_5__CharQueue2__
#define __Assignment_5__CharQueue2__

#include <iostream>
#include <string>
#include <sstream>

class CharQueue2{
public:
	CharQueue2();
	~CharQueue2();
	
	void enque(char c);
	void dequeue();
	std::string toString();
	
private:
	char* cq;
	int size;
};

#endif /* defined(__Assignment_5__CharQueue2__) */
