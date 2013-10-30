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

std::string days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

int dow(const Date& date){
	int y = date.year;
	int m = date.month;
	int d = date.day;
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -=m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

std::string getDayOfWeek(int dayIndex){
	// get the day of the week by name
	return days[dayIndex];
}

// required for following two functions
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

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
	// but that would require 'adding a Februrary' or similar which feels bizarre
	addDays(date, 30);
}

void addYear(Date& date){
	date.year++;
}

Date getNextMonday(Date date){
	// keep adding a day
	// until the day equals monday
	// then return that day
	while (dow(date) != 1){
		date.day++;
	}
	
	return date;
}

void printDate(const Date& date){
	//output the date in a readable format
	std::cout << std::string(20, '*') << std::endl;
	std::cout << "\nmonth : " << date.month << std::endl;
	std::cout << "day : " << date.day << std::endl;
	std::cout << "year : " << date.year << std::endl;
	std::cout << "day of week : " << getDayOfWeek(dow(date)) << std::endl;
	std::cout << std::string(20, '*') << std::endl;
}


TEST(dateTest, Date){
	//validation based on http://www.timeanddate.com/date/weekday.html	
	Date birthday;
	birthday.day = 7;
	birthday.month = 11;
	birthday.year = 1984;
	
	Date dday;
	dday.day = 6;
	dday.month = 6;
	dday.year = 1944;
	
	Date apolloEleven;
	apolloEleven.day = 20;
	apolloEleven.month = 7;
	apolloEleven.year = 1969;
	
	// begin addDay check	
	addDay(birthday);
	CHECK(birthday.day == 8 && birthday.month == 11 && birthday.year == 1984);
	CHECK(getDayOfWeek(dow(birthday)) == "Thursday");
	
	addDay(dday);
	CHECK(dday.day == 7 && dday.month == 6 && dday.year == 1944);
	CHECK(getDayOfWeek(dow(dday)) == "Wednesday");
	
	addDay(apolloEleven);
	CHECK(apolloEleven.day == 21 && apolloEleven.month == 7 && apolloEleven.year == 1969);
	CHECK(getDayOfWeek(dow(apolloEleven)) == "Monday");	
	// end addDay check
	
	// begin addMonth check
	addMonth(birthday);
	CHECK(birthday.day == 8 && birthday.month == 12 && birthday.year == 1984);
	CHECK(getDayOfWeek(dow(birthday)) == "Saturday");
	
	addMonth(dday);
	CHECK(dday.day == 7 && dday.month == 7 && dday.year == 1944);
	CHECK(getDayOfWeek(dow(dday)) == "Friday");
	
	addMonth(apolloEleven);
	CHECK(apolloEleven.day == 20 && apolloEleven.month == 8 && apolloEleven.year == 1969);
	CHECK(getDayOfWeek(dow(apolloEleven)) == "Wednesday");
	// end addMonth check
	
	// begin addYear check
	addYear(birthday);
	CHECK(birthday.day == 8 && birthday.month == 12 && birthday.year == 1985);
	CHECK(getDayOfWeek(dow(birthday)) == "Sunday");
	
	addYear(dday);
	CHECK(dday.day == 7 && dday.month == 7 && dday.year == 1945);
	CHECK(getDayOfWeek(dow(dday)) == "Saturday");
	
	addYear(apolloEleven);
	CHECK(apolloEleven.day == 20 && apolloEleven.month == 8 && apolloEleven.year == 1970);
	CHECK(getDayOfWeek(dow(apolloEleven)) == "Thursday");
	// end addYear check

	// begin getNextMonday check
	Date nmBirthday = getNextMonday(birthday);
	CHECK(nmBirthday.day == 9 && nmBirthday.month == 12 && nmBirthday.year == 1985);
	CHECK(getDayOfWeek(dow(nmBirthday)) == "Monday");
	
	Date nmDDay = getNextMonday(dday);
	CHECK(nmDDay.day == 9 && nmDDay.month == 7 && nmDDay.year == 1945);
	CHECK(getDayOfWeek(dow(nmDDay)) == "Monday");
	
	Date nmApolloEleven = getNextMonday(apolloEleven);
	CHECK(nmApolloEleven.day == 24 && nmApolloEleven.month == 8 && nmApolloEleven.year == 1970);
	CHECK(getDayOfWeek(dow(nmApolloEleven)) == "Monday");
	// end getNextMonday check
}