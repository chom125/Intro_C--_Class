//
//  account.cpp
//  Assignment 6
//
//  Created by Steve Minor on 11/18/13.
//  Copyright (c) 2013 Steve Minor. All rights reserved.
//

#include "account.h"

const float OVERDRAFT_FEE = -35.0;

Account::Account(float startingBalance):
balance(startingBalance){}

float Account::getBalance(){
	return balance;
};

void Account::addTransaction(Transaction t){
	transactions.push_back(t);
	balance += t.getAmount();
};

void Account::printTransactions(){
//	std::cout << "Balance for account:" << name << std::endl;
	std::cout << "Balance for account:" << std::endl;
	std::cout << std::string(50, '*') << std::endl;
	std::cout << "to\t\t|from\t\t|amount\t\t|location" << std::endl;
	for(std::vector<Transaction>::iterator i = transactions.begin(); i != transactions.end(); i++){
		std::cout << i->getTo() << "\t\t" << i->getFrom() << "\t\t" << i->getAmount() << "\t\t" << i->getLocation() << std::endl;
	}
	std::cout << std::string(50, '*') << std::endl;
	std::cout << "Ending balance: " << balance << std::endl;
};


void Account::calculateBalance(){
	// go through each transaction and add the amounts
	// would want to use this if transactions
	// needed to be edited/removed
	float total = 0.0;
	for(std::vector<Transaction>::iterator i = transactions.begin(); i != transactions.end(); i++){
		total += i->getAmount();
	}	
	balance = total;
};

SavingsAccount::SavingsAccount(float startingBalance):
	Account(startingBalance){
};


CheckingAccount::CheckingAccount(float startingBalance, std::string _name):
	Account(startingBalance),
	hasOverdrafted(false){}

void CheckingAccount::addOverdraft(){
	//if balance is below 0, add a transaction of OVERDRAFT_FEE from customer to bank
};


