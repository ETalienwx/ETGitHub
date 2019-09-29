#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int>& l)//传过来最好用引用，因为这里是深拷贝
{
	list<int>::const_iterator cit = l.begin();//const迭代器的使用
	while (cit != l.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}

void test_list1()
{
	list<int> l1;//无参的构造函数
	list<int> l2(10, 3);//带参的构造函数：十个3
	list<int> l3(l2.begin(), l2.end());//可以传一个迭代器区间(保证数据类型兼容)
	list<int> l4(l3);//拷贝构造（用l3拷贝构造一个l4）

	//打印l4，使用迭代器
	//list<int>::iterator l4it = l4.begin();
	auto l4it = l4.begin();
	while (l4it != l4.end())
	{
		cout << *l4it << " ";
		l4it++;
	}
	cout << endl;

	//基于范围的for--->最好加上引用
	for (const auto& e : l4)//打印l4
	{
		cout << e << " ";
	}
	cout << endl;

	l3.push_back(0);
	print_list(l3);

	list<int>::reverse_iterator l3it = l3.rbegin();//倒着遍历（使用反向迭代器）
	while (l3it != l3.rend())
	{
		cout << *l3it << " ";
		++l3it;
	}
	cout << endl;
}

void test_list2()
{
	list<int> l;
	l.push_back(1);//尾插
	l.push_front(2);//头插
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	l.assign(10, 3);//用10个3把以前的值覆盖掉
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.insert(l.begin(), 0);//头插一个0
	list<int>::iterator pos = find(l.begin(), l.end(), 30);//找3这个位置
	if (pos != l.end())//保证安全。因为没有找到find会返回最后一个位置
	{
		l.insert(pos, 30);
	}
	*pos = 33;//list的插入不会导致迭代器失效（vector会失效是因为vector有可能会增容）

	//l.erase(pos);//可以删除pos，但是之后不能访问pos，因为pos失效了
	//*pos = 333;//因为删除了pos所以不能这样操作了
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	//删除该链表中所有的偶数
	list<int>::iterator eit = l.begin();
	while (eit != l.end())
	{
		if (*eit % 2 == 0)//找偶数
		{
			//是偶数就删除
			//erase删除数据之后，迭代器会失效，它返回的是下一个位置的迭代器，用eit重新接收
			eit = l.erase(eit);
		}
		else
		{
			//不是偶数就++
			eit++;
		}
	}
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list4()
{
	//实现交换
	list<int> l1(10, 3);
	list<int> l2(10, 4);

	swap(l1, l2);//效率低
	for (const auto& e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (const auto& e : l2)
	{
		cout << e << " ";
	}
	cout << endl;

	l1.swap(l2);//效率高
	for (const auto& e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (const auto& e : l2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list5()
{
	list<int> l;
	l.resize(10);//10个缺省，0
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	l.resize(20, 1);//前面10个是0，后面10个是1
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	l.resize(5);//缩容到5
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	l.push_back(2);
	l.push_back(1);
	l.push_back(3);
	l.push_back(2);
	l.push_back(3);
	l.push_back(3);
	l.push_back(1);

	l.sort();//先排序
	l.unique();//再去重（保留一个，不是全部删完）
	for (const auto& e : l)
	{
		cout << e << " ";
	}
}
void test_list6()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	list<int> ll;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);

	list<int>::iterator pos = find(l.begin(), l.end(), 3);
	l.splice(pos, ll);

	for (auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	l.reverse();
	for (auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//test_list1(); 
	//test_list2(); 
	//test_list3();
	//test_list4();
	//test_list5();
	test_list6();

	system("pause");
	return 0;
}