//
//  probe.cpp
//  Assignment 7
//
//  Created by Steve Minor on 11/23/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "probe.h"

void Probe::increment(){
	total++;
	current++;
}

void Probe::decrement(){
	current--;
}

//probe can't have static member data
//Probe::Probe(){
//	//increment();
//}
//
//Probe::Probe(Probe& p){
//	increment();
//}
//
//Probe::~Probe(){
//	//decrement();
//}

// keep for demonstrative purposes but do not use
void Probe::operator++(int i){
	increment();
}

// keep for demonstrative purposes but do not use
void Probe::operator++(){
	++total;
	++current;
}

// keep for demonstrative purposes but do not use
void Probe::operator--(int i){
	decrement();
}

unsigned int Probe::getTotal(){
	return total;
}

unsigned int Probe::getCurrent(){
	return current;
}

std::ostream& operator<<(std::ostream& os, Probe& p){
	std::cout << "total instances: " << p.getTotal() << std::endl;
	std::cout << "current instances: " << p.getCurrent() << std::endl;
	return os;
};
