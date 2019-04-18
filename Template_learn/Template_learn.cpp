#include <iostream>

////ģ��*****************************************************************
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


////��ʽʵ��������ʾʵ����****************************************************
//template <class T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 10, b = 20;
//	char c = 1, d = 2;
//	//��ʽʵ���������������Զ��Ƶ�����������
//	Add(a, b);
//	Add(c, d);
//
//	//��ʾʵ��������ģ�庯�����������<>д�����������
//	Add<char>(a, d);
//
//	return 0;
//}


////ƥ�����*******************************************************
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


//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	//���ģ�庯��ƥ�䣬����������Ҫʵ��������˵��õ���ר�Ŵ���int�ļӷ�������
//	Add(1, 2); 
//	//���ñ�����ʵ��������Add�汾����������ʾʵ���������õ���ģ��ӷ�������Ȼ��ʵ����Ϊint��
//	Add<int>(1, 2); 
//}



//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	// ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2); 
//	// ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	Add(1, 2.0); 
//}




//ʵ�ּ򵥵�ģ��Vector��**************************************************
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
	//���������������������������ⶨ��
	~Vector();

	void PushBack(const T& x)
	{
		//����Ҫ��������飬�ռ䲻��Ҫ���ݣ���ʱʡ�ԣ�
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