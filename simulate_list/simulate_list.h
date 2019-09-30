#pragma once

#include <iostream>
using namespace std;

//节点
template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;

	ListNode(const T& data = T())//这里给的是缺省，T()调的是T的默认构造函数
		:_prev(nullptr)
		, _next(nullptr)
		, _data(data)
	{}
};

//迭代器
template <class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	Node* _node;//节点的指针

	//用传过来的节点的指针构造一个ListIterator的对象
	ListIterator(Node* node)
		:_node(node)
	{}

	//实现运算符的重载，比如++，节点的指针++之后就指向连续空间的下一个了，就找不到下一个节点的指针了
	//因此需要运算符的重载
	//如节点的指针++就让他指向下一个节点，并且返回这个迭代器

	Ref operator*()//返回的是节点里数据的引用：为了保证可读可写，返回引用的话我也可以改变这个节点的值
	{
		return _node->_data;//返回的是节点的数据
	}

	Ptr operator->()//返回data的指针，data的指针里才会有数据
	{
		//return &_node->_data;
		return &(operator*());//取地址
	}

	//++it; -->it.operator++()
	Self& operator++()//前置++返回++之后的
	{
		_node = _node->_next;//指向下一个位置
		return *this;//返回的是下一个位置的迭代器
	}

	//it++;
	Self operator++(int)//后置++返回++之前的,出了作用域不在了，所以不能返回引用
	{
		Self tmp(*this);//保存之前的迭代器
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//两个迭代器进行比较的时候比较的是节点的指针，两个指针指向的是同一个位置说明迭代器相等
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	//~ListIterator()
	//不需要写，因为节点的生命周期是跟着链表走的，链表销毁了节点才会销毁
	//迭代器不是管理一个节点，它是封装这个节点之后让我们用同样的方式去遍历这个链表，而不暴露里面的东西
	//我们可以理解为迭代器就像是一个隔离层，屏蔽了里面实现的东西，但是外面的使用都是一样的
};

//链表
template <class T>
class List
{
	typedef ListNode<T> Node;//节点
public:
	typedef ListIterator<T, T&, T*> iterator;//迭代器
	typedef ListIterator<T, const T&, const T*> const_iterator;//const迭代器

	List()//构造函数
	{
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;
	}

	//begin是第一个位置的迭代器，有节点的指针就能构造迭代器，只有链表才有节点的指针
	//begin和end都是链表实现的，迭代器是我传过去一个节点，他构造一个ListIterator的对象
	iterator begin()
	{
		//迭代器不是节点的指针，它是一个ListIterator的自定义类型
		//ListIterator可以用节点的指针构造一个对象
		return iterator(_head->_next);//调它的构造函数
	}
	iterator end()
	{
		return iterator(_head);//左闭右开区间
	}
	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}

	List(const List<T>& l)//拷贝构造（拷贝构造要支持深拷贝，否则析构的时候会有问题）
	{
		this->_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		List<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			this->PushBack(*it);
			it++;
		}
	}

	//现代写法
	List<int>& operator=(List<int> l)
	{
		//假设l1 = l2
		//l就是l2拷贝构造出来的，因此交换this和l两个链表的头节点即可
		//交换过后l1原来的值会在l里，l出了作用域会自动释放（临时对象）
		swap(this->_head, l._head);
		return *this;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	void Clear()//链表的清理
	{
		Node* cur = _head->_next;//从第一个节点开始删除
		while(cur != _head)
		{
			Node* next = cur->_next;//删除这个节点之前要保存下一个节点
			delete cur;

			cur = next;
		}

		//不删除头节点，最后要把头节点链接好
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(const T& x)
	{
		//方法一
		//Node* tail = _head->_prev;
		//Node* newnode = new Node(x);
		//tail->_next = newnode;
		//newnode->_prev = tail;
		//_head->_prev = newnode;
		//newnode->_next = _head;

		//方法二
		Insert(end(), x);//在end()的前面插入
	}
	void PopBack()
	{
		Erase(--end());//end()指向的是最后一个的下一个，因此尾删的是--end()
	}
	void PushFront(const T& x)
	{
		Insert(begin(), x);//在begin()的前面插入
	}
	void PopFront()
	{
		Erase(begin());//begin()是头节点的下一个，头删就是删除这个节点
	}
	void Insert(iterator pos, const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}
	iterator Erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;
		prev->_next = next;
		next->_prev = prev;
		delete cur;

		return iterator(next);//返回下一个位置的迭代器
	}

	size_t Size()
	{
		size_t size = 0;
		for (const auto& e : *this)
		{
			size++;
		}
		return size;
	}

	bool Empty()
	{
		//return _head->_next = _head;
		return begin() == end();
	}
private:
	Node* _head;
};

