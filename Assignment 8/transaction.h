//
//  transaction.h
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_6__transaction__
#define __Assignment_6__transaction__

#include <string>

class Transaction{
public:
	Transaction(std::string _to,
				std::string _from,
				float _amount,
				std::string _location = "none");
	float getAmount();
	std::string getTo();
	std::string getFrom();
	std::string getLocation();
	
	void setAmount(float _a);
	void setTo(std::string _t);
	void setFrom(std::string _f);
	void setLocation(std::string _l);
private:
	float amount;
	std::string to;
	std::string from;
	std::string location;
};

#endif /* defined(__Assignment_6__transaction__) */
