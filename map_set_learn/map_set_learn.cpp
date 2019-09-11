#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

void test_set()
{
	//底层二叉搜索树
	//1.key.查看关键字在不在
	//2.排序+去重(插入的时候如果这个值在就不插入了)
	//不能修改
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

	set<int>::iterator pos = s.find(3);//时间复杂度：O(logN)----底层是搜索树
	//set<int>::iterator pos = find(s.begin(), s.end(), 3);//时间复杂度：O(N)----需要遍历一遍
	if (pos != s.end())
	{
		cout << "找到了" << endl;
	}

	//s.erase(3);
	s.erase(pos);//找到了我就删，没找到要删的话会报错
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

	ss.swap(s);//交换根节点的指针，效率高
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.clear();//清掉所有数据
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_multiset()
{
	//底层二叉搜索树
	//1.key.查看关键字在不在
	//2.排序
	//不能修改
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
		cout << "找到了" << endl;//找到的是中序的第一个5
		while (*pos == 5)//往后继续找可以找到后面所有的5
		{
			cout << *pos << endl;
			++pos;
			if (pos == ms.end())//pos指向最后一个的下一个
				break;
		}
	}

	--pos;//倒数第一个5
	ms.erase(pos);

	for (auto e : ms)//可以重复插入相同key值
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
//	//构造函数
//};

//template<class K,class V>
//inline pair<K, V> make_pair(const K &k, const V &v)
//{
//	return pair<K, V>(k, v);
//}

void test_map()
{
	//1.key/value 通过关键字查找映射关联信息value
	//排序

	//key_type：key值
	//mapped_type：value值
	//value_type：pair

	map<string, string> dict;
	dict.insert(pair<string, string>("string", "字符串"));//模板类型pair：构造了一个匿名对象插入到map
	dict.insert(make_pair("apple", "苹果"));//模板函数make_pair：偷懒了，实际调的是pair
	dict.insert({ "left", "左边" });
	dict.insert({ "left", "剩余" });//插入不进去了，因为key值已经有了
	dict["pair"];//插入一个pair的key，value为空字符串(\0)
	dict["key"] = "关键字";
	dict["left"] = "剩余";

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
	//允许key冗余
	//没有operator[]
	multimap<string, string> mmp;
	mmp.insert(pair<string, string>("left", "左边"));
	mmp.insert(make_pair("key","关键字"));
	mmp.insert({ "map", "地图" });
	mmp.insert({ "key", "剩余" });

	for (const auto &e : mmp)
	{
		cout << e.first << ":" << e.second << endl;
	}

}
void count_number()
{
	////方法一：有了second++，没有我就插入
	//string str[] = { "苹果", "苹果", "梨", "苹果", "香蕉", "梨", "香蕉", "香蕉", "苹果", "西瓜" };
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
	//		count_map.insert({ s, 1 });//返回的是pair<map<string,int>::iterator ,bool>
	//	}
	//}
	//for (const auto &e : count_map)
	//{
	//	cout << e.first << ":" << e.second << endl;
	//}

	////方法二：
	//string str[] = { "苹果", "苹果", "梨", "苹果", "香蕉", "梨", "香蕉", "香蕉", "苹果", "西瓜" };
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

	//方法三：
	string str[] = { "苹果", "苹果", "梨", "苹果", "香蕉", "梨", "香蕉", "香蕉", "苹果", "西瓜" };
	map<string, int> count_map;
	for (auto s : str)
	{
		count_map[s]++;
	}
	for (const auto &e : count_map)
	{
		cout << e.first << ":" << e.second << endl;
	}

	cout << count_map["苹果"] << endl;//返回key为“苹果”的value的引用，输出4
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