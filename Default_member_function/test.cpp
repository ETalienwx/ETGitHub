#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//Ĭ�Ϲ��캯��--��ʼ��
//class Date
//{
//public:
//	//Date()
//	//{
//	//	_year = 2019;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	Date(int year = 2019, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		std::cout << _year << "-" << _month << "-" << _day << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;//�޲εĹ��캯�����ܴ�()
//	d1.Print();
//	Date d2(2019, 2, 2);
//	d2.Print();
//	system("pause");
//	return 0;
//}

//class Time
//{ 
//public:
//	Time()
//	{
//		std::cout << "Time()" << std::endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	//��������
//	int _year;
//	int _month;
//	int _day;
//	//�Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	system("pause");
//	return 0;
//}

//��������
//class Seqlist
//{
//public:
//	Seqlist(size_t capacity = 10)
//	{
//		_array = (int *)malloc(capacity * sizeof(capacity));
//		size_t _size = 0;
//		size_t _capacity = capacity;
//	}
//	~Seqlist()
//	{
//		free(_array);
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Seqlist s;
//	system("pause");
//	return 0;
//}

//#include <string.h>
//#include <stdlib.h>
//class String
//{
//public:
//	String(const char* str="jack")
//	{
//		std::cout << "String()" << std::endl;
//		_str = (char*)malloc(strlen(str)+1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		std::cout << "~String()" << std::endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}


//�������캯��
//class Date
//{
//public:
//	Date(int year = 2019, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date d2(d1)
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		std::cout << _year << "-" << _month << "-" << _day << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	Date d2(d1);
//	d2.Print();
//	system("pause");
//	return 0;
//}

//��ǳ����
//�ᱨ��ͬһ��ռ��ͷ�������
//class String
//{
//public:
//	String(char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		free(_str);
//		_str = nullptr;
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1;
//	String s2(s1);
//	return 0;
//}

//����������������
//class Date
//{
//public:
//	Date(int year = 2019, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator==(const Date& d1, const Date& d2)
//{
//	return (d1._year == d2._year)
//		&& (d1._month == d2._month)
//		&& (d1._day == d2._day);
//}
//bool operator<(const Date& d1, const Date& d2)
//{
//	return (d1._year < d2._year)
//		|| (d1._year == d2._year && d1._month < d2._month)
//		|| (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day);
//}
//bool operator>(const Date& d1, const Date& d2)
//{
//	return (d1._year > d2._year)
//		|| (d1._year == d2._year && d1._month > d2._month)
//		|| (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day);
//}
//int main()
//{
//	Date d1;
//	Date d2(2019, 2, 2);
//	//ԭʼд��
//	std::cout << operator==(d1, d2) << std::endl;
//	std::cout << operator<(d1, d2) << std::endl;
//	std::cout << operator>(d1, d2) << std::endl;
//	//����д��
//	std::cout << (d1 == d2) << std::endl;
//	std::cout << (d1 < d2) << std::endl;
//	std::cout << (d1 > d2) << std::endl;
//	system("pause");
//	return 0;
//}


//����������������
//class Date
//{
//public:
//	Date(int year = 2019, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//d1==d2
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	//d1<d2
//	bool operator<(const Date& d)
//	{
//		return (_year < d._year)
//			|| (_year == d._year && _month < d._month)
//			|| (_year == d._year && _month == d._month && _day < d._day);
//	}
//	//d1>d2
//	bool operator>(const Date& d)
//	{
//		return (_year > d._year)
//			|| (_year == d._year && _month > d._month)
//			|| (_year == d._year && _month == d._month && _day > d._day);
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(2019, 2, 2);
//	//ԭʼд��
//	std::cout << d1.operator==(d2) << std::endl;
//	std::cout << d1.operator<(d2) << std::endl;
//	std::cout << d1.operator>(d2) << std::endl;
//	//����д��
//	std::cout << (d1 == d2) << std::endl;
//	std::cout << (d1 < d2) << std::endl;
//	std::cout << (d1 > d2) << std::endl;
//	system("pause");
//	return 0;
//}

//��ֵ�����������
class Date
{
public:
	Date(int year = 2019, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//d1=d2
	Date& operator=(Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(2019, 2, 2);
	Date d3(2019, 3, 3);
	d1 = d2 = d3;
	system("pause");
	return 0;
}