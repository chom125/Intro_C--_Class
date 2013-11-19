//
//  customer.cpp
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "customer.h"

Address::Address(std::string _line1,
				 std::string _line2,
				 std::string _city,
				 std::string _state,
				 std::string _zip):
line1(_line1),
line2(_line2),
city(_city),
state(_state),
zip(_zip){}

Customer::Customer(std::string _firstName,
				   std::string _lastName,
				   Address _address,
				   float startingChecking,
				   float startingSavings):
firstName(_firstName),
lastName(_lastName),
address(_address),
checking(startingChecking),
savings(startingSavings){}

std::string Customer::getName(){
	return getFirstName() + " " + getLastName();
}

std::string Customer::getFirstName(){
	return firstName;
};

std::string Customer::getLastName(){
	return lastName;
};

Account* Customer::getAccount(std::string name){
	if(name == "checking"){
		return &checking;
	}else if(name == "savings"){
		return &savings;
	}
};