//#include <iostream>
//using namespace std;
//命名空间
//namespace bit
//{
//	int printf = 10;
//}
//
//int main()
//{
//	cout << bit::printf << endl;
//	system("pause");
//	return 0;
//}

//缺省参数
//#include <iostream>
//using namespace std;
//void f(int a = 10)
//{
//	cout << a << endl;
//}
//int main()
//{
//	f();
//	f(50);
//	return 0;
//}

//auto的学习
//int main()
//{
//	int x = 10;
//	auto y = 'c';
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(y).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//输入输出
//int main()
//{
//	int a;
//	double b;
//	char c;
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	system("pause");
//	return 0;
//}

//学生类
//class student
//{
//public:
//	void StudentShow()
//	{
//		cout << _name <<" "<< _age << endl;
//	}
//public:
//	char* _name;
//	int _age;
//};
//int main()
//{
//	student s;
//	s._name = "zhangsan";
//	s._age = 18;
//	s.StudentShow();
//	system("pause");
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year,int month,int day)
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
//	Date d1;
//	d1.Init(2019, 1, 1);
//	d1.Print();
//
//	Date d2;
//	d2.Init(2019, 2, 23);
//	d2.Print();
//
//	Date* p = nullptr;
//	p->Print();
//
//	system("pause");
//	return 0;
//}

////指针空值
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);//调用f(int)
//	f(NULL);//调用f(int)
//	f((int*)NULL);//调用f(int*)
//	f(nullptr);//调用f(int*)
//	return 0;
//}


