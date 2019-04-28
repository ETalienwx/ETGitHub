#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
////����ָ��ԭ��
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		cout <<"delete:"<< _ptr << endl;
//		delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//
////void Func()
////{
////	int* p = new int;
////	vector<int> v;
////	v.at(0) = 10;//�����쳣
////	delete p;//����pû���ͷ�
////}
//
//void Func()
//{
//	int* p = new int;
//	SmartPtr<int> sp(p);
//	vector<int> v;
//	v.at(0) = 10;//�����쳣
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	system("pause");
//	return 0;
//}



//����ָ�����-->������
//template<class T>//�����ģ�����������������͵�������Ҳ���������SmartLock
//class SmartLock
//{
//public:
//	SmartLock(T& lock)
//		:_lock(lock)
//	{
//		_lock.lock();
//	}
//	~SmartLock()
//	{
//		_lock.unlock();
//	}
//private:
//	T& _lock;
//};
//
//mutex mtx;
//
//void add(int n, int *value)
//{
//	SmartLock<mutex> smtlock(mtx);//��smtlock�������mtx�������������������Զ�����
//	for (int i = 0; i < n; i++)
//	{
//		++(*value);
//	}
//}
//
//int main()
//{
//	int x = 0;
//	thread t1(add, 10000, &x);
//	thread t2(add, 10000, &x);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//	system("pause");
//	return 0;
//}


//��ָ��һ������Ϊ
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		delete _ptr;
//	}
//	T& operator*()//��������������ڣ����Է�������
//	{
//		return *_ptr;//�����������
//	}
//	T* operator->()
//	{
//		return _ptr;//����ԭ��ָ��
//	}
//private:
//	T* _ptr;
//};
//
//struct A
//{
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	SmartPtr<int> p1(new int);
//	*p1 = 10;
//	cout << *p1 << endl;
//
//	SmartPtr<A> p2(new A);
//	(*p2)._a1 = 10;
//	cout << p2->_a1 << endl;
//	p2->_a2 = 100;
//	cout << p2->_a2 << endl;
//
//	system("pause");
//	return 0;
//}


//auto_ptr��C++98,����Ȩת�ƣ�����ȱ�ݵ�������ƣ���˾�Ͻ�ʹ����
//unique_ptr��C++11,�򵥴ֱ�����������Ч�ʸߣ����ܲ�ȫ������ʹ����
//shared_ptr������ȫ��֧�ֿ��������ü�������Ƹ��ӣ�ѭ������
namespace PTR
{
	template <class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)//����
			:_ptr(ptr)
		{}
		~auto_ptr()//����
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}

		//��������
		//p1(p2)--->p2��������p1����ʱ��p2�ÿգ�����Ȩ����p1
		auto_ptr(auto_ptr<T>& ptr)//thisָ����p1��ptr��p2
			:_ptr(ptr._ptr)
		{
			ptr._ptr = nullptr;
		}

		//��ֵ
		//p1=p2
		//this=ptr--->��ptr��this���ٰ�ptr�ÿ�
		auto_ptr& operator=(auto_ptr<T>& ptr)
		{
			if (this != &ptr)//�����Լ����Լ���ֵ
			{
				//���p1��Ϊ�վͰ�p1����Դ���ͷ�
				if (_ptr)
				{
					delete _ptr;
				}
				//�ٽ���Ȩ�޵�ת��
				_ptr = ptr._ptr;
				ptr._ptr = nullptr;
			}
			return *this;
		}
	private:
		T* _ptr;
	};


	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//������
		//��������
		unique_ptr(unique_ptr<T>& ptr) = delete;
		//��ֵ
		unique_ptr<T>& operator=(unique_ptr<T>& ptr) = delete;
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}
		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}
		}
		T& operator*()//*�ǵ�Ŀ�����
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//p2(p1)
		//��������
		shared_ptr(const shared_ptr<T>& ptr)
			:_ptr(ptr._ptr)
			, _pcount(ptr._pcount)
		{
			++(*_pcount);
		}
		//p1=p2
		//��ֵ
		shared_ptr<T>& operator=(shared_ptr<T>& ptr)
		{
			//if (this != &ptr)��������ǿ����Ż�
			//���������ptr�����ͬ�Ͳ���ȥ�ˣ�����--��++���������ù���
			//Ҫ����ͬ�Ķ���ptr��ͬ�Ͳ�������
			//Ҫ�ǲ�ͬ�Ķ�������ָ��ͬһ��ռ䣬ptr��ͬҲ��������
			if (_ptr != ptr._ptr)
			{
				if (--(*_pcount) == 0)//��Ҫ��ֵ�Ķ������ü���Ϊ1�ſ��Խ����ͷ�
				{ 
					delete _ptr;
					delete _pcount;
				}
				_ptr = ptr._ptr;
				_pcount = ptr._pcount;
				++(*_pcount);
			}
			return *this;
		}
		//�鿴���ü���
		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;//���ü���
	};
}

