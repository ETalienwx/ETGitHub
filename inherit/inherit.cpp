#include <iostream>
#include <string>
using namespace std;

///////////////////////////////继承的定义///////////////////////////////
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//private:
//	string _name = "jack";
//	int _age = 18;
//};
//class Student:public Person
//{
//private:
//	int _snum;
//};


//////////////////////////////////////访问限定符//////////////////////////////////
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name="jack"; // 姓名
//private:
//	int _age=18; // 年龄
//};
//class Student : protected Person
//{
//public:
//	void Fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	int _stunum; // 学号
//};
//int main()
//{
//	Student s;
//	s.Fun();
//	system("pause");
//	return 0;
//}


//////////////////////////////////////////////赋值//////////////////////////////////
//class Person
//{
//public:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	//对象的赋值
//	//Person p;
//	//Student s;
//
//	//s._name = "小荔枝";
//	//s._age = 18;
//	//s._sex = "女";
//	//s._No = 123456;
//
//	//p = s;
//
//	//指针的赋值
//	//Person p;
//	//Student s;
//
//	//s._name = "小荔枝";
//	//s._age = 18;
//	//s._sex = "女";
//	//s._No = 123456;
//
//	//Person* ptrp = &s;
//	//ptrp->_age = 20;
//	////Student* ptrp = &p;//报错
//
//	//引用的赋值
//	//Person p;
//	//Student s;
//
//	//s._name = "小荔枝";
//	//s._age = 18;
//	//s._sex = "女";
//	//s._No = 123456;
//
//	//Person& rp = s;
//	//rp._age = 20;
//	////Student& rp = p;//报错
//
//
//	Person p;
//	Student s;
//
//	s._name = "小荔枝";
//	s._age = 18;
//	s._sex = "女";
//	s._No = 123456;
//
//	Person* ptrp = &p;
//	Student* ptrs = (Student*)ptrp;
//	//ptrs->_No = 10;//报错
//
//	Person* ptrp = &s;
//	Student* ptrs = (Student*)ptrp;
//	ptrs->_No = 10;
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}


////////////////////////////////////////////作用域//////////////////////////////////
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;//输出111
//		cout << " 学号:" << _num << endl;//输出999
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test1()
//{
//	Student s1;
//	s1.Print();
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test2()
//{
//	B b;
//	b.fun(10);
//	//b.fun();//编不过，提示调用的参数过少
//	b.A::fun();
//};
//
//int main()
//{
//	Test2();
//	system("pause");
//	return 0;
//}

/////////////////////////////////////////派生类的默认成员函数/////////////////////////
//#include <string>
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//class Student:public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)//切片
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);//调父类的operator=完成父类那一部分的拷贝
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num; //学号
//};
//int main()
//{
//	Student s1("小栗子", 18);
//	Student s2("小王子", 19);
//	Student s3(s2);
//	s2 = s1;
//	//system("pause");
//	return 0;
//}

////////////////////////////////////不能被继承的类//////////////////////////////////////
////C++98
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
////C++11
//class NonInherit final
//{};

///////////////////////////////////继承和友元////////////////////////////////////////////////
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s._stuNum << endl;//不能访问
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

////////////////////////////////////////////静态成员//////////////////////////////////////
//class Person
//{
//public:
//	Person() 
//	{
//		++_count;
//	}
//protected:
//	string _name;//姓名
//public:
//	static int _count;//统计人的个数
//};
//
//int Person::_count = 0;//静态成员在类外初始化
//
//class Student : public Person
//{
//protected:
//	int _stuNum;//学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse;//研究科目
//};
//
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << "人数:" << Person::_count << endl;
//	Student::_count = 0;
//	cout << "人数:" << Person::_count << endl;
//}
//int main()
//{
//	TestPerson();
//	system("pause");
//	return 0;
//}

///////////////////////////////////////多继承///////////////////////////////////////////////
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//int main()
//{
//	Test();
//	return 0;
//}



//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//}


//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}


//////////////////////////////////////笔试题/////////////////////////////////////////
class Base1 {
public:
	int _b1;
};
class Base2 {
public:
	int _b2;
};
class Derive : public Base1, public Base2 {
public:
	int _d;
};
int main()
{
	// A. p1 == p2 == p3
	// B. p1 < p2 < p3
	// C. p1 == p3 != p2
	// D. p1 != p2 != p3
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;
	return 0;
}