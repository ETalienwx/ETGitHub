#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>

////��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��
////switch��case�ȹؼ��ּ������ж���䣨A?B:C����
//class Solution {
//public:
//	class Sum
//	{
//	public:
//		Sum()//���캯��
//		{
//			_sum += _i;
//			_i++;
//		}
//	};
//	int Sum_Solution() {
//		_sum = 0;//��������
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

////����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
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


////malloc/calloc/realloc��free**************************************************
//void Test()
//{
//	//����һ�����εĴ�С
//	int* p1 = (int *)malloc(sizeof(int));
//	free(p1);//�ͷ�p1
//	//����һ�����εĴ�С����ʼ��Ϊ4
//	int* p2 = (int *)calloc(4, sizeof(int));
//	//��p2�������ݲ���
//	int* p3 = (int *)realloc(p2, sizeof(int)* 10);
//	free(p3);//�ͷ�p3
//}
//int main()
//{
//	return 0;
//}


////new��delete*********************************************************************
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
//	//��������:�����÷���֮ͬ������޲���
//	int* d1 = new int;
//	int* d2 = (int*)malloc(sizeof(int));
//	delete d1;
//	free(d2);
//
//	//�Զ�������
//	Date* d3 = new Date;//���ռ�+��ʼ��������ù��캯����
//	Date* d4 = new Date(2019, 1, 1);//���ռ�+��ʼ��������ù��캯����
//	Date* d5 = (Date*)malloc(sizeof(Date));//ֻ���ռ�
//	delete d3;//����+�ͷſռ�
//	delete d4;//����+�ͷſռ�
//	free(d5);//ֻ�ͷſռ�
//
//	Date* d6=new Date[10];//���ٶ���ռ�
//	delete[] d6;//�ͷ�Ҫ��[]
//	system("pause");
//	return 0;
//}

////operator new��operator delete**********************************************
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
	new(p)Date(2018, 2, 2);//��λnew���ʽ
	system("pause");
	return 0;
}

