#include <iostream>
#include <string>
using namespace std;

///////////////////////////////�̳еĶ���///////////////////////////////
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


//////////////////////////////////////�����޶���//////////////////////////////////
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name="jack"; // ����
//private:
//	int _age=18; // ����
//};
//class Student : protected Person
//{
//public:
//	void Fun()
//	{
//		cout << _name << endl;
//	}
//protected:
//	int _stunum; // ѧ��
//};
//int main()
//{
//	Student s;
//	s.Fun();
//	system("pause");
//	return 0;
//}


//////////////////////////////////////////////��ֵ//////////////////////////////////
//class Person
//{
//public:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	//����ĸ�ֵ
//	//Person p;
//	//Student s;
//
//	//s._name = "С��֦";
//	//s._age = 18;
//	//s._sex = "Ů";
//	//s._No = 123456;
//
//	//p = s;
//
//	//ָ��ĸ�ֵ
//	//Person p;
//	//Student s;
//
//	//s._name = "С��֦";
//	//s._age = 18;
//	//s._sex = "Ů";
//	//s._No = 123456;
//
//	//Person* ptrp = &s;
//	//ptrp->_age = 20;
//	////Student* ptrp = &p;//����
//
//	//���õĸ�ֵ
//	//Person p;
//	//Student s;
//
//	//s._name = "С��֦";
//	//s._age = 18;
//	//s._sex = "Ů";
//	//s._No = 123456;
//
//	//Person& rp = s;
//	//rp._age = 20;
//	////Student& rp = p;//����
//
//
//	Person p;
//	Student s;
//
//	s._name = "С��֦";
//	s._age = 18;
//	s._sex = "Ů";
//	s._No = 123456;
//
//	Person* ptrp = &p;
//	Student* ptrs = (Student*)ptrp;
//	//ptrs->_No = 10;//����
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


////////////////////////////////////////////������//////////////////////////////////
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;//���111
//		cout << " ѧ��:" << _num << endl;//���999
//	}
//protected:
//	int _num = 999; // ѧ��
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
//	//b.fun();//�಻������ʾ���õĲ�������
//	b.A::fun();
//};
//
//int main()
//{
//	Test2();
//	system("pause");
//	return 0;
//}

/////////////////////////////////////////�������Ĭ�ϳ�Ա����/////////////////////////
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
//	string _name; // ����
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
//		:Person(s)//��Ƭ
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
//			Person::operator=(s);//�������operator=��ɸ�����һ���ֵĿ���
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
//	int _num; //ѧ��
//};
//int main()
//{
//	Student s1("С����", 18);
//	Student s2("С����", 19);
//	Student s3(s2);
//	s2 = s1;
//	//system("pause");
//	return 0;
//}

////////////////////////////////////���ܱ��̳е���//////////////////////////////////////
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

///////////////////////////////////�̳к���Ԫ////////////////////////////////////////////////
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s._stuNum << endl;//���ܷ���
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

////////////////////////////////////////////��̬��Ա//////////////////////////////////////
//class Person
//{
//public:
//	Person() 
//	{
//		++_count;
//	}
//protected:
//	string _name;//����
//public:
//	static int _count;//ͳ���˵ĸ���
//};
//
//int Person::_count = 0;//��̬��Ա�������ʼ��
//
//class Student : public Person
//{
//protected:
//	int _stuNum;//ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse;//�о���Ŀ
//};
//
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << "����:" << Person::_count << endl;
//	Student::_count = 0;
//	cout << "����:" << Person::_count << endl;
//}
//int main()
//{
//	TestPerson();
//	system("pause");
//	return 0;
//}

///////////////////////////////////////��̳�///////////////////////////////////////////////
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	//a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
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
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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


//////////////////////////////////////������/////////////////////////////////////////
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