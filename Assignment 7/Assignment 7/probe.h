//
//  probe.h
//  Assignment 7
//
//  Created by Steve Minor on 11/23/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_7__probe__
#define __Assignment_7__probe__

#include <iostream>

class Probe{
public:
//	Probe();
//	Probe(Probe& p);
//	~Probe();
	void increment();
	void decrement();
	
	void operator++(int i); //probe++
	void operator++(); //++probe
	void operator--(int i);
	
	unsigned int getTotal();
	unsigned int getCurrent();
private:
	unsigned int total;
	unsigned int current;
};

std::ostream& operator<<(std::ostream& os, Probe& p);

#endif /* defined(__Assignment_7__probe__) */
