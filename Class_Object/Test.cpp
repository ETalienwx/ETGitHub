#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

////��ʼ���б�*****************************************************************
////�������ͳ�Ա������const���εĳ�Ա�����������ͳ�Ա���� �����ڳ�ʼ���б��ʼ��
//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int ref = 0)
//		:_ref(ref)
//		, _n(10)
//		, _a(0)
//	{}
//	int& _ref;
//	const int _n;
//	A _a;
//};
//int main()
//{
//	B b1;
//	system("pause");
//	return 0;
//}


////�Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ��
//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		std::cout << "Time()" << std::endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int day)
//		:_t(10)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d(1);
//	system("pause");
//	return 0;
//}


////��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳��
//class Array
//{
//public:
//	Array(int size)
//		:_size(size)
//		, _array((int*)malloc(sizeof(int)*_size))
//	{}
//private:
//	int* _array;
//	int _size;
//};

////explicit�ؼ���*******************************************************
//class Date
//{
//public:
//	explicit Date(int year = 1900)
//	{
//		_year = year;
//		std::cout << "Date(int year = 1900)" << std::endl;
//	}
//	Date(const Date& y)
//	{
//		_year = y._year;
//		std::cout << "Date(const Date& y)" << std::endl;
//	}
//private:
//	int _year;
//};
//int main()
//{
//	Date y1(2018);//����
//	Date y2 = y1;//��������
//	Date y3 = 2019;//---->����explicit��ֹ����������ʽ����ת��
//	//1.����һ����ʱ���� 2.����ʱ���󿽱������y3  3.�Ż� <--->����
//	system("pause");
//	return 0;
//}


////ʵ��һ���࣬�����г����д������˶��ٸ������**********************************
//class A
//{
//public:
//	A()
//	{
//		++n;
//		std::cout << "A()" << std::endl;
//	}
//	A(const A& a)
//	{
//		++n;
//		std::cout << "A(const A& a)" << std::endl;
//	}
//	��Ϊ��̬������Ϊ���û�в�������Ҳ���Ե��ã�û��thisָ�룩
//	static int Getn()//ͨ�������ӿڻ�ȡn��ֵ
//	{
//		return n;
//	}
//private:
//	static int n;//n��������n���������࣬Ҳ����������ÿ������
//};
//
//int A::n = 0;//n�Ķ����ʼ������̬��Ա���������ⶨ���ʼ����
//
//A f(A a)
//{
//	return a;
//}
//int main()
//{
//	A a1;
//	A a2;
//	f(a1);
//	std::cout << A::Getn() << std::endl;
//	system("pause");
//	return 0;
//}
//


////C++11��Ա��ʼ�������÷�******************************************************
//class B
//{
//public:
//	B(int b = 0)//�������Ĺ��캯��
//	{
//		_b = b;
//	}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		std::cout << a << std::endl;
//		std::cout << b._b << std::endl;
//		std::cout << arr << std::endl;
//		std::cout << n << std::endl;
//	}
//private:
//	//�Ǿ�̬�ĳ�Ա����������������ʱ��ֱ�ӳ�ʼ��
//	//�����ǳ�Ա�����������������Ƕ��壨�����ֵ�൱��ȱʡֵ��
//	int a = 10;
//	B b = 20;//��������ʽ���͵�ת��
//	int* arr = (int *)malloc(4);
//	static int n;
//};
//int A::n = 30;//��̬��Ա������������г�ʼ��
//int main()
//{
//	A a;
//	a.Print();
//	system("pause");
//	return 0;
//}


//���츳ֵ����ʽ���͵�ת��*******************************************************
//class Date
//{
//public:
//	Date(int year = 1900)
//	{
//		std::cout << "Date(int year = 1900)" << std::endl;
//	}
//	Date(const Date& d)
//	{
//		std::cout << "Date(const Date& d)" << std::endl;
//	}
//	Date& operator=(const Date& d)
//	{
//		std::cout << "Date& operator=(const Date& d)" << std::endl;
//		return *this;
//	}
//};
//int main()
//{
//	Date d1(2019);//����
//	Date d2 = 2020;//������ʱ������ʱ���󿽱�����d2���Ż�==����
//	d1 = 2030;//������ʱ������ʱ����ֵ��d1
//	system("pause");
//	return 0;
//}


////��Ԫ����********************************************************************
//class Date
//{
//	friend std::ostream& operator<<(std::ostream& out, const Date& d);
//	friend std::istream& operator>>(std::istream& in, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//std::ostream& operator<<(std::ostream& out,const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << std::endl;
//	return out;
//}
//std::istream& operator>>(std::istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//int main()
//{
//	Date d1,d2;
//	std::cin >> d1 >> d2;
//	std::cout << d1 << d2;
//	system("pause");
//	return 0;
//}

////��Ԫ��************************************************************************
////��Ҫ�����㣬�Ͱ��Ҷ���Ϊ�����Ԫ
//class Date; //ǰ������
//class Time
//{
//	friend class Date;
//	//����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//	Time(int hour=0, int minute=0, int second=0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

////�ڲ���
//class A
//{
//private:
//	static int k1;//����
//	int h=10;
//public://B��ķ����޶����ǹ��еģ��������ҵ�A���ҵ�B
//	class B//B��Ĭ����A�����Ԫ�࣬���B����Է���A��ĳ�Ա����
//	{
//	public:
//		static int k2;//����
//		int y;
//		void f(const A& a)
//		{
//			std::cout << k1 << std::endl;//k1�Ǿ�̬��Ա��������˿���ֱ�ӷ���
//			std::cout << a.h << std::endl;//h����ĳһ�����������Ҫ�ö���������
//		}
//	};
//};
//int A::k1 = 10;//A��ľ�̬��Ա�����ĳ�ʼ��
//int A::B::k2 = 2;//ͨ��A���ҵ�B�࣬��������г�ʼ��
//int main()
//{
//	A::B b;//����һ��B���b
//	b.f(A());
//	std::cout << sizeof(A) << std::endl;
//	std::cout << sizeof(A::B) << std::endl;
//	system("pause");
//	return 0;
//}

