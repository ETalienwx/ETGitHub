#include "Date.h"
//��ӡ
void Date::Print()const
{
	std::cout << _year << "-" << _month << "-" << _day << std::endl;
}

//��ȡ�µ�����
int Date::GetMonthDay(int year, int month)const
{
	static int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//������Ļ�2�·���29��
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return array[month];
}

//���캯��
Date::Date(int year, int month, int day)
{
	//�ж��������Ƿ�Ϸ�
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

//��������
Date::~Date()
{}

//��������Date d2(d1);
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//��ֵ���������
Date& Date::operator=(const Date& d)
{
	if (this != &d)//��ֹ�Լ����Լ���ֵ
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//����֧��������ֵ
}

//�ж����ڴ�С�����
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

//�������ڵļӼ�

////d1+100----d1�������ı�
////������ʵ��+
//Date Date::operator+(int day)const
//{
//	Date ret(*this);
//	ret._day += day;
//	while (ret._day > GetMonthDay(ret._year, ret._month))//���ڸ��������Ͳ��Ϸ�
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

//����+=ʵ��+
Date Date::operator+(int day)const
{
	Date ret(*this);
	ret += day;
	return ret;
}

////d1-100----d1�������ı�
////������ʵ��-
//Date Date::operator-(int day)const
//{
//	Date ret(*this);
//	ret._day -= day;
//	while (ret._day <= 0)//С�ں͵���0�����Ϸ�
//	{
//		--ret._month;//������ϸ��µ�����
//		if (ret._month == 0)
//		{
//			ret._year--;
//			ret._month = 12;
//		}
//		ret._day += GetMonthDay(ret._year, ret._month);		
//	}
//	return ret;
//}

//����-=ʵ��-
Date Date::operator-(int day)const
{
	Date ret(*this);
	ret -= day;
	return ret;
}

//ʵ��+=
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

//ʵ��-=
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
int Date::operator-(Date& d)const//���ڼ����ڣ�����ֵ������int
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

//ǰ��++(d.operator++(&d))
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//����++(d.operator++(&d,0))
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

//ǰ��--(d.operator--(&d))
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//����--(d.operator--(&d,0))
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

