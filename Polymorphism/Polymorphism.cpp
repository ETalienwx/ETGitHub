#include <iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "������Ʊ��ȫ��" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "ѧ����Ʊ�����" << endl;
//	}
//};
//void Buy(Person* p)
//{
//	p->BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	Buy(&p);
//	Buy(&s);
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "������Ʊ��ȫ��" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "ѧ����Ʊ�����" << endl;
//	}
//};
//void Buy(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	Buy(p);
//	Buy(s);
//	system("pause");
//	return 0;
//}

///////////////////////////////////////Э��/////////////////////////////////////
//class A{};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};


/////////////////////////////////���������Ϊʲô����Ϊ�麯��//////////////////////////
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//int main()
//{
//	Person* p = new Student;
//	delete p;
//
//	system("pause");
//	return 0;
//}


//////////////////////////////////////���麯��///////////////////////////////////////////
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};


//////////////////////////////////override��final///////////////////////////////////////////
//class Car{
//public:
//	virtual void Drive(){}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override //ǿ�������д
//	{ 
//		cout << "Benz-����" << endl; 
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	//virtual void Drive() //������ʾ�޷������д
//	//{ 
//	//	cout << "Benz-����" << endl; 
//	//}
//};


/////////////////////////////////////�麯��ԭ��////////////////////////////////////////////
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	system("pause");
//	return 0;
//}



//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	Derive d;
//	cout << sizeof(Derive) << endl;
//	system("pause");
//	return 0;
//}



//��֤���������
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//int main()
//{
//	Base base;
//	int a;//ջ
//	int* b = new int;//��
//	static int c;//��̬��
//	char* d = "abcd";//�����
//
//	cout << &a << endl;
//	cout << b << endl;
//	cout << &c << endl;
//	cout << (void*)d << endl;
//
//	cout << (void*)(*(int*)&base) << endl;
//	system("pause");
//	return 0;
//}



//////////////////////////////////////�ض���/////////////////////////////////////////
//class A
//{
//public:
//	A(){}
//	void show()
//	{
//		cout << "A::show()" << endl;
//	}
//};
//class B:public A
//{
//public:
//	B(){}
//	void show()
//	{
//		cout << "B::show()" << endl;
//	}
//};
//int main()
//{
//	A* a = new A;
//	B* b = new B;
//	A* c = new B;
//
//	a->show();
//	b->show();
//	c->show();
//
//	system("pause");
//	return 0;
//}


////////////////////////////////////////////��д////////////////////////////////////
//class A
//{
//public:
//	A(){}
//	virtual void show(){ cout << "A::show()" << endl; }
//	//virtual void print(){ cout << "A::print()" << endl; }
//	virtual void fun(){ cout << "A::fun()" << endl; }
//};
//class B :public A
//{
//public:
//	B(){}
//	virtual void show(){ cout << "B::show()" << endl; }
//	//virtual int print(){ cout << "B::print()" << endl; }
//	virtual void fun(int i){ cout << "B::fun()" << endl; }
//};
//int main()
//{
//	A* a = new B;
//	a->show();
//	a->fun();
//	B* b = new B;
//	b->fun(1);
//
//	system("pause");
//	return 0;
//}


/////////////////////////////////////////����////////////////////////////////////////
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//	system("pause");
//	return 0;
//}


/////////////////////////////////////���̳е��麯����////////////////////////////////////////
//class Base 
//{
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base 
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//typedef void(*VFUNC)();//����һ������ָ��VFUNC
//
//void PrintVTable(VFUNC* table)
//{
//	cout << "���" << table << endl;
//	for (int i = 0; table[i] != nullptr; ++i)//�������һ��Ԫ����nullptr
//	{
//		printf("�麯��%d : [0x%p]->", i, table[i]);
//		VFUNC f = table[i];
//		f();
//	}
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//	//PrintVTable((VFUNC*)(*(int*)&b));
//	PrintVTable((VFUNC*)(*(int*)&d));
//	system("pause");
//	return 0;
//}


/////////////////////////////////////��̳е��麯����////////////////////////////////////
class Base1 
{
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 
{
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 
{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFUNC)();
void PrintVTable(VFUNC* table)
{
	cout << "�麯����:" << table << endl;
	for (int i = 0; table[i] != nullptr; i++)
	{
		printf("�麯��%d : [0x%p]->", i, table[i]);
		table[i]();
	}
	cout << endl;
}
int main()
{
	Base1 b1;
	Base2 b2;
	Derive d;
	PrintVTable((VFUNC*)(*(int*)&d));
	PrintVTable((VFUNC*)(*(int*)((char*)&d + sizeof(Base1))));
	system("pause");
	return 0;
}