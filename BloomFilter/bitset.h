#pragma once
#include <iostream>
#include <vector>
using namespace std;

class bitset
{
public:
	bitset(size_t bitnum)//������λ
		:_bitnum(bitnum)
	{
		_bit.resize((bitnum >> 3) + 1, 0);//��8+1��ȷ�����鿪��������е�ÿһ��Ԫ�ض����Ա�ʶ8������
	}
	void set(size_t x)
	{
		//size_t index = x / 8;//����������ĵڼ�����
		size_t index = x >> 3;
		size_t num = x % 8;//����������εĵڼ���λ

		//�Ѷ�Ӧ�ı���λ��Ϊ1
		_bit[index] |= (1 << num);
	}
	void reset(size_t x)
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		//�Ѷ�Ӧ�ı���λ��Ϊ0
		_bit[index] &= (~(1 << num));
	}
	bool test(size_t x)
	{
		//�ж϶�Ӧλ��0����1
		size_t index = x >> 3;
		size_t num = x % 8;

		return _bit[index] & (1 << num);//����֮��Ľ����������˵�����ڣ�Ϊ��˵��������
	}
	size_t GetBitNum()
	{
		return _bitnum;
	}
private:
	vector<char> _bit;
	size_t _bitnum;
};