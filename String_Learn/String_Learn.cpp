#include <string>
#include <iostream>
using namespace std;

void test_string1()
{
	string s1("hello");//���캯��
	string s2 = "world";//��������ʽ���͵�ת��������+��������+�Ż���

	char str1[] = "�Է�";
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
	string s1("hello");//����
	string s2(s1);//��������
	string s3("world");
	s1 = s3;//��ֵ
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	string s4(s3, 3);//�Ӷ���ĵ���λ��ʼȡ��ֱ��\0
	cout << s4 << endl;

	string s5("world", 3);//ȡ���ַ�����ǰ��λ
	cout << s5 << endl;

	string s6(s3, 1, 3);//�Ӷ���ĵ�һλ��ʼȡ��ȡ��λ
	cout << s6 << endl;

	string s7("world", 1, 3);//�Ӹ��ַ����ĵ�һλ��ʼȡ��ȡ��λ
	cout << s7 << endl;
}
//�����ַ���"1234abcd"
void Print1(string s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";//֧���±����
		//�ȼ���cout << s.operator[](i) << " ";
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
		//*sit = '1';�����޸�����
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
		//*sit = '1';�����޸�����
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
//���ݱ����ַ���ʵ���ַ�ת����"123456"
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
	cout << s1.capacity() << endl;//�ʼcapacity����Ϊ15
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;//�ռ䲻��������

	//clear:��������ַ���
	s1.clear();
	s1.push_back('d'); //���֮�����²�������
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	s1.push_back('d');
	for (auto e : s1)//��ӡ
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
	for (auto e : s1)//��ӡ
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_string6()
{
	//string�����ݹ��̣���һ��2����֮����1.5������
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
	//reserve��resize
	string s1("hello world");
	s1.reserve(100);
	cout << s1.size() << endl;//11
	cout << s1.capacity() << endl;//111

	string s2("hello world");
	s2.resize(5);//С��sizeС��capacity��ֱ����Сsize
	cout << s2.size() << endl;//5
	cout << s2.capacity() << endl;//15(�����ʼ����15)
	cout << s2 << endl;

	string s3("hello world");
	s3.resize(14, 'a');//����sizeС��capacity������ĳ�ʼ��Ϊa��size��Ϊ14��capacity��15����
	cout << s3.size() << endl;//14
	cout << s3.capacity() << endl;//15
	cout << s3 << endl;

	string s4("hello world");
	s4.resize(20, 'b');//����size����capacity������ĳ�ʼ��Ϊx��size��Ϊ20��capacity������
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
	string s7 = s5 + s6;//��������+
	cout << s7 << endl;
}
void test_string10()
{
	string s1("ello");
	string s2(" world");
	s1.insert(0, 1, 'h');//�ڵ�0��λ�õ�ǰ�����һ���ַ�h
	cout << s1 << endl;

	s1.insert(s1.end(), 'w');//��end()λ�ã�����һ���ַ�w
	cout << s1 << endl;

	s1.erase(5, 1);//�ӵ����λ�ÿ�ʼɾ����ɾ��1���ַ�
	cout << s1 << endl;

	s1.insert(5, " world");//�ӵ����λ�ÿ�ʼ���룬����һ���ַ���
	cout << s1 << endl;

	s1.insert(5, s2);//�ӵ����λ�ÿ�ʼ���룬����һ������s2
	cout << s1 << endl;
}
void test_string11()
{
	string s1("hello");
	string s2("world");
	s1.swap(s2);//string����ʵ�ֵ�swap������ʹ��
	cout << s1 << "--" << s2 << endl;

	swap(s1, s2);//C++�����swap��������ʹ�ã�Ч�ʵ���
	cout << s1 << "--" << s2 << endl;
}
void test_string12()
{
	string s("http://www.cplusplus.com/");
	s.replace(0, 4, "https");
	cout << s << endl;

	s[5] = '\0';
	cout << s << endl;//����\0���������ֱ��size�Ž���
	cout << s.c_str() << endl;//��C��ʽ���������\0�ͻ�ֹͣ
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
		//string suffix(s, pos, s.size() - pos);//����
		string suffix = s.substr(pos);//��ȡ�Ӵ�:��posȡ�����
		return suffix;
	}
}
void test_string13()
{
	//ȡ��׺
	string file("file.cpp");
	string suffix(file, 4, 4);
	cout << suffix << endl;

	size_t pos = file.find('.');//�ҵ��˷��ص�һ�γ��ֵ�λ�ã�û�ҵ�����npos��-1��
	if (pos != string::npos)//˵���ҵ���
	{
		string suffix(file, pos, file.size()-pos);//���캯������file��pos(.)λ�ÿ�ʼ��ȡ�ܳ���pos���ַ������������suffix
		cout << suffix << endl;
	}

	cout << GetSuffix("test.c.cpp") << endl;

	//ȡ����
	string url("http://www.cplusplus.com/reference/string/string/substr/");
	size_t start = url.find("://")+3;//��"://"�ַ�����Ȼ��+3��¼���һ��/��λ��
	size_t finish = url.find('/',start);//�Ӹոռ�¼��startλ�ÿ�ʼ����һ��'/'
	//start��finish֮���һ�ξ�������
	string domain=url.substr(start, finish-start);//��start��ʼ��������finish-start���ַ���finish-start�����������ַ�������
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