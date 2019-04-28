#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
////智能指针原型
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
////	v.at(0) = 10;//会抛异常
////	delete p;//导致p没有释放
////}
//
//void Func()
//{
//	int* p = new int;
//	SmartPtr<int> sp(p);
//	vector<int> v;
//	v.at(0) = 10;//会抛异常
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



//智能指针变形-->智能锁
//template<class T>//定义成模板就是如果有另外类型的锁来了也可以用这个SmartLock
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
//	SmartLock<mutex> smtlock(mtx);//用smtlock对象管理mtx这个锁，出了作用域会自动解锁
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


//像指针一样的行为
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
//	T& operator*()//对象出了作用域还在，所以返回引用
//	{
//		return *_ptr;//返回这个对象
//	}
//	T* operator->()
//	{
//		return _ptr;//返回原生指针
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


//auto_ptr：C++98,管理权转移：带有缺陷的早期设计，公司严禁使用它
//unique_ptr：C++11,简单粗暴，防拷贝，效率高，功能不全。鼓励使用它
//shared_ptr：功能全，支持拷贝，引用计数。设计复杂，循环引用
namespace PTR
{
	template <class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)//构造
			:_ptr(ptr)
		{}
		~auto_ptr()//析构
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

		//拷贝构造
		//p1(p2)--->p2拷贝构造p1，此时把p2置空，管理权交给p1
		auto_ptr(auto_ptr<T>& ptr)//this指针是p1，ptr是p2
			:_ptr(ptr._ptr)
		{
			ptr._ptr = nullptr;
		}

		//赋值
		//p1=p2
		//this=ptr--->把ptr给this，再把ptr置空
		auto_ptr& operator=(auto_ptr<T>& ptr)
		{
			if (this != &ptr)//不是自己给自己赋值
			{
				//如果p1不为空就把p1的资源先释放
				if (_ptr)
				{
					delete _ptr;
				}
				//再进行权限的转移
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
		//防拷贝
		//拷贝构造
		unique_ptr(unique_ptr<T>& ptr) = delete;
		//赋值
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
		T& operator*()//*是单目运算符
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//p2(p1)
		//拷贝构造
		shared_ptr(const shared_ptr<T>& ptr)
			:_ptr(ptr._ptr)
			, _pcount(ptr._pcount)
		{
			++(*_pcount);
		}
		//p1=p2
		//赋值
		shared_ptr<T>& operator=(shared_ptr<T>& ptr)
		{
			//if (this != &ptr)不算错，但是可以优化
			//两个对象的ptr如果相同就不进去了，否则--再++就是做无用功了
			//要是相同的对象，ptr相同就不作操作
			//要是不同的对象，你们指向同一块空间，ptr相同也不作操作
			if (_ptr != ptr._ptr)
			{
				if (--(*_pcount) == 0)//当要赋值的对象引用计数为1才可以进行释放
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
		//查看引用计数
		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;//引用计数
	};
}

//void test_auto_ptr()
//{
//	PTR::auto_ptr<int> p1(new int);
//	PTR::auto_ptr<int> p2(p1);//拷贝构造会把p1置空
//	//*p1 = 10;//p1悬空
//	*p2 = 20;
//
//	PTR::auto_ptr<int> p3(new int);
//	p3 = p2;//这里赋值会把p2置空
//	//*p2 = 30;//悬空
//	*p3 = 40;
//}
//void test_unique_ptr()
//{
//	PTR::unique_ptr<int> p1(new int);
//	//PTR::unique_ptr<int> p2(p1);//报错：提示使用已删除的函数
//}
//void test_shared_ptr()
//{
//	PTR::shared_ptr<int> p1(new int);//p1引用计数为1
//	PTR::shared_ptr<int> p2(p1);//p1，p2指向同一块空间，这块空间的引用计数变为2
//	*p1 = 10;
//	*p2 = 20;
//	p1 = p2;
//
//	PTR::shared_ptr<int> p3(new int(30));//p3引用计数为1
//	p1 = p3;//p3和p1指向同一块空间，引用计数变为2，p2引用计数变为1
//}
//void copy_ptr(PTR::shared_ptr<int>& ptr, int n)
//{
//	//拷贝n次ptr
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
//	test_shared_ptr_safe();//引用计数出现问题，说明多线程下不安全
//	system("pause");
//	return 0;
//}



//shared_ptr安全的版本
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
		//拷贝构造
		shared_ptr(const shared_ptr<T>& ptr)
			:_ptr(ptr._ptr)
			, _pcount(ptr._pcount)
			, _pmtx(ptr._pmtx)
		{
			//++(*_pcount);
			Addref();
		}
		//赋值
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
		//查看引用计数
		int use_count(){return *_pcount;}
	private:
		T* _ptr;
		int* _pcount;//引用计数
		mutex* _pmtx;
	};
}
void copy_ptr(safe::shared_ptr<int>& ptr, int n)
{
	//拷贝n次ptr
	for (int i = 0; i < n; i++)
	{
		safe::shared_ptr<int> copy(ptr);//线程安全
		++(*copy);//不是线程安全的
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




#include <memory>//shared_ptr的头文件
//shared_ptr的循环引用问题
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



//定制删除器
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