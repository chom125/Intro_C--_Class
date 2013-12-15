//
//  customer.h
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_6__customer__
#define __Assignment_6__customer__

#include "account.h"
#include <string>

struct Address{
	Address(std::string _line1,
			std::string _line2,
			std::string _city,
			std::string _state,
			std::string _zip);
	std::string line1;
	std::string line2;
	std::string city;
	std::string state;
	std::string zip;
};

class Customer{
public:
	Customer(std::string _firstName,
			 std::string _lastName,
			 Address _address,
			 float startingChecking = 0,
			 float startingSavings = 0);
	Address getAddress();
	std::string getName();
	std::string getFirstName();
	std::string getLastName();
	
	static Account* getAccount(std::string name, Customer& cust);
	static void printInfo(const Customer& cust);
private:
	std::string firstName;
	std::string lastName;
	Address address;
	CheckingAccount checking;
	SavingsAccount savings;
};

std::ostream& operator<<(std::ostream& os, Customer& cust);

#endif /* defined(__Assignment_6__customer__) */
