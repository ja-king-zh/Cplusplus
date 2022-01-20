#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1);
	void print();
	int GetMonthDay(int year, int month);
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator!=(const Date& d);
	Date& operator+=(const int d);
	Date operator+(const int d);
	Date& operator-=(const int d);
	Date operator-(const int d);
	// ++d1 前置++
	Date& operator++ ();
	// d1++ 后置++，需要一个占位参数(区分前置++和后置++的依据)
	Date operator++ (int);
	Date& operator--();
	Date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};