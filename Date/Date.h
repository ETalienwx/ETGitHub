#pragma once
#include <iostream>
class Date
{
public:
	void Print()const;
	int Date::GetMonthDay(int year, int month)const;
	//构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	//析构函数
	~Date();
	//拷贝构造Date d2(d1);
	Date(const Date& d);
	//赋值运算符重载
	Date& operator=(const Date& d);
	//比较日期
	bool operator==(const Date&d)const;
	bool operator!=(const Date&d)const;
	bool operator>(const Date&d)const;
	bool operator<(const Date&d)const;
	bool operator>=(const Date&d)const;
	bool operator<=(const Date&d)const;
	//关于日期的加减
	Date operator+(int day)const;//日期加天数，原日期不变，因此要构造临时对象，要传值返回
	Date& operator+=(int day);//日期加上天数，把日期改变，直接传引用
	Date operator-(int day)const;//日期减天数，原日期不变
	Date& operator-=(int day);//日期减去天数，把日期改变
	int operator-(Date& d)const;//日期减日期，返回值是天数int
	//前置++(d.operator++(&d))
	Date& operator++();
	//后置++(d.operator++(&d,0))
	Date operator++(int);
	//前置--(d.operator--(&d))
	Date& operator--();
	//后置--(d.operator--(&d,0))
	Date operator--(int);
private:
	int _year;
	int _month;
	int _day;
};