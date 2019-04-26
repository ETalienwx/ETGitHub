#include <string>
#include <iostream>
using namespace std;

void test_string1()
{
	string s1("hello");//构造函数
	string s2 = "world";//这里有隐式类型的转换（构造+拷贝构造+优化）

	char str1[] = "吃饭";
	cout << str1 << endl;

	char str2[5];
	str2[0] = -77;
	str2[1] = -43;
	str2[2] = -73;
	str2[3] = -70;
	str2[4] = '\0';
	cout << str2 << endl;
}
void test_string2()
{
	string s1("hello");//构造
	string s2(s1);//拷贝构造
	string s3("world");
	s1 = s3;//赋值
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	string s4(s3, 3);//从对象的第三位开始取，直到\0
	cout << s4 << endl;

	string s5("world", 3);//取该字符串的前三位
	cout << s5 << endl;

	string s6(s3, 1, 3);//从对象的第一位开始取，取三位
	cout << s6 << endl;

	string s7("world", 1, 3);//从该字符串的第一位开始取，取三位
	cout << s7 << endl;
}
//遍历字符串"1234abcd"
void Print1(string s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";//支持下标访问
		//等价于cout << s.operator[](i) << " ";
	}
	cout << endl;
}
void Print2(string s)
{
	string::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		sit++;
	}
	cout << endl;
}
void ReversePrint(string s)
{
	string::reverse_iterator sit = s.rbegin();
	while (sit != s.rend())
	{
		cout << *sit << " ";
		sit++;
	}
	cout << endl;
}
void ConstPrint(const string& s)
{
	string::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		//*sit = '1';不能修改数据
		cout << *sit << " ";
		sit++;
	}
	cout << endl;
}
void ConstReversePrint(const string& s)
{
	string::const_reverse_iterator sit = s.rbegin();
	while (sit != s.rend())
	{
		//*sit = '1';不能修改数据
		cout << *sit << " ";
		sit++;
	}
	cout << endl;
}
void Print3(string s)
{
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_string3()
{
	Print1("1234abcd");
	Print2("1234abcd");
	ReversePrint("1234abcd");
	ConstPrint("1234abcd");
	ConstReversePrint("1234abcd");
	Print3("1234abcd");
}
//根据遍历字符串实现字符转整形"123456"
int StrToInt1(string s)
{
	int value = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		value *= 10;
		value += s[i] - '0';
	}
	return value;
}
int StrToInt2(string s)
{
	int value = 0;
	string::iterator sit = s.begin();
	while (sit != s.end())
	{
		value *= 10;
		value += *sit - '0';
		sit++;
	}
	return value;
}
int StrToInt3(string s)
{
	int value = 0;
	for (auto e : s)
	{
		value *= 10;
		value += e - '0';
	}
	return value;
}
void test_string4()
{
	cout << StrToInt1("123456") << endl;
	cout << StrToInt2("123456") << endl;
	cout << StrToInt3("123456") << endl;
}
void test_string5()
{
	//size/capacity
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('w');
	s1.push_back('o');
	s1.push_back('r');
	s1.push_back('l');
	s1.push_back('d');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;//最开始capacity容量为15
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;//空间不够，增容

	//clear:清空整个字符串
	s1.clear();
	s1.push_back('d'); //清空之后重新插入数据
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	for (auto e : s1)//打印
	{
		cout << e << " ";
	}
	cout << endl;

	//empty
	s1.clear();
	if (s1.empty())
	{
		s1.push_back('d'); 
		s1.push_back('d');
		s1.push_back('d');
		s1.push_back('d');
		s1.push_back('d');
	}
	for (auto e : s1)//打印
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_string6()
{
	//string的增容过程：第一次2倍，之后是1.5倍增容
	string s;
	size_t sz = 0;
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void test_string7()
{
	//reserve和resize
	string s1("hello world");
	s1.reserve(100);
	cout << s1.size() << endl;//11
	cout << s1.capacity() << endl;//111

	string s2("hello world");
	s2.resize(5);//小于size小于capacity，直接缩小size
	cout << s2.size() << endl;//5
	cout << s2.capacity() << endl;//15(容量最开始就是15)
	cout << s2 << endl;

	string s3("hello world");
	s3.resize(14, 'a');//大于size小于capacity，后面的初始化为a，size变为14，capacity是15不变
	cout << s3.size() << endl;//14
	cout << s3.capacity() << endl;//15
	cout << s3 << endl;

	string s4("hello world");
	s4.resize(20, 'b');//大于size大于capacity，后面的初始化为x，size变为20，capacity会增容
	cout << s4.size() << endl;//20
	cout << s4.capacity() << endl;//31
	cout << s4 << endl;
}
void test_string8()
{
	string s("hello,world");
	for (size_t i = 0; i < s.size();  i++)
	{
		if (s[i] == ',')
		{
			s[i] = '%';
		}
	}
	cout << s << endl;
	
	for (auto& e : s)
	{
		if (e == '%')
		{
			e = ',';
		}
	}
	cout << s << endl;

	string::iterator sit = s.begin();
	while (sit != s.end())
	{
		if (*sit == ',')
		{
			*sit = '%';
		}
		sit++;
	}
	cout << s << endl;

	size_t pos = s.find('%');
	s[pos] = ',';
	cout << s << endl;
}
void test_string9()
{
	string s1("hello ");
	string s2("world");
	s1.append(s2);
	cout << s1 << endl;

	string s3("hello ");
	string s4("world");
	s3 += s4;
	s3 += "!!!";
	cout << s3 << endl;

	string s5("hello ");
	string s6("world");
	string s7 = s5 + s6;//不建议用+
	cout << s7 << endl;
}
void test_string10()
{
	string s1("ello");
	string s2(" world");
	s1.insert(0, 1, 'h');//在第0个位置的前面插入一个字符h
	cout << s1 << endl;

	s1.insert(s1.end(), 'w');//在end()位置，插入一个字符w
	cout << s1 << endl;

	s1.erase(5, 1);//从第五个位置开始删除，删除1个字符
	cout << s1 << endl;

	s1.insert(5, " world");//从第五个位置开始插入，插入一个字符串
	cout << s1 << endl;

	s1.insert(5, s2);//从第五个位置开始插入，插入一个对象s2
	cout << s1 << endl;
}
void test_string11()
{
	string s1("hello");
	string s2("world");
	s1.swap(s2);//string类里实现的swap，建议使用
	cout << s1 << "--" << s2 << endl;

	swap(s1, s2);//C++库里的swap，不建议使用，效率低下
	cout << s1 << "--" << s2 << endl;
}
void test_string12()
{
	string s("http://www.cplusplus.com/");
	s.replace(0, 4, "https");
	cout << s << endl;

	s[5] = '\0';
	cout << s << endl;//遇到\0不会结束，直到size才结束
	cout << s.c_str() << endl;//以C形式输出，遇到\0就会停止
}
string GetSuffix(const string& s)
{
	size_t pos = s.find('.');
	if (pos == string::npos)
	{
		return s;
	}
	else
	{
		//string suffix(s, pos, s.size() - pos);//构造
		string suffix = s.substr(pos);//获取子串:从pos取到最后
		return suffix;
	}
}
void test_string13()
{
	//取后缀
	string file("file.cpp");
	string suffix(file, 4, 4);
	cout << suffix << endl;

	size_t pos = file.find('.');//找到了返回第一次出现的位置，没找到返回npos（-1）
	if (pos != string::npos)//说明找到了
	{
		string suffix(file, pos, file.size()-pos);//构造函数：从file的pos(.)位置开始，取总长减pos个字符，拷贝构造给suffix
		cout << suffix << endl;
	}

	cout << GetSuffix("test.c.cpp") << endl;

	//取域名
	string url("http://www.cplusplus.com/reference/string/string/substr/");
	size_t start = url.find("://")+3;//找"://"字符串，然后+3记录最后一个/的位置
	size_t finish = url.find('/',start);//从刚刚记录的start位置开始找下一个'/'
	//start和finish之间的一段就是域名
	string domain=url.substr(start, finish-start);//从start开始输出，输出finish-start个字符（finish-start就是域名的字符个数）
	cout << domain << endl;

}
//int main()
//{
	//test_string1(); 
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	//test_string8();
	//test_string9();
	//test_string10();
	//test_string11();
	//test_string12();
	//test_string13();

	//system("pause");
	//return 0;
//}