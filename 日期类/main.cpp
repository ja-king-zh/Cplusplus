#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int main()
{
	Date d1;
	d1.print();
	Date d2(2022, 1, 18);
	d2.print();
	Date d3(2020, 2, 29);

	return 0;
}