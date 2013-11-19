// Assignment 6-1
// Let's now complete the banking problem that was specified and designed in Assignment
// 4. First, write the C++ code and classes that implement that design. Next, test
// the program, including boundary conditions, to ensure that it behaves as you (and
// the customer) intended. Overload the ostream operator to support printing
// instances of a customer account to the monitor, a stringstream, or to a file.

//customer class
//transaction class
//account class (contains 1-many transactions) and customer associations
//<< should display current balance

#include "account.h"
#include "customer.h"
#include "TestHarness.h"
#include "transaction.h"
#include <iostream>

using namespace std;

TEST(bankTest, Banking){
	Address testAddress1("1234 5th St", "Apt 6", "Seattle", "WA", "98105");
	
	Customer sm("Steve", "Minor", testAddress1);
	Customer hw("Hillary", "Warden", testAddress1);
	
	Account* smchk = Customer::getAccount("checking", sm);
	Account* smsv = Customer::getAccount("savings", sm);
	smchk->addTransaction(Transaction("hillary", "steve", -50));
	smchk->addTransaction(Transaction("steve",	"hillary", 50));
	smchk->addTransaction(Transaction("hillary", "steve", -100));
	smchk->addTransaction(Transaction("steve", "hillary", 75));
	smchk->addTransaction(Transaction("hillary", "steve", -50));
	
	smsv->addTransaction(Transaction("steve", "nordstrom", 100));
	smsv->addTransaction(Transaction("steve", "nordstrom", 100));
	smsv->addTransaction(Transaction("steve", "nordstrom", 100));
	smsv->addTransaction(Transaction("steve", "nordstrom", 100));
	Customer::printInfo(sm);
	Account::printTransactions("checking", smchk);
	Account::printTransactions("savings", smsv);
	
	Customer& sm_ref = sm;
	//cout << sm_ref;
	
}