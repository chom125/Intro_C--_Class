//
//  CharQueue2.cpp
//  Assignment 5
//
//  Created by Steve Minor on 11/11/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "CharQueue2.h"
#include <string>
#include <sstream>

using std::cout;
using std::endl;

CharQueue2::CharQueue2(){
	size = 1;	
	cq = new char[size]();
	cq[0] = '\0';
}

CharQueue2::~CharQueue2(){
	delete[] cq;
}

std::string CharQueue2::toString(){
	std::string cqStr;
	std::stringstream ss;
	
	for(int i = 0; cq[i] != '\0'; i++) {
		ss << cq[i];
	}
	ss >> cqStr;
	
	return cqStr;
};

void CharQueue2::enque(char c){
	char * copy = new char[size];
	strcpy(copy, cq);
	
	delete[] cq;
	cq = new char[size + 1];
	
	for (int i = 0; i <= size; i++){
		if (i == size -1){
			cq[i] = c;
		}
		else if (i == size){
			cq[size] = '\0';
		}
		else {
			cq[i] = copy[i];
		}
	}
	size++;

	delete[] copy;
};

void CharQueue2::dequeue(){
	char  * copy = new char[size];
	strcpy(copy, cq);
	
	delete[] cq;
	size--;
	cq = new char[size];
	
	for (int i = 0; i < size; i++){
		if (i == size -1){
			cq[i] = '\0';
		}
		else{
			cq[i] = copy[i];	
		}
	}
	delete[] copy;
};
