//
//  array.h
//  Assignment 7
//
//  Created by Steve Minor on 11/24/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_7__array__
#define __Assignment_7__array__

#include <iostream>

class Array{
private:
	int* _array;
	int length;
public:
	Array();
	~Array();
	
	int& operator[] (int x);
	int size();
	
	void putAt(int index, int value); // insert the value at index. The array must expand to accommodate the new element.
	void writeAt(int index, int value); // overwrite the value at index.	
	int getAt(int index) const; // returns the element at index.	
	void removeAt(int index); // removes the data at array the specified index. The array must contract.
};


std::ostream& operator<<(std::ostream& os, Array& ar);
#endif /* defined(__Assignment_7__array__) */
