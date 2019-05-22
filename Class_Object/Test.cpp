#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

////初始化列表*****************************************************************
////引用类型成员变量、const修饰的成员变量、类类型成员变量 必须在初始化列表初始化
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


////自定义类型成员变量，一定会先使用初始化列表初始化
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


////成员变量在类中声明次序就是其在初始化列表中的初始化顺序
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

////explicit关键字*******************************************************
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
//	Date y1(2018);//构造
//	Date y2 = y1;//拷贝构造
//	Date y3 = 2019;//---->报错，explicit防止单参数的隐式类型转换
//	//1.构造一个临时对象 2.把临时对象拷贝构造给y3  3.优化 <--->构造
//	system("pause");
//	return 0;
//}


////实现一个类，计算中程序中创建出了多少个类对象**********************************
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
//	设为静态的是因为如果没有产生对象也可以调用（没有this指针）
//	static int Getn()//通过函数接口获取n的值
//	{
//		return n;
//	}
//private:
//	static int n;//n的声明（n属于整个类，也属于这个类的每个对象）
//};
//
//int A::n = 0;//n的定义初始化（静态成员变量在类外定义初始化）
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


////C++11成员初始化的新用法******************************************************
//class B
//{
//public:
//	B(int b = 0)//单参数的构造函数
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
//	//非静态的成员变量可以在声明的时候直接初始化
//	//以下是成员变量的声明，并不是定义（后面的值相当于缺省值）
//	int a = 10;
//	B b = 20;//发生了隐式类型的转换
//	int* arr = (int *)malloc(4);
//	static int n;
//};
//int A::n = 30;//静态成员变量在类外进行初始化
//int main()
//{
//	A a;
//	a.Print();
//	system("pause");
//	return 0;
//}


//构造赋值，隐式类型的转换*******************************************************
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
//	Date d1(2019);//构造
//	Date d2 = 2020;//构造临时对象、临时对象拷贝构造d2、优化==构造
//	d1 = 2030;//构造临时对象、临时对象赋值给d1
//	system("pause");
//	return 0;
//}


////友元函数********************************************************************
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

////友元类************************************************************************
////我要访问你，就把我定义为你的友元
//class Date; //前置声明
//class Time
//{
//	friend class Date;
//	//声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
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
//		// 直接访问时间类私有的成员变量
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

////内部类
//class A
//{
//private:
//	static int k1;//声明
//	int h=10;
//public://B类的访问限定符是公有的，可以先找到A再找到B
//	class B//B类默认是A类的友元类，因此B类可以访问A类的成员变量
//	{
//	public:
//		static int k2;//声明
//		int y;
//		void f(const A& a)
//		{
//			std::cout << k1 << std::endl;//k1是静态成员变量，因此可以直接访问
//			std::cout << a.h << std::endl;//h属于某一个对象，因此需要用对象来访问
//		}
//	};
//};
//int A::k1 = 10;//A类的静态成员变量的初始化
//int A::B::k2 = 2;//通过A类找到B类，在类外进行初始化
//int main()
//{
//	A::B b;//定义一个B类的b
//	b.f(A());
//	std::cout << sizeof(A) << std::endl;
//	std::cout << sizeof(A::B) << std::endl;
//	system("pause");
//	return 0;
//}

