#include "simulate_list.h"

void test_list1()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	//普通迭代器
	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void PrintList(const List<int>& list)
{
	//const迭代器
	List<int>::const_iterator it = list.begin();
	while (it != list.end())
	{
		//*it = 10;//不可以修改
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void test_list2()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	PrintList(l);//调用const迭代器
}
void test_list3()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	l.PushFront(0);
	l.PushFront(-1);
	l.PushFront(-2);
	l.PushFront(-3);

	l.PopFront();
	l.PopBack();

	PrintList(l);
}
void test_list4()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	List<int> ll(l);//用l拷贝构造ll

	PrintList(ll);

	List<int> lt;
	lt.PushBack(10);
	lt.PushBack(20);
	lt.PushBack(30);
	lt.PushBack(40);

	ll = lt;//用lt给ll赋值

	PrintList(ll);

	cout << ll.Size() << endl;

}
void test_list5()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	//删除所有偶数
	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			//Erase返回的是下一个位置的迭代器，再重新赋值给it，让它继续往后走
			it = l.Erase(it);
		}
		else
		{
			it++;
		}
	}
	PrintList(l);
}
int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	test_list5();
	system("pause");
	return 0;
}