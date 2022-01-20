#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year > 0 && (month > 0 && month < 13) && (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "非法日期->";
		print();
	}
}

void Date::print()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}

int Date::GetMonthDay(int year, int month)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		if (month == 2) return 29;
		else if (month < 8 && month % 2 == 1) return 31;
		else if (month >= 8 && month % 2 == 0) return 31;
		else return 30;
	}
	else
	{
		if (month == 2) return 28;
		else if (month < 8 && month % 2 == 1) return 31;
		else if (month >= 8 && month % 2 == 0) return 31;
		else return 30;
	}
}

bool Date::operator > (const Date& d)
{
	if (_year > d._year)return true;
	else if (_year == d._day && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
}

Date& Date:: operator +=(const int d)
{
	if (d < 0) return *this -= -d;
	_day += d;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator +(const int d)
{
	Date res(*this);
	res += d;
	return res;
}

// ++d1 前置++
Date& Date::operator++ ()
{
	*this += 1;
	return *this;
}

// d1++ 后置++，需要一个占位参数(区分前置++和后置++的依据)
Date Date::operator++ (int)
{
	Date res(*this);
	res += 1;
	return res;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

bool Date::operator<=(const Date& d)
{
	return (*this < d || *this == d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator-=(const int d)
{
	if (d < 0) return (*this += (-d));
	_day -= d;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(const int d)
{
	Date res(*this);
	res -= d;
	return res;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date res(*this);
	*this -= 1;
	return res;
}