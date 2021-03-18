
#include "Date.h"

int Days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // колличество дней в месяцах невисокосного года

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
		if (year % 4 == 0 && year % 100 != 0) {
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
		if (Year % 4 == 0 && Year % 100 != 0) {
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
	int day = days;
	Date d = *this;
	if (day >= 0) {
		if (day >= 365249) {
			d.Year += 1000 * (int)(day / 365249);
			day = day % 365249;
		}
		if (day >= 36524) {
			d.Year += 100 * (int)(day / 36524);
			day = day % 36524;
		}
		while (day > 365) {
			
				if (d.Month > 2 ? (d.Year + 1) % 4 != 0 || (d.Year + 1) % 100 == 0 : d.Year  % 4 != 0 || d.Year % 100 == 0) {
					d.Year++;
					day = day - 365;
				}
				else {
					d.Year++;
					day = day - 366;
				}
			
		}
		for (int i = 0; i < day;i++) {
			if (d.Month != 2) {
				if (d.Day < Days[d.Month]) {
					d.Day++;
				}
				else {
					d.Day = 1;
					d.Month++;
					if (d.Month == 13) {
						d.Year++;
						d.Month = 1;
					}
				}
			}
			else {
				if (d.Year % 4 != 0 || d.Year % 100 == 0) {
					if (d.Day < Days[d.Month]) {
						d.Day++;
					}
					else {
						d.Day = 1;
						d.Month++;
					}
				}
				else {
					if (d.Day < Days[d.Month] + 1) {
						d.Day++;
					}
					else {
						d.Day = 1;
						d.Month++;
					}
				}
				
			}
		}
	}

	return d;
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

ostream& operator<<(ostream& out, const Date& date)
{
	
	out << setfill('0') << setw(2) << date.Day << ":" << setfill('0') << setw(2) << date.Month << ":" << date.Year;
	return out;
}

istream& operator>>(istream& in, Date& date)
{
	in >> date.Day;
	in.ignore(1);
	in >> date.Month;
	in.ignore(1);
	in >> date.Year;
	assert(date.Month <= 12 && date.Month >= 1);
	if (date.Month == 2 && date.Year % 4 == 0 && date.Year % 100 != 0) {
		assert(date.Day <= Days[2] + 1);
	}
	else {
		assert(date.Day <= Days[date.Month]);
	}
	return in;
}
