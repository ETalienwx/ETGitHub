#include<iostream>
using namespace std;
//void Test()
//{
//	int i = 1;
//	// ��ʽ����ת��
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	// ��ʾ��ǿ������ת��
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


//static_cast��ʹ��

//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//	return 0;
//}

//reinterpret_cast��ʹ��

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

//typedef void(*FUNC)();//�޲��޷���ֵ������ָ�룩
//int DoSomething(int i)//�в��з���ֵ
//{
//	cout << "DoSomething" << endl;
//	return 0;
//}
//int main()
//{
//	FUNC f = reinterpret_cast<FUNC> (DoSomething);//ǿ�����͵�ת��
//	f();
//	system("pause");
//	return 0;
//}

//const_cast��ʹ��:ȥ��const����
//int main()
//{
//	const int a = 2;
//	int* p = const_cast< int*>(&a);
//	*p = 3;
//	cout << a << endl;
//	system("pause");
//	return 0;
//}

//dynamic_cast��ʹ��

class A
{
	virtual void f(){}
};
class B :public A
{};

void test(A* p)
{
	//������м��
	//A* pp = (B*)p;
	//A* pp = static_cast<B*> (p);
	//cout << pp << endl;

	//���Ƚ��м�飬�������ת��ת��������ת�ͷ���0
	A* pp = dynamic_cast<B*> (p);
	cout << pp << endl;
}
int main()
{
	A a;
	B b;
	test(&a);//����ȥ����һ�������ָ�룬ǿת������������
	test(&b);//����ȥ����һ�������ָ�룬ǿת���̲��������
	system("pause");
	return 0;
}