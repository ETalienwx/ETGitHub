#pragma once
#include <iostream>
#include <vector>
using namespace std;

class bitset
{
public:
	bitset(size_t bitnum)//开多少位
		:_bitnum(bitnum)
	{
		_bit.resize((bitnum >> 3)+1, 0);//除8+1是确定数组开多大，数组中的每一个元素都可以标识8个数据
	}
	void set(size_t x)
	{
		//size_t index = x / 8;//计算是数组的第几个段
		size_t index = x >> 3;
		size_t num = x % 8;//计算是这个段的第几个位

		//把对应的比特位置为1
		_bit[index] |= (1 << num);
	}
	void reset(size_t x)
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		//把对应的比特位置为0
		_bit[index] &= (~(1 << num));
	}
	bool test(size_t x)
	{
		//判断对应位是0还是1
		size_t index = x >> 3;
		size_t num = x % 8;

		return _bit[index] & (1 << num);//与完之后的结果如果非零就说明存在，为零说明不存在
	}
private:
	vector<char> _bit;
	size_t _bitnum;
};

void test_bitset()
{
	bitset bs(10000);
	bs.set(6666);
	bs.set(666);
	bs.set(66);
	bs.set(6);

	cout << bs.test(6) << endl;//存在
	cout << bs.test(66) << endl;//存在
	cout << bs.test(666) << endl;//存在
	cout << bs.test(6666) << endl;//存在
	cout << bs.test(16) << endl;//不存在
}