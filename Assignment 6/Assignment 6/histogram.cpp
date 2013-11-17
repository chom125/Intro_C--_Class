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
int Histogram::getLetterCount() const{
	return letterCount;
};

int Histogram::getDigitCount() const{
	return digitCount;
};

int Histogram::getPunctuationCount() const{
	return punctuationCount;
};

int Histogram::getWhitespaceCount() const{
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

std::ostream& operator<<(std::ostream& os, const Histogram& h){
	
	os << "digits: " << h.getDigitCount() << std::endl;
	os << "letters: " << h.getLetterCount() << std::endl;
	os << "punctuation: " << h.getPunctuationCount() << std::endl;
	os << "whitespace: " << h.getWhitespaceCount() << std::endl;
	
	return os;
}


