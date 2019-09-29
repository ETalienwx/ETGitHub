#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int>& l)//��������������ã���Ϊ���������
{
	list<int>::const_iterator cit = l.begin();//const��������ʹ��
	while (cit != l.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}

void test_list1()
{
	list<int> l1;//�޲εĹ��캯��
	list<int> l2(10, 3);//���εĹ��캯����ʮ��3
	list<int> l3(l2.begin(), l2.end());//���Դ�һ������������(��֤�������ͼ���)
	list<int> l4(l3);//�������죨��l3��������һ��l4��

	//��ӡl4��ʹ�õ�����
	//list<int>::iterator l4it = l4.begin();
	auto l4it = l4.begin();
	while (l4it != l4.end())
	{
		cout << *l4it << " ";
		l4it++;
	}
	cout << endl;

	//���ڷ�Χ��for--->��ü�������
	for (const auto& e : l4)//��ӡl4
	{
		cout << e << " ";
	}
	cout << endl;

	l3.push_back(0);
	print_list(l3);

	list<int>::reverse_iterator l3it = l3.rbegin();//���ű�����ʹ�÷����������
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
	l.push_back(1);//β��
	l.push_front(2);//ͷ��
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	l.assign(10, 3);//��10��3����ǰ��ֵ���ǵ�
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

	l.insert(l.begin(), 0);//ͷ��һ��0
	list<int>::iterator pos = find(l.begin(), l.end(), 30);//��3���λ��
	if (pos != l.end())//��֤��ȫ����Ϊû���ҵ�find�᷵�����һ��λ��
	{
		l.insert(pos, 30);
	}
	*pos = 33;//list�Ĳ��벻�ᵼ�µ�����ʧЧ��vector��ʧЧ����Ϊvector�п��ܻ����ݣ�

	//l.erase(pos);//����ɾ��pos������֮���ܷ���pos����ΪposʧЧ��
	//*pos = 333;//��Ϊɾ����pos���Բ�������������
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	//ɾ�������������е�ż��
	list<int>::iterator eit = l.begin();
	while (eit != l.end())
	{
		if (*eit % 2 == 0)//��ż��
		{
			//��ż����ɾ��
			//eraseɾ������֮�󣬵�������ʧЧ�������ص�����һ��λ�õĵ���������eit���½���
			eit = l.erase(eit);
		}
		else
		{
			//����ż����++
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
	//ʵ�ֽ���
	list<int> l1(10, 3);
	list<int> l2(10, 4);

	swap(l1, l2);//Ч�ʵ�
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

	l1.swap(l2);//Ч�ʸ�
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
	l.resize(10);//10��ȱʡ��0
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	l.resize(20, 1);//ǰ��10����0������10����1
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	l.resize(5);//���ݵ�5
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

	l.sort();//������
	l.unique();//��ȥ�أ�����һ��������ȫ��ɾ�꣩
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