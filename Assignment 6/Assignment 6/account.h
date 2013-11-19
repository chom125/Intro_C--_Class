//
//  account.h
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#ifndef __Assignment_6__account__
#define __Assignment_6__account__

#include <iostream>
#include <vector>
#include <string>
#include "transaction.h"

class Account{
public:
	Account(float startingBalance);
	float getBalance();
	void addTransaction(Transaction t);
	void printTransactions();
private:
	std::vector <Transaction> transactions;
	void calculateBalance();
	float balance;
};

class SavingsAccount: public Account{
public:
	SavingsAccount(float startingBalance);
};

class CheckingAccount: public Account{
public:
	CheckingAccount(float startingBalance, std::string _name="checking");
private:
	bool hasOverdrafted;
	void addOverdraft();
};

#endif /* defined(__Assignment_6__account__) */