//void test_auto_ptr()
//{
//	PTR::auto_ptr<int> p1(new int);
//	PTR::auto_ptr<int> p2(p1);//����������p1�ÿ�
//	//*p1 = 10;//p1����
//	*p2 = 20;
//
//	PTR::auto_ptr<int> p3(new int);
//	p3 = p2;//���︳ֵ���p2�ÿ�
//	//*p2 = 30;//����
//	*p3 = 40;
//}
//void test_unique_ptr()
//{
//	PTR::unique_ptr<int> p1(new int);
//	//PTR::unique_ptr<int> p2(p1);//������ʾʹ����ɾ���ĺ���
//}
//void test_shared_ptr()
//{
//	PTR::shared_ptr<int> p1(new int);//p1���ü���Ϊ1
//	PTR::shared_ptr<int> p2(p1);//p1��p2ָ��ͬһ��ռ䣬���ռ�����ü�����Ϊ2
//	*p1 = 10;
//	*p2 = 20;
//	p1 = p2;
//
//	PTR::shared_ptr<int> p3(new int(30));//p3���ü���Ϊ1
//	p1 = p3;//p3��p1ָ��ͬһ��ռ䣬���ü�����Ϊ2��p2���ü�����Ϊ1
//}
//void copy_ptr(PTR::shared_ptr<int>& ptr, int n)
//{
//	//����n��ptr
//	for (int i = 0; i < n; i++)
//	{
//		PTR::shared_ptr<int> copy(ptr);
//	}
//}
//void test_shared_ptr_safe()
//{
//	PTR::shared_ptr<int> p(new int);
//	thread t1(copy_ptr, p, 1000);
//	thread t2(copy_ptr, p, 1000);
//
//	cout << p.use_count() << endl;
//	t1.join();
//	t2.join();
//}
//int main()
//{
//	//test_auto_ptr();
//	//test_unique_ptr();
//	//test_shared_ptr();
//	test_shared_ptr_safe();//���ü����������⣬˵�����߳��²���ȫ
//	system("pause");
//	return 0;
//}



//shared_ptr��ȫ�İ汾
namespace safe
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}
		~shared_ptr()
		{
			Release();
		}
		T& operator*(){return *_ptr;}
		T* operator->(){return _ptr;}
		void Addref()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}
		void Release()
		{
			_pmtx->lock();
			int flag = 0;
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
				flag = 1;
			}
			_pmtx->unlock();
			if (flag == 1){	delete _pmtx; }
		}
		//��������
		shared_ptr(const shared_ptr<T>& ptr)
			:_ptr(ptr._ptr)
			, _pcount(ptr._pcount)
			, _pmtx(ptr._pmtx)
		{
			//++(*_pcount);
			Addref();
		}
		//��ֵ
		shared_ptr<T>& operator=(const shared_ptr<T>& ptr)
		{
			if (_ptr != ptr._ptr)
			{
				Release();

				_ptr = ptr._ptr;
				_pcount = ptr._pcount;
				_pmtx = ptr._pmtx;

				Addref();
			}
			return *this;
		}
		//�鿴���ü���
		int use_count(){return *_pcount;}
	private:
		T* _ptr;
		int* _pcount;//���ü���
		mutex* _pmtx;
	};
}
void copy_ptr(safe::shared_ptr<int>& ptr, int n)
{
	//����n��ptr
	for (int i = 0; i < n; i++)
	{
		safe::shared_ptr<int> copy(ptr);//�̰߳�ȫ
		++(*copy);//�����̰߳�ȫ��
	}
}
void test_shared_ptr_safe()
{
	safe::shared_ptr<int> p(new int(0));
	thread t1(copy_ptr, p, 1000);
	thread t2(copy_ptr, p, 1000);
	t1.join();
	t2.join();
	cout << p.use_count() << endl;
	cout << *p << endl;
}
//int main()
//{
//	test_shared_ptr_safe();
//	system("pause");
//	return 0;
//}




#include <memory>//shared_ptr��ͷ�ļ�
//shared_ptr��ѭ����������
struct ListNode
{
	std::weak_ptr<ListNode> _prev;
	std::weak_ptr<ListNode> _next;
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};
void test_shared_ptr_cycle_ref()
{
	std::shared_ptr<ListNode> node1(new ListNode);
	std::shared_ptr<ListNode> node2(new ListNode);
	node1->_next = node2;
	node2->_prev = node1;
}
//int main()
//{
//	test_shared_ptr_cycle_ref();
//	system("pause");
//	return 0;
//}



//����ɾ����
template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};
struct test
{
	~test()
	{
		cout << "~test()" << endl;
	}
};
void test_shared_ptr_delete()
{
	DeleteArray<test> del;
	std::shared_ptr<test> ptr(new test[10], del);
}
int main()
{
	test_shared_ptr_delete();
	system("pause");
	return 0;
}