//
//  histogram.h
//  Assignment 6
//
//  Created by Steve Minor on 11/16/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_6__histogram__
#define __Assignment_6__histogram__

#include <iostream>
#include <string>
#include <sstream>

class Histogram{
public:
	Histogram();
	
	//getters
	int getLetterCount();
	int getDigitCount();
	int	getPunctuationCount();
	int getWhitespaceCount();
	
	//setters
	void addLetter();
	void addDigit();
	void addPunctuation();
	void addWhitespace();
	
	void print();
	
private:
	unsigned int letterCount;
	unsigned int digitCount;
	unsigned int punctuationCount;
	unsigned int whitespaceCount;
};


#endif /* defined(__Assignment_6__histogram__) */
