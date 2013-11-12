//
//  CharQueue1.cpp
//  Assignment 5
//
//  Created by Steve Minor on 11/10/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "CharQueue1.h"
#include <deque>
#include <sstream>

std::string CharQueue1::toString(){
	std::string cqStr;
	std::stringstream ss;
	
	for(std::deque<char>::iterator i = cq.begin(); i != cq.end(); i++){
		ss << *i;
	}
	ss >> cqStr;
	
	return cqStr;
};

void CharQueue1::enque(char c){
	cq.push_back(c);
};

void CharQueue1::dequeue(){
	cq.pop_back();
};


