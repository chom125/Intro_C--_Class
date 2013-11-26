// An array is a common structure for storing information. In many languages, one must
// specify the size of the array in advance of its use. Frequently, however, one does
// not know how much data will need to be stored. A common solution is to declare the
// array to be much larger than is expected will be necessary in hopes that it will
// be large enough. This is certainly not the most efficient solution.
// In this problem, you are to design an array that expands as data is entered, contracts
// when it is removed, and supports the following access methods:
//
//// insert the value at index. The array must expand to accommodate the new element.
// void putAt(int index, int value);
//
//// overwrite the value at index.
// void writeAt(int index, int value);
//
//// returns the element at index.
// int getAt(int index) const;
//
//// removes the data at array the specified index. The array must contract.
// void removeAt(int index);
//
// Provide the subscript operator operator[] to return the data at the specified array
// index. This allows the array class to be used like a built in array.
//
// Provide the subscript operator operator[] to overwrite the data at the specified
// array index.  This allows the array class to be used like a built in array.
//
// Write an overloaded stream operator to display the contents of the array.
// Write and test a copy constructor for the dynamic array class.
// Write and test an assignment operator for the dynamic array class.
// QUESTION: In this case, why is it better to write our own copy constructor and assignment
// operator rather than rely on the compiler generated ones?
// ANSWER: Our class is dependant on heap memory that we ourselves are allocating. It's our
// responsibility to clean it up to avoid memory leaks.
// QUESTION: In what situation might it be better to rely on the compiler generated copy constructor
// and assignment operators?
// ANSWER: When the class leverages pre built types with complete deconstructors. 

#include "TestHarness.h"
#include "array.h"
#include <iostream>
#include <sstream>


TEST(putAtTest, Array){
	Array a;
	std::stringstream ss;
	
	ss << a;	
	CHECK_EQUAL("0", ss.str());
	ss.str(std::string());
	
	a.putAt(0, 5);
	ss << a;
	CHECK_EQUAL("5, 0", ss.str());
	ss.str(std::string());
	
	a.putAt(0, 2);
	ss << a;
	CHECK_EQUAL("2, 5, 0", ss.str());
	ss.str(std::string());
	
	a.putAt(10, 3);
	ss << a;
	CHECK_EQUAL("2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 3", ss.str());
	ss.str(std::string());
	
	a.putAt(4, 4);
	ss << a;
	CHECK_EQUAL("2, 5, 0, 0, 4, 0, 0, 0, 0, 0, 0, 3", ss.str());
};

TEST(writeAtTest, Array){
	Array a;
	std::stringstream ss;
	
	ss << a;
	CHECK_EQUAL("0", ss.str());
	ss.str(std::string());
	
	a.writeAt(0, 3);
	ss << a;
	CHECK_EQUAL("3", ss.str());
	ss.str(std::string());
	
	//should use putAt behavior
	a.writeAt(3, 3);
	ss << a;
	CHECK_EQUAL("3, 0, 0, 3", ss.str());
};

TEST(removeAtTest, Array){
	Array a;
	std::stringstream ss;
	
	ss << a;
	CHECK_EQUAL("0", ss.str());
	ss.str(std::string());
	
	a.putAt(5, 5);
	ss << a;
	CHECK_EQUAL("0, 0, 0, 0, 0, 5", ss.str());
	ss.str(std::string());
	
	a[1] = 1;
	ss << a;
	CHECK_EQUAL("0, 1, 0, 0, 0, 5", ss.str());
	ss.str(std::string());
	
	a[2] = 2;
	ss << a;
	CHECK_EQUAL("0, 1, 2, 0, 0, 5", ss.str());
	ss.str(std::string());
	
	a[3] = 3;
	a[4] = 4;
	ss << a;
	CHECK_EQUAL("0, 1, 2, 3, 4, 5", ss.str());
	ss.str(std::string());
	
	a.removeAt(2);
	ss << a;
	CHECK_EQUAL("0, 1, 3, 4, 5", ss.str());
	ss.str(std::string());
	
	a.removeAt(4);
	ss << a;
	CHECK_EQUAL("0, 1, 3, 4", ss.str());
};

TEST(assignGetAtTest, Array){
	Array a;
	std::stringstream ss;
	
	ss << a;
	CHECK_EQUAL("0", ss.str());
	ss.str(std::string());
	
	a[0] = 5;
	CHECK_EQUAL(5, a[0]);
	CHECK_EQUAL(5, a.getAt(0));
};


TEST(copyConstructorTest, Array){
	Array a;
	std::stringstream ss;
	
	a.putAt(5, 5);
	ss << a;
	CHECK_EQUAL("0, 0, 0, 0, 0, 5", ss.str());
	ss.str(std::string());

	Array b(a);
	ss << b;
	CHECK_EQUAL("0, 0, 0, 0, 0, 5", ss.str());
	
};
