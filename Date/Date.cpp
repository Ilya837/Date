﻿
#include "Date.h"

int Days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}

Date::Date(const Date& date)
{
	Day = date.Day;
	Month = date.Month;
	Year = date.Year;
}

Date::Date(const int day, const int month, const int year)
{
	assert(month <= 12 && month >= 0);
	if (month != 2) {
			assert(day <= Days[month] && day > 0);
	}
	else {
		if (year % 4 == 0 && year % 1000 != 0) {
			assert(day <= Days[month]+1 && day > 0);
		}
		else {
			assert(day <= Days[month]  && day > 0);
		}
	}
	Day = day;
	Month = month;
	Year = year;
}

Date::Date(string date)
{
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	Year = 0;
	for(int i = 6; date[i] != '\0';i++){
		Year = Year * 10 + (date[i] - '0');
	}
	assert(month <= 12 && month >= 0);
	if (month != 2) {
		assert(day <= Days[month] && day > 0);
	}
	else {
		if (Year % 4 == 0 && Year % 1000 != 0) {
			assert(day <= Days[month] + 1 && day > 0);
		}
		else {
			assert(day <= Days[month] && day > 0);
		}
	}
	Day = day;
	Month = month;
	int a = 0;
}

Date::~Date()
{
}

Date Date::operator=(const Date& date)
{
	Day = date.Day;
	Month = date.Month;
	Year = date.Year;
	return *this;
}

Date Date::operator+(const int& days) const
{

	return Date();
}

bool Date::operator<(const Date& date)
{
	if (date.Year > Year) {
		return true;
	}
	if (date.Month > Month) {
		return true;
	}
	if (date.Day > Day) {
		return true;
	}
	return false;
}

bool Date::operator>(const Date& date)
{
	bool a = *this < date ? false : true;
	if (date.Year == Year && date.Month == Month && date.Day == Day) a = false;
	return a;
}

bool Date::operator<=(const Date& date)
{
	
	return *this > date ? false : true;
}

bool Date::operator>=(const Date& date)
{
	return *this < date ? false : true;
}

bool Date::operator==(const Date& date)
{
	if (date.Year == Year && date.Month == Month && date.Day == Day) return true;
	return false;
}

//ostream& operator<<(ostream& out, const Date& date)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//istream& operator>>(ostream& in, const Date& date)
//{
//	// TODO: вставьте здесь оператор return
//}