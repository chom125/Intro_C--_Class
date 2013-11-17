// Assignment 6-2
// We require a container, Histogram, that can be used to keep count of the number
// of alphas (letter or digit), digits (0..9), punctuation, and whitespace (\t, \v,
//	\f, \r, or \n) characters in an input file.
// Develop the use cases for the Histogram.
// Develop a class diagram for the Histogram. Remember, a histogram
// is a container. It stores things; it does not do any parsing.
// Implement the Histogram class.
// Write a function parseAdd that takes a std::string by const reference
// and an instance of the Histogram by reference. Invoke the function parseAdd
// to parse the string and update the Histogram entries.
// In addition to being able to individually access query the number of entries in
// any of the categories, overload the ostream operator to support printing
// instances of a Histogram to stdout.

#include "TestHarness.h"
#include "histogram.h"
#include <iostream>
#include <locale> //isdigit(), isaplha(), isspace(), ispunct()
#include <fstream> //file input
#include <string>

using namespace std;

void parseAdd(const std::string& s, Histogram& h){
	locale loc;
	
	// convert back to character to use isDigit, isWhitespace, etc
	char * c = new char[s.length()+1];
	c = strcpy(c, s.c_str());
	
	if(isdigit(s[0], loc)){
		h.addDigit();
	}
	else if(isalpha(s[0], loc)){
		h.addLetter();
	}
	else if(isspace(s[0], loc)){
		h.addWhitespace();
	}
	else if(ispunct(s[0], loc)){
		h.addPunctuation();
	}
	
	delete [] c;
}

TEST(histogramTest, histogram){
	Histogram hist, hist2;
	char c;
	
	fstream file("/Users/steveminor/Documents/C++/Intro_C++_Class/Assignment 6/Assignment 6/hist.txt", fstream::in);
	if(file.is_open()){
		while((c = file.get()) != -1){
			parseAdd(string(&c), hist);
		}
	}
	
	fstream file2("/Users/steveminor/Documents/C++/Intro_C++_Class/Assignment 6/Assignment 6/hist1.txt", fstream::in);
	if(file2.is_open()){
		while((c = file2.get()) != -1){
			parseAdd(string(&c), hist2);
		}
	}
	
	//hist
	CHECK_EQUAL(hist.getDigitCount(), 10);
	CHECK_EQUAL(hist.getLetterCount(), 52);
	CHECK_EQUAL(hist.getPunctuationCount(), 9);
	CHECK_EQUAL(hist.getWhitespaceCount(), 3);
	
	//hist2
	CHECK_EQUAL(hist2.getDigitCount(), 6);
	CHECK_EQUAL(hist2.getLetterCount(), 9);
	CHECK_EQUAL(hist2.getPunctuationCount(),12);
	CHECK_EQUAL(hist2.getWhitespaceCount(), 10);
	
	// uncomment to see output
	// cout << hist;
	// cout << hist2;
	
	file.close();
}