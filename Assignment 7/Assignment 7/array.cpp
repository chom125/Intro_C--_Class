//
//  array.cpp
//  Assignment 7
//
//  Created by Steve Minor on 11/24/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "array.h"

int& Array::operator[] (int x) {
	return _array[x];
};

Array::Array(){
	length = 1;
	_array = new int[length];
	_init(_array, length);
};

Array::~Array(){
	delete[] _array;
};

Array::Array(const Array& ar){
	length = ar.length;
	_array = new int[length];
	_init(_array, length);
	
	for(int i = 0; i < length; i++){
		_array[i] = ar._array[i];
	}
};

void Array::_init(int* ar, int size){
	//ensure that values are initialized to 0
	for(int i = 0; i < size; i++){
		ar[i] = 0;
	};
};

void Array::putAt(int index, int value){
	// insert the value at index. The array must expand to
	// accommodate the new element.
	if(index > length){
		int * t = new int[index+1];
		_init(t, index+1);
		
		for(int i = 0; i < length; i++){
			t[i] = _array[i];
		}
		t[index] = value;
		delete [] _array;
		_array = t;
		length = index+1;
	}
	else{
		int * t = new int[length+1];
		for(int i = 0; i <= length; i++){
			if(i < index){
				t[i] = _array[i];
			}
			else if(i == index){
				t[i] = value;
			}
			else{
				t[i] = _array[i-1];
			}
		}
		delete [] _array;
		_array = t;
		length++;
	}	
};


void Array::writeAt(int index, int value){
	// overwrite the value at index.
	if(index < length){
		//_array[index] = value;
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
	int *t = new int[length-1];
	for(int i = 0; i < length; i++){
		if(i < index){
			t[i] = _array[i];
		}else if(i >= index){
			t[i] = _array[i+1];
		}
	}
	delete [] _array;
	_array = t;
	length--;
	
};

int Array::size(){
	return length;
};

std::ostream& operator<<(std::ostream& os, Array& ar){
	bool first = true;
	for(int i= 0; i < ar.size(); i++){
		if(!first){
			os << ", " <<  ar.getAt(i);
		}else{
			os << ar.getAt(i);
			first = false;
		}
	}
	return os;
};