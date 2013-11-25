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
};

Array::~Array(){
	delete[] _array;
};

int& Array::operator[] (int x) {
	return _array[x];
};

void Array::putAt(int index, int value){
	// insert the value at index. The array must expand to
	// accommodate the new element.
	
	
};


void Array::writeAt(int index, int value){
	// overwrite the value at index.
	//_array[index] = value;
	if(index < length){
		(*this)[index] = value; //leverage operator overload
	}
	else{
		putAt(index, value);
	}
};

int Array::getAt(int index) const{
	// returns the element at index.
	// return (*this)[index]; //error "no operator overload[] for const Array"
	return _array[index];
};

void Array::removeAt(int index){
	// removes the data at array the specified index. The array must contract.
	
};

int Array::size(){
	return length;
};

std::ostream& operator<<(std::ostream& os, Array& ar){
	bool first = true;
	for(int i= 0; i < ar.size(); i++){
		if(!first){
			std::cout << ", " <<  ar.getAt(i);
		}else{
			std::cout << ar.getAt(i);
			first = false;
		}
	}
	return os;
};