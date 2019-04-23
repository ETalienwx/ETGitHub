////设计一个类，只在堆上创建对象
//class HeapOnly
//{
//public:
//	static HeapOnly* GetHeapObj()
//	{
//		return new HeapOnly;
//	}
//private:
//	//构造函数私有
//	HeapOnly()
//	{}
//	//C++98：拷贝构造函数只声明不实现,并且声明成私有的
//	HeapOnly(const HeapOnly&);
//	//C++11：拷贝构造函数delete
//	HeapOnly(const HeapOnly&) = delete;
//};
//int main()
//{
//	HeapOnly* obj = HeapOnly::GetHeapObj();
//}


////设计一个类，只在栈上创建对象
////方法一
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};
//int main()
//{
//	StackOnly obj = StackOnly::GetStackObj();
//	return 0;
//}


////方法二
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();
//	}
//private:
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};
//int main()
//{
//	StackOnly obj = StackOnly::GetStackObj();
//}


////方法三
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();
//	}
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//};
//int main()
//{
//	StackOnly obj = StackOnly::GetStackObj();
//}



//#include <iostream>
////饿汉模式
//class ConfigSingleton
//{
//public:
//	//公有的接口来获取这个对象
//	static ConfigSingleton& GetInstance()
//	{
//		return _sinst;
//	}
//	void Print()//打印
//	{
//		std::cout << _ip << std::endl;
//		std::cout << _port << std::endl;
//	}
//private:
//	//构造函数私有
//	ConfigSingleton(const char* ip = "127.0.0.1" ,int port = 80)
//		:_ip(ip)
//		, _port(port)
//	{
//		//进行初始化工作
//	}
//
//	//防拷贝
//	ConfigSingleton(const ConfigSingleton&) = delete;//拷贝构造函数
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;//赋值运算符重载
//
//	//成员变量
//	const char* _ip;
//	int _port;
//
//	//定义一个自己类型的对象（相当于全局的，但是此时受类域的限制）
//	static ConfigSingleton _sinst;
//};
//
////定义这个对象_sinst
//ConfigSingleton ConfigSingleton::_sinst("127.0.0.1", 80);
//
//int main()
//{
//	//获取这个对象然后对象调Print函数
//	ConfigSingleton::GetInstance().Print();
//	system("pause");
//	return 0;
//}


//////////////////////////////////////////////////
//此处代码为练习有误，没有调试好ヽ(#`Д´)ﾉ┌┛〃//
//////////////////////////////////////////////////
////懒汉模式
//#include <iostream>
//#include <thread>
//#include <mutex>
//class ConfigSingleton
//{
//public:
//	static ConfigSingleton* GetInstance()
//	{
//		//双重检查
//		if (_psinst == nullptr)//这个判断是如果对象已经定义出来了，那么就直接返回空指针，就不用加锁解锁了
//		{
//			_mutex.lock();//加锁（保证线程是串行运行的）
//			if (_psinst == nullptr)//这个判断是如果是第一个线程过来为空就定义这个唯一的对象
//			{
//				_psinst = new ConfigSingleton;
//			}
//			_mutex.unlock();//解锁
//		}
//		return _psinst;
//	}
//	void Print()
//	{
//		std::cout << _ip << std::endl;
//		std::cout << _port << std::endl;
//	}
//private:
//	//构造函数私有
//	ConfigSingleton(const char* ip = "127.0.0.1", int port = 80)
//		:_ip(ip)
//		, _port(port)
//	{
//		std::cout << "ConfigSingleton(const char* ip ,int port)" << std::endl;
//	}
//
//	//~ConfigSingleton()
//	//{
//	//	std::cout << "~ConfigSingleton()" << std::endl;
//	//}
//
//	//成员变量
//	const char* _ip;
//	int _port;
//
//	//防拷贝
//	ConfigSingleton(const ConfigSingleton&) = delete;
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;
//
//	//定义一个内部类(内部类是外部类的友元)
//	//class GC
//	//{
//	//public:
//	//	~GC()
//	//	{
//	//		delete _psinst;
//	//	}
//	//};
//
//	//定义唯一对象的指针
//	static ConfigSingleton* _psinst;
//	static std::mutex _mutex;
//	//static GC _gc;
//};
//
////指针初始化为nullptr
//ConfigSingleton* ConfigSingleton::_psinst = nullptr;
//std::mutex ConfigSingleton::_mutex;
////ConfigSingleton::GC ConfigSingleton::_gc;
//
//
//void fun(int n)
//{
//	std::cout<<ConfigSingleton::GetInstance()<<std::endl;
//}
//
//int main()
//{
//	//两个线程都去调fun函数
//	std::thread t1(fun, 10);
//	std::thread t2(fun, 10);
//	t1.join();
//	t2.join();
//
//	system("pause");
//	return 0;
//}
///////////////////////////////////////////////////////////////////////




//懒汉
#include <iostream>
#include <thread>
#include <mutex>
class ConfigSingleton
{
public:
	static ConfigSingleton* GetInstance()
	{
		//双重检查
		if (_psinst == nullptr)//这个判断是如果对象已经定义出来了，那么就直接返回_psinst，就不用加锁解锁了,提高效率
		{
			_mutex.lock();//加锁
			if (_psinst == nullptr)//第一次调用时，如果是空就创建对象
			{
				_psinst = new ConfigSingleton;
			}
			_mutex.unlock();//解锁
		}
		return _psinst;
	}
	void Print()
	{
		std::cout << _ip << std::endl;
		std::cout << _port << std::endl;
	}
private:
	//构造函数私有
	ConfigSingleton(const char* ip = "127.0.0.1", int port = 80)
		:_ip(ip)
		, _port(port)
	{
		std::cout << "ConfigSingleton(const char* ip, int port)" << std::endl;
	}

	//析构函数
	~ConfigSingleton()
	{
		std::cout << "~ConfigSingleton()" << std::endl;
	}

	//成员变量
	const char* _ip;
	int _port;

	//内部类(垃圾回收站)
	class GC
	{
	public:
		~GC()
		{
			delete _psinst;
		}
	};

	//防拷贝
	ConfigSingleton(const ConfigSingleton&) = delete;
	ConfigSingleton& operator=(const ConfigSingleton&) = delete;

	//创建唯一对象的指针
	static ConfigSingleton* _psinst;
	static std::mutex _mutex;
	static GC _gc;
};

ConfigSingleton* ConfigSingleton::_psinst = nullptr;
std::mutex ConfigSingleton::_mutex;
ConfigSingleton::GC ConfigSingleton::_gc;

void fun(int n)
{
	ConfigSingleton::GetInstance()->Print();
	std::cout << ConfigSingleton::GetInstance() << std::endl;;
}
int main()
{
	std::thread t1(fun, 10);
	std::thread t2(fun, 10);
	t1.join();
	t2.join();

	return 0;
}