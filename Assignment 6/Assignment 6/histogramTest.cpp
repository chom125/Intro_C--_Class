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
#include <locale>
#include <fstream>
#include <string>

#include <unistd.h>

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
	Histogram hist;
	char c;
	
	//TODO: make the path to RoM.txt an argument in main
	fstream file("/Users/steveminor/Documents/C++/Intro_C++_Class/Assignment 6/Assignment 6/RoM.txt", fstream::in);
	if(file.is_open()){
		while((c = file.get()) != -1){
			parseAdd(string(&c), hist);
		}
	}
	
	hist.print();
	
	file.close();
}