#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "bitset.h"
using namespace std;

template <class K, class HashFunc1, class HashFunc2, class HashFunc3>
class BloomFilter
{
public:
	BloomFilter(size_t keynum)//������λ�أ�
		:_bs(keynum * 5)
	{}
	void set(const K& key)
	{
		//������ַ��������翪��50��λ����ô��ӳ���λ��һ��������50��λ֮�䣬���Ҫģ��bitnum
		//ʹ���������λ������50��λ�����ӳ��
		size_t index1 = HashFunc1()(key) % _bs.GetBitNum();
		size_t index2 = HashFunc2()(key) % _bs.GetBitNum();
		size_t index3 = HashFunc3()(key) % _bs.GetBitNum();

		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}
	//void reset(const K& key)//��¡��������֧��reset��������Ϊͬһ��λ���ܱ���ͬ���ַ�����ӳ��
	bool test(const K& key)
	{
		size_t index1 = HashFunc1()(key) % _bs.GetBitNum();
		if (_bs.test(index1) == false)
			return false;
		size_t index2 = HashFunc2()(key) % _bs.GetBitNum();
		if (_bs.test(index2) == false)
			return false;
		size_t index3 = HashFunc3()(key) % _bs.GetBitNum();
		if (_bs.test(index3) == false)
			return false;

		return true;//�п��ܻ�������е����
	}

private:
	bitset _bs;//λͼ
};

//�ַ�����ϣ�㷨
struct StrHash1
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto e : s)
		{
			hash *= 131;
			hash += e;
		}
		return hash;
	}
};
struct StrHash2
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto e : s)
		{
			hash *= 65599;
			hash += e;
		}
		return hash;
	}
};
struct StrHash3
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		size_t magic = 63689;
		for (auto e : s)
		{
			hash *= magic;
			hash += e;

			magic *= 378551;
		}
		return hash;
	}
};

void test_BloomFilter()
{
	BloomFilter<string, StrHash1, StrHash2, StrHash3> bf(10);
	cout << StrHash1()("https://mail.qq.com") << endl;
	cout << StrHash2()("https://mail.qq.com") << endl;
	cout << StrHash3()("https://mail.qq.com") << endl;

	string url1("https://mail.qq.com1");
	string url2("https://mail.qq.com2");
	string url3("https://mail.qq.com3");
	string url4("http://mail.qq.com");
	string url5("https://maill.qq.com");

	bf.set(url1);
	bf.set(url2);
	bf.set(url3);

	cout << bf.test(url1) << endl;
	cout << bf.test(url2) << endl;
	cout << bf.test(url3) << endl;
	cout << bf.test(url4) << endl;
	cout << bf.test(url5) << endl;
}