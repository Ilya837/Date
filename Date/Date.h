#pragma once
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

class Date
{
	int Day, Month, Year;
public:
	Date();
	Date(const Date& date);
	Date(const int day, const int mouth, const int year);
	Date(string date);
	~Date();
	Date operator = (const Date& date);
	Date operator + (const int& days) const;
	bool operator < (const Date& date);
	bool operator > (const Date& date);
	bool operator <= (const Date& date);
	bool operator >= (const Date& date);
	bool operator == (const Date& date);
	friend ostream& operator << (ostream& out, const Date& date);
	friend istream& operator >> (ostream& in, const Date& date);
	
};
