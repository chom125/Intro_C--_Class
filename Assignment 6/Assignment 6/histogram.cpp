//
//  histogram.cpp
//  Assignment 6
//
//  Created by Steve Minor on 11/16/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "histogram.h"

Histogram::Histogram() : letterCount(0), digitCount(0), whitespaceCount(0), punctuationCount(0){}

//getters
int Histogram::getLetterCount(){
	return letterCount;
};

int Histogram::getDigitCount(){
	return digitCount;
};

int	Histogram::getPunctuationCount(){
	return punctuationCount;
};

int Histogram::getWhitespaceCount(){
	return whitespaceCount;
};

//setters
void Histogram::addLetter(){
	letterCount++;
};

void Histogram::addDigit(){
	digitCount++;
};

void Histogram::addPunctuation(){
	punctuationCount++;
};

void Histogram::addWhitespace(){
	whitespaceCount++;
};

void Histogram::print(){
	std::cout << "digits: " << digitCount << std::endl;
	std::cout << "letters: " << letterCount << std::endl;
	std::cout << "punctuation: " << punctuationCount << std::endl;
	std::cout << "whitespace: " << whitespaceCount << std::endl;
}


