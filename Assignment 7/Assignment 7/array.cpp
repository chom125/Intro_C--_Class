//
//  array.cpp
//  Assignment 7
//
//  Created by Steve Minor on 11/24/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "array.h"

Array::Array(){
	length = 1;
	_array = new int[length];
}

Array::~Array(){
	delete[] _array;
}

int& Array::operator[] (int x) {
	return _array[x];
}

void Array::putAt(int index, int value){
	// insert the value at index. The array must expand to accommodate the new element.
}


void Array::writeAt(int index, int value){
	 // overwrite the value at index.
	_array[index] = value;
}

int Array::getAt(int index) const{
	// returns the element at index.
	return _array[index];
};

void Array::removeAt(int index){
	// removes the data at array the specified index. The array must contract.
	
};