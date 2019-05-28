#include<iostream>
using namespace std;
//void Test()
//{
//	int i = 1;
//	// 隐式类型转换
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	// 显示的强制类型转换
//	int* p = &i;
//	int address = (int)p;
//	printf("%x, %d\n", p, address);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}


//static_cast的使用

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//	return 0;
//}

//reinterpret_cast的使用

//int main()
//{
//	int i = 10;
//	int *j = &i;
//	int address =reinterpret_cast<int> (j);
//	cout << j << endl;
//	cout << address << endl;
//	system("pause");
//	return 0;
//}

//typedef void(*FUNC)();//无参无返回值（函数指针）
//int DoSomething(int i)//有参有返回值
//{
//	cout << "DoSomething" << endl;
//	return 0;
//}
//int main()
//{
//	FUNC f = reinterpret_cast<FUNC> (DoSomething);//强制类型的转换
//	f();
//	system("pause");
//	return 0;
//}

//const_cast的使用:去掉const属性
//int main()
//{
//	const int a = 2;
//	int* p = const_cast< int*>(&a);
//	*p = 3;
//	cout << a << endl;
//	system("pause");
//	return 0;
//}

//dynamic_cast的使用

class A
{
	virtual void f(){}
};
class B :public A
{};

void test(A* p)
{
	//不会进行检查
	//A* pp = (B*)p;
	//A* pp = static_cast<B*> (p);
	//cout << pp << endl;

	//会先进行检查，如果可以转就转，不可以转就返回0
	A* pp = dynamic_cast<B*> (p);
	cout << pp << endl;
}
int main()
{
	A a;
	B b;
	test(&a);//传过去的是一个父类的指针，强转成子类会出问题
	test(&b);//传过去的是一个子类的指针，强转过程不会出问题
	system("pause");
	return 0;
}