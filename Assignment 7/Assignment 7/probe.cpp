//
//  probe.cpp
//  Assignment 7
//
//  Created by Steve Minor on 11/23/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "probe.h"

unsigned int Probe::count = 0;

void Probe::increment(){
	count++;
}

void Probe::decrement(){
	count--;
}

Probe::Probe(){
	increment();
}

Probe::Probe(Probe& p){
	increment();
}

Probe::~Probe(){
	decrement();
}

void Probe::operator++(int i){
	increment();
}

void Probe::operator++(){
	++count;
}

void Probe::operator--(int i){
	decrement();
}
