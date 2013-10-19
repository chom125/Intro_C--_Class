//Assignment 2-2
//Define a table of the names of months of the year and the number of days in each month.
//Write out that table to a stringstream. Do this twice; once using an array of char for
//the names and an array for the number of days and a second time using an array of structures,
//with each structure holding the name of a month and the number of days in it.

#include "TestHarness.h"
#include <iostream>

TEST(tableArraysTest, stringstream){
	std::stringstream sTable;
	
	const int NUM_MONTHS = 12;
	char monthNames[][NUM_MONTHS] = {
		"January",
		"Frebruary",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	
	int numDays[NUM_MONTHS] = {
		31,
		28,
		31,
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};
	
	for(int i = 0; i < NUM_MONTHS; i++){
		sTable << monthNames[i] << "\t" << numDays[i] << std::endl;
		CHECK_EQUAL(!sTable, false);
	}
	
	//std::cout << sTable.str() << std::endl; //actually output the table
	CHECK_EQUAL(!sTable, false);
}

TEST(tableArStructTest, stringstream){
	std::stringstream sTable;
	
	const int NUM_MONTHS = 12;
	
	struct MONTH{
		std::string name;
		int days;
	}months[NUM_MONTHS] ={
		{"January", 31},
		{"Frebruary", 28},
		{"March", 31},
		{"April", 30},
		{"May", 31},
		{"June", 30},
		{"July", 31},
		{"August", 31},
		{"September", 30},
		{"October", 31},
		{"November", 30},
		{"December", 31}
	};
	
	for(int i = 0; i < NUM_MONTHS; i++){
		sTable << months[i].name << "\t" << months[i].days << std::endl;
		CHECK_EQUAL(!sTable, false);
	}
	
	//std::cout << sTable.str() << std::endl; //actually output the table
	CHECK_EQUAL(!sTable, false);
}

