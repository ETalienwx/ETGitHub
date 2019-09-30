#include "simulate_list.h"

void test_list1()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	//��ͨ������
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
	//const������
	List<int>::const_iterator it = list.begin();
	while (it != list.end())
	{
		//*it = 10;//�������޸�
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

	PrintList(l);//����const������
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

	List<int> ll(l);//��l��������ll

	PrintList(ll);

	List<int> lt;
	lt.PushBack(10);
	lt.PushBack(20);
	lt.PushBack(30);
	lt.PushBack(40);

	ll = lt;//��lt��ll��ֵ

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
	//ɾ������ż��
	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			//Erase���ص�����һ��λ�õĵ������������¸�ֵ��it����������������
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