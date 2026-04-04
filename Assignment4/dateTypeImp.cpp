//Implementation file date
   
#include <iostream>
#include "dateType.h"

using namespace std;

bool dateType::isLeapYear() const
{
    if ((dYear % 4 == 0 && dYear % 100 != 0) || (dYear % 400 == 0))
        return true;
    else
        return false;
}

void dateType::setDate(int month, int day, int year) 
{
    if (month < 1 || month > 12) {
        cout << "Invalid month. Setting to default (1)." << endl;
        month = 1;
	}

	int daysInMonth;
    if (month == 2) {
        if (isLeapYear())
            daysInMonth = 29;
        else
            daysInMonth = 28;
    } 
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } 
    else {
		daysInMonth = 31;
    
    }

    if (day < 1 || day > daysInMonth) {
        cout << "Invalid day. Setting to default (1)." << endl;
        day = 1;
	}

    if (year < 1) {
        cout << "Invalid year. Setting to default (1900)." << endl;
        year = 1900;
    } // <-- Added missing closing brace here

    dMonth = month;
    dDay = day;
    dYear = year;
}

int dateType::getDay() const 
{
    return dDay;
}

int dateType::getMonth() const 
{
    return dMonth;
}

int dateType::getYear() const 
{
    return dYear;
}

void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

    //Constructor with parameters
dateType::dateType(int month, int day, int year) 
{ 
    dMonth = month;
    dDay = day;
    dYear = year;
}

