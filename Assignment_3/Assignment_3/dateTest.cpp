// Assignment 3-1
// Write functions to add one day, another function to add one month, and yet another
// function to add one year to a Date struct. Write a function that gives the day of
// the week for a given Date. Write a function that returns the Date of the first Monday
// following a given Date. Return the date by value. Pass Dates by reference when
// appropriate (i.e., Date& or const Date&).

#include "TestHarness.h"
#include <iostream>
#include <string>

struct Date
{
    int year;
    int month;
    int day;
};

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

std::string months[] = {
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

std::string days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

int getCenturyNumber(const Date& date){
	// see centuries table:
	// http://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
	// basic method for mental calculation requires a century number
	// 0-2-4-6 for 2000, 2100, 2200, 2300 (first two digits % 4)
	return (date.year/100) % 4;
}

int getDayOfWeek(const Date& date){
	// using basic method for mental calculation:
	// http://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
	// d + m + y + (y/4) + c;
	// returns index for use with days[]
	return date.day + date.month + date.year + (date.year/4) + ((date.year/100) % 4);
}

std::string getDayOfWeek(int dayIndex){
	// get the day of the week by name
	return days[dayIndex];
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i; //sets month via pointer
	*pday = yearday; //sets day via pointer
}

void addDays(Date& date, int days){
	int doy = day_of_year(date.year, date.month, date.day) + days; 
	int* pmonth = &date.month; //Address of month member or same address as reference
	int* pday = &date.day;
	month_day(date.year, doy, pmonth, pday);
}

void addDay(Date& date){
	addDays(date, 1);
}

void addMonth(Date& date){
	// broad assumption that adding a month is 30 days
	// could add a switch statement using dayTab and switch statement,
	// but that would require 'adding a Februrary' which feels bizarre
	addDays(date, 30);
}

void addYear(Date& date){
	date.year++;
}

Date getNextMonday(const Date&){
	// keep adding a day
	// until the day equals monday
	// then return that day
}

void printDate(const Date& date){
	std::cout << "\nday : " << date.day << std::endl;
	std::cout << "month : " << date.month << std::endl;
	std::cout << "year : " << date.year << std::endl;
}



TEST(dateTest, Date){
	Date birthday;
	birthday.day = 7;
	birthday.month = 11;
	birthday.year = 1984;
	
	addDay(birthday);
	printDate(birthday);
	std::cout << std::string('*', 20) << std::endl;
	addMonth(birthday);
	printDate(birthday);
	std::cout << std::string('*', 20) << std::endl;
	addYear(birthday);
	printDate(birthday);
	
}