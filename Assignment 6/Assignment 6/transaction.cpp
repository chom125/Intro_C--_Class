//
//  transaction.cpp
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "transaction.h"

Transaction::Transaction(std::string _to,
						 std::string _from,
						 float _amount,
						 std::string _location):
to(_to),
from(_from),
amount(_amount),
location(_location){}


//getters
float Transaction::getAmount(){
	return amount;
};

std::string Transaction::getTo(){
	return to;
};

std::string Transaction::getFrom(){
	return from;
};

std::string Transaction::getLocation(){
	return location;
}

//setters
void Transaction::setAmount(float _a){
	amount = _a;
};

void Transaction::setTo(std::string _t){
	to = _t;
};

void Transaction::setFrom(std::string _f){
	from = _f;
};

void Transaction::setLocation(std::string _l){
	location = _l;
};