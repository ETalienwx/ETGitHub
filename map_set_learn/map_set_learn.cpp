#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

void test_set()
{
	//�ײ����������
	//1.key.�鿴�ؼ����ڲ���
	//2.����+ȥ��(�����ʱ��������ֵ�ھͲ�������)
	//�����޸�
	set<int> s;
	s.insert(2);
	s.insert(1);
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(5);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		sit++;
	}
	cout << endl;

	set<int>::iterator pos = s.find(3);//ʱ�临�Ӷȣ�O(logN)----�ײ���������
	//set<int>::iterator pos = find(s.begin(), s.end(), 3);//ʱ�临�Ӷȣ�O(N)----��Ҫ����һ��
	if (pos != s.end())
	{
		cout << "�ҵ���" << endl;
	}

	//s.erase(3);
	s.erase(pos);//�ҵ����Ҿ�ɾ��û�ҵ�Ҫɾ�Ļ��ᱨ��
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> ss;
	ss.insert(6);
	ss.insert(9);
	ss.insert(8);
	ss.insert(7);
	ss.insert(10);

	ss.swap(s);//�������ڵ��ָ�룬Ч�ʸ�
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.clear();//�����������
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_multiset()
{
	//�ײ����������
	//1.key.�鿴�ؼ����ڲ���
	//2.����
	//�����޸�
	multiset<int> ms;
	ms.insert(2);
	ms.insert(1);
	ms.insert(4);
	ms.insert(5);
	ms.insert(3);
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);
	
	auto pos = ms.find(5);
	if (pos != ms.end())
	{
		cout << "�ҵ���" << endl;//�ҵ���������ĵ�һ��5
		while (*pos == 5)//��������ҿ����ҵ��������е�5
		{
			cout << *pos << endl;
			++pos;
			if (pos == ms.end())//posָ�����һ������һ��
				break;
		}
	}

	--pos;//������һ��5
	ms.erase(pos);

	for (auto e : ms)//�����ظ�������ͬkeyֵ
	{
		cout << e << " ";
	}
	cout << endl;
}

//template<class K,class V>
//struct pair
//{
//	K first;
//	V second;
//
//	//���캯��
//};

//template<class K,class V>
//inline pair<K, V> make_pair(const K &k, const V &v)
//{
//	return pair<K, V>(k, v);
//}

void test_map()
{
	//1.key/value ͨ���ؼ��ֲ���ӳ�������Ϣvalue
	//����

	//key_type��keyֵ
	//mapped_type��valueֵ
	//value_type��pair

	map<string, string> dict;
	dict.insert(pair<string, string>("string", "�ַ���"));//ģ������pair��������һ������������뵽map
	dict.insert(make_pair("apple", "ƻ��"));//ģ�庯��make_pair��͵���ˣ�ʵ�ʵ�����pair
	dict.insert({ "left", "���" });
	dict.insert({ "left", "ʣ��" });//���벻��ȥ�ˣ���Ϊkeyֵ�Ѿ�����
	dict["pair"];//����һ��pair��key��valueΪ���ַ���(\0)
	dict["key"] = "�ؼ���";
	dict["left"] = "ʣ��";

	for (const auto &e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	map<string, string>::iterator mit = dict.begin();
	while (mit != dict.end())
	{
		cout << mit->first << ":" << mit->second << endl;
		cout << (*mit).first << ":" << (*mit).second << endl;
		mit++;
	}
}
void test_multimap()
{
	//����key����
	//û��operator[]
	multimap<string, string> mmp;
	mmp.insert(pair<string, string>("left", "���"));
	mmp.insert(make_pair("key","�ؼ���"));
	mmp.insert({ "map", "��ͼ" });
	mmp.insert({ "key", "ʣ��" });

	for (const auto &e : mmp)
	{
		cout << e.first << ":" << e.second << endl;
	}

}
void count_number()
{
	////����һ������second++��û���ҾͲ���
	//string str[] = { "ƻ��", "ƻ��", "��", "ƻ��", "�㽶", "��", "�㽶", "�㽶", "ƻ��", "����" };
	//map<string, int> count_map;
	//for (const auto &s : str)
	//{
	//	auto tmp = count_map.find(s);
	//	if (tmp != count_map.end())
	//	{
	//		tmp->second++;
	//	}
	//	else
	//	{
	//		count_map.insert({ s, 1 });//���ص���pair<map<string,int>::iterator ,bool>
	//	}
	//}
	//for (const auto &e : count_map)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}

	////��������
	//string str[] = { "ƻ��", "ƻ��", "��", "ƻ��", "�㽶", "��", "�㽶", "�㽶", "ƻ��", "����" };
	//map<string, int> count_map;
	//for (const auto &s : str)
	//{
	//	pair<map<string,int>::iterator ,bool> ret = count_map.insert(pair<string, int>(s, 1));
	//	if (!ret.second)
	//	{
	//		(ret.first)->second++;
	//	}
	//}
	//for (const auto &e : count_map)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}

	//��������
	string str[] = { "ƻ��", "ƻ��", "��", "ƻ��", "�㽶", "��", "�㽶", "�㽶", "ƻ��", "����" };
	map<string, int> count_map;
	for (auto s : str)
	{
		count_map[s]++;
	}
	for (const auto &e : count_map)
	{
		cout << e.first << ":" << e.second << endl;
	}

	cout << count_map["ƻ��"] << endl;//����keyΪ��ƻ������value�����ã����4
}
int main()
{
	//test_set();
	//test_multiset();
	//test_map();
	test_multimap();
	//count_number();
	system("pause");
	return 0;
}