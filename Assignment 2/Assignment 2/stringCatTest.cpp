// Assignment 2-4
// Write a function cat() that takes two C-style string arguments and returns
// a string that is the concatenation of the arguments. Use new to find store
// for the result. Write another function cat that takes two const std::string&
// arguments and returns a std::string that is a concatenation of the arguments.
// The std::string version does not require new. Which is the better approach?

#include "TestHarness.h"
#include <iostream>

char* cat(char* s1, char* s2){
	const int totalSize = int(strlen(s1) + strlen(s2) + 1); //both strings + null character
	char* result = new char[totalSize];
	strncpy(result, s1, strlen(s1)); //copy s1 to result first
	strcat(result, s2); //now s1 is unaffected 
	return result; //memory leak? would like deallocation to happen here
}

std::string cat(std::string& s1, std::string& s2){
	return s1 + s2;
}

TEST(cStyleConcatTest, charArray){
	char s1[] = "this";
	char s2[] = "that";
	char s3[] = "theother";
	char s4[] = "stillmore";
	
	char* s1Test = cat(s1, s2);
	char* s2Test = cat(s2, s3);
	char* s3Test = cat(s3, s4);
	
	CHECK(strcmp(s1Test, "thisthat") == 0);
	CHECK(strcmp(s2Test, "thattheother") == 0);
	CHECK(strcmp(s3Test, "theotherstillmore") == 0);
	
	delete[] s1Test; //dirty
	delete[] s2Test;
	delete[] s3Test;	
}

TEST(stringConcatTest, string){
	std::string s1 = "this";
	std::string s2 = "that";
	std::string s3 = "theother";
	std::string s4 = "stillmore";
	
	CHECK_EQUAL(cat(s1, s2), "thisthat");
	CHECK_EQUAL(cat(s2, s3), "thattheother");
	CHECK_EQUAL(cat(s3, s4), "theotherstillmore");	
}