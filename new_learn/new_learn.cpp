#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>

////求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、
////switch、case等关键字及条件判断语句（A?B:C）。
//class Solution {
//public:
//	class Sum
//	{
//	public:
//		Sum()//构造函数
//		{
//			_sum += _i;
//			_i++;
//		}
//	};
//	int Sum_Solution() {
//		_sum = 0;//进行重置
//		_i = 1;
//		Sum arr[5];
//		return _sum;
//	}
//private:
//	static int _sum;
//	static int _i;
//};
//int Solution::_sum = 0;
//int Solution::_i = 1;
//int main()
//{
//	Solution s;
//	std::cout << s.Sum_Solution() << std::endl;
//	system("pause");
//	return 0;
//}

////输入某年某月某日，判断这一天是这一年的第几天？
//#include <iostream>
//int main()
//{
//	int year, month, day;
//	while (std::cin >> year >> month >> day)
//	{
//		int array[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//		int sum = 0;
//		sum = array[month - 1] + day;
//		if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			sum++;
//		}
//		std::cout << sum << std::endl;
//	}
//	system("pause");
//	return 0;
//}


////malloc/calloc/realloc和free**************************************************
//void Test()
//{
//	//开辟一个整形的大小
//	int* p1 = (int *)malloc(sizeof(int));
//	free(p1);//释放p1
//	//开辟一个整形的大小并初始化为4
//	int* p2 = (int *)calloc(4, sizeof(int));
//	//对p2进行扩容操作
//	int* p3 = (int *)realloc(p2, sizeof(int)* 10);
//	free(p3);//释放p3
//}
//int main()
//{
//	return 0;
//}


////new和delete*********************************************************************
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		std::cout << "Date(int year = 1900, int month = 1, int day = 1)" << std::endl;
	}
	~Date()
	{
		std::cout << "~Date()" << std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//int main()
//{
//	//内置类型:除了用法不同之外基本无差异
//	int* d1 = new int;
//	int* d2 = (int*)malloc(sizeof(int));
//	delete d1;
//	free(d2);
//
//	//自定义类型
//	Date* d3 = new Date;//开空间+初始化（会调用构造函数）
//	Date* d4 = new Date(2019, 1, 1);//开空间+初始化（会调用构造函数）
//	Date* d5 = (Date*)malloc(sizeof(Date));//只开空间
//	delete d3;//清理+释放空间
//	delete d4;//清理+释放空间
//	free(d5);//只释放空间
//
//	Date* d6=new Date[10];//开辟多个空间
//	delete[] d6;//释放要带[]
//	system("pause");
//	return 0;
//}

////operator new和operator delete**********************************************
//int main()
//{
//	int* p1 = (int*)operator new(sizeof(int));
//	operator delete(p1);
//
//	int* p2 = (int*)malloc(sizeof(int));
//	free(p2);
//
//	return 0;
//}



int main()
{
	Date* p = (Date*)malloc(sizeof(Date));
	new(p)Date(2018, 2, 2);//定位new表达式
	system("pause");
	return 0;
}

