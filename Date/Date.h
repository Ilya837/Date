#pragma once
#include <iostream>
#include <assert.h>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Date
{
private:
	 int Day, Month, Year;
public:
	Date();
	Date(const Date& date);
	Date(const int day, const int mouth, const int year);
	Date(string date);
	~Date();
	Date operator = (const Date& date);
	Date operator - (const  long double& days) const;
	Date operator + (const  long double& days) const;
	bool operator < (const Date& date);
	bool operator > (const Date& date);
	bool operator <= (const Date& date);
	bool operator >= (const Date& date);
	bool operator == (const Date& date);
	friend ostream& operator << (ostream& out, const Date& date);
	friend istream& operator >> (istream& in,  Date& date);
	
};
