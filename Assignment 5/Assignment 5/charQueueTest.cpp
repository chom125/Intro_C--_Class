// Assignment 5-1
// Define a class CharQueue so that the public interface does not depend on the representation.
// Implement two versions of CharQueue
// CharQueue1 with a std::deque<char> data member.
// CharQueue2 with a built in array as the data member.
// Note: The representation is the private data member(s) used to track the state of
// the class instances.
// Place each class two files. for example, for CharQueue1 place the class declaration
// in CharQueue1.h. Place the class definition in CharQueue1.cpp.

#include "TestHarness.h"
#include "CharQueue1.h"
#include "CharQueue2.h"
#include <iostream>
#include <deque>

TEST(CharQueue1Test, CharQueue1){
	CharQueue1 cq1;

	cq1.enque('d');
	CHECK_EQUAL(cq1.toString(), "d");
	
	cq1.enque('e');
	CHECK_EQUAL(cq1.toString(), "de");
	
	cq1.enque('f');
	CHECK_EQUAL(cq1.toString(), "def");
	
	cq1.enque('g');	
	CHECK_EQUAL(cq1.toString(), "defg");
	
	cq1.dequeue();
	CHECK_EQUAL(cq1.toString(), "def");
	
	cq1.dequeue();
	CHECK_EQUAL(cq1.toString(), "de");
	
	cq1.dequeue();
	CHECK_EQUAL(cq1.toString(), "d");	
}

TEST(CharQueue2Test, CharQueue2){
	CharQueue2 cq2;
	
	cq2.enque('d');
	CHECK_EQUAL(cq2.toString(), "d");
	
	cq2.enque('e');
	CHECK_EQUAL(cq2.toString(), "de");
	
	cq2.enque('f');
	CHECK_EQUAL(cq2.toString(), "def");
	
	cq2.enque('g');
	CHECK_EQUAL(cq2.toString(), "defg");
	
	cq2.dequeue();
	CHECK_EQUAL(cq2.toString(), "def");
	
	cq2.dequeue();
	CHECK_EQUAL(cq2.toString(), "de");
	
	cq2.dequeue();
	CHECK_EQUAL(cq2.toString(), "d");
}