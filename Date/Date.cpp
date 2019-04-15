#include "Date.h"
//打印
void Date::Print()const
{
	std::cout << _year << "-" << _month << "-" << _day << std::endl;
}

//获取月的天数
int Date::GetMonthDay(int year, int month)const
{
	static int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//是闰年的话2月返回29天
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return array[month];
}

//构造函数
Date::Date(int year, int month, int day)
{
	//判断年月日是否合法
	if (year > 0 && 
		month > 0 && month<13 && 
		day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		std::cout << "Date Invalid" << std::endl;
	}
}

//析构函数
Date::~Date()
{}

//拷贝构造Date d2(d1);
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//赋值运算符重载
Date& Date::operator=(const Date& d)
{
	if (this != &d)//防止自己给自己赋值
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//可以支持连续赋值
}

//判断日期大小或相等
bool Date::operator==(const Date&d)const
{
	return _year == d._year 
		&& _month == d._month 
		&& _day == d._day;
}
bool Date::operator!=(const Date&d)const
{
	return !(*this == d);
}
bool Date::operator>(const Date&d)const
{
	return (_year > d._year)
		|| (_year == d._year&&_month > d._month)
		|| (_year == d._year&&_month == d._month&&_day > d._day);
}
bool Date::operator<(const Date&d)const
{
	return !(*this > d);
}
bool Date::operator>=(const Date&d)const
{
	return (*this > d) || (*this == d);
}
bool Date::operator<=(const Date&d)const
{
	return (*this < d) || (*this == d);
}

//关于日期的加减

////d1+100----d1不发生改变
////不复用实现+
//Date Date::operator+(int day)const
//{
//	Date ret(*this);
//	ret._day += day;
//	while (ret._day > GetMonthDay(ret._year, ret._month))//大于该月天数就不合法
//	{
//		ret._day -= GetMonthDay(ret._year, ret._month);
//		ret._month++;
//		if (ret._month == 13)
//		{
//			ret._year++;
//			ret._month = 1;
//		}
//	}
//	return ret;
//}

//复用+=实现+
Date Date::operator+(int day)const
{
	Date ret(*this);
	ret += day;
	return ret;
}

////d1-100----d1不发生改变
////不复用实现-
//Date Date::operator-(int day)const
//{
//	Date ret(*this);
//	ret._day -= day;
//	while (ret._day <= 0)//小于和等于0都不合法
//	{
//		--ret._month;//借的是上个月的天数
//		if (ret._month == 0)
//		{
//			ret._year--;
//			ret._month = 12;
//		}
//		ret._day += GetMonthDay(ret._year, ret._month);		
//	}
//	return ret;
//}

//复用-=实现-
Date Date::operator-(int day)const
{
	Date ret(*this);
	ret -= day;
	return ret;
}

//实现+=
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

//实现-=
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

//d1-d2
int Date::operator-(Date& d)const//日期减日期，返回值是天数int
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		Date max = d;
		Date min = *this;
		flag = -1;
	}
	int num = 0;
	while (max != min)
	{
		min++;
		num++;
	}
	return num;
}

//前置++(d.operator++(&d))
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//后置++(d.operator++(&d,0))
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

//前置--(d.operator--(&d))
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//后置--(d.operator--(&d,0))
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

