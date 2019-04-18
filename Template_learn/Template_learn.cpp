#include <iostream>

////模板*****************************************************************
//template <class T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	char c = 1, d = 2;
//	Swap(a, b);
//	Swap(c, d);
//	return 0;
//}


////隐式实例化和显示实例化****************************************************
//template <class T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10, b = 20;
//	char c = 1, d = 2;
//	//隐式实例化：编译器会自动推导参数的类型
//	Add(a, b);
//	Add(c, d);
//
//	//显示实例化：在模板函数名后面加上<>写清楚参数类型
//	Add<char>(a, d);
//
//	return 0;
//}


////匹配规则*******************************************************
//template <class T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	Swap(a, b);
//	return 0;
//}


//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	//与非模板函数匹配，编译器不需要实例化（因此调用的是专门处理int的加法函数）
//	Add(1, 2); 
//	//调用编译器实例化出的Add版本（这里是显示实例化，调用的是模板加法函数，然后实例化为int）
//	Add<int>(1, 2); 
//}



//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	// 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2); 
//	// 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	Add(1, 2.0); 
//}




//实现简单的模板Vector类**************************************************
#include <assert.h>
template <class T>
class Vector
{
public:
	Vector(int capacity=10)
		:_a(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	//析构函数：在类中声明，在类外定义
	~Vector();

	void PushBack(const T& x)
	{
		//这里要有容量检查，空间不够要增容（暂时省略）
		_a[_size] = x;
		_size++;
	}
	void PopBack()
	{
		_size--;
	}
	size_t size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _a[pos];
	}
private:
	T* _a;
	size_t _size;
	size_t _capacity;
};

template <class T>
Vector<T>::~Vector()
{
	if (_a)
	{
		delete[] _a;
		_size = _capacity = 0;
	}
}
int main()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	for (size_t i=0; i<v1.size();i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;


	Vector<char> v2;
	v2.PushBack('a');
	v2.PushBack('b');
	v2.PushBack('c');

	for (size_t i = 0; i<v2.size(); i++)
	{
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}