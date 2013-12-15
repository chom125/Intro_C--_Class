//
//  customer.cpp
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "customer.h"
#include <iostream>

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

Address Customer::getAddress(){
	return address;
};

std::string Customer::getName(){
	return getFirstName() + " " + getLastName();
};

std::string Customer::getFirstName(){
	return firstName;
};

std::string Customer::getLastName(){
	return lastName;
};

Account* Customer::getAccount(std::string name, Customer& cust){
	if(name == "checking"){
		return &cust.checking;
	}else if(name == "savings"){
		return &cust.savings;
	}
};

void Customer::printInfo(const Customer& cust){
	//can't acceess cust public methods. why?
	std::cout << cust.firstName << " " << cust.lastName << std::endl;
	std::cout << cust.address.line1 << std::endl;
	std::cout << cust.address.line2 << std::endl;
	std::cout << cust.address.city << ", " <<cust.address.state << std::endl;
	std::cout << cust.address.zip << std::endl;
};

std::ostream& operator<<(std::ostream& os, Customer& cust){
	Customer::printInfo(cust);
	
	Account* checking = Customer::getAccount("checking", cust);
	Account* savings = Customer::getAccount("savings", cust);
	
	Account::printTransactions("checking", checking);
	Account::printTransactions("savings", savings);
	return os;
};