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
// In this case, why is it better to write our own copy constructor and assignment
// operator rather than rely on the compiler generated ones?
// In what situation might it be better to rely on the compiler generated copy constructor
// and assignment operators?

#include "TestHarness.h"
#include "array.h"
#include <iostream>

TEST(arrayTest, Array){
	Array a;
	a.writeAt(0, 6);
	
	std::cout << a;
};
