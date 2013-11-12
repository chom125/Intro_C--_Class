//
//  CharQueue1.h
//  Assignment 5
//
//  Created by Steve Minor on 11/10/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_5__CharQueue1__
#define __Assignment_5__CharQueue1__

#include <iostream>
#include <deque>
#include <string>

class CharQueue1{
public:
	void enque(char c);
	void dequeue();
	std::string toString();
	
private:
	std::deque<char> cq;	
};

#endif /* defined(__Assignment_5__CharQueue1__) */
