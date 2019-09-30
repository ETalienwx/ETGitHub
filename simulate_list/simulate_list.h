#pragma once

#include <iostream>
using namespace std;

//�ڵ�
template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;

	ListNode(const T& data = T())//���������ȱʡ��T()������T��Ĭ�Ϲ��캯��
		:_prev(nullptr)
		, _next(nullptr)
		, _data(data)
	{}
};

//������
template <class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	Node* _node;//�ڵ��ָ��

	//�ô������Ľڵ��ָ�빹��һ��ListIterator�Ķ���
	ListIterator(Node* node)
		:_node(node)
	{}

	//ʵ������������أ�����++���ڵ��ָ��++֮���ָ�������ռ����һ���ˣ����Ҳ�����һ���ڵ��ָ����
	//�����Ҫ�����������
	//��ڵ��ָ��++������ָ����һ���ڵ㣬���ҷ������������

	Ref operator*()//���ص��ǽڵ������ݵ����ã�Ϊ�˱�֤�ɶ���д���������õĻ���Ҳ���Ըı�����ڵ��ֵ
	{
		return _node->_data;//���ص��ǽڵ������
	}

	Ptr operator->()//����data��ָ�룬data��ָ����Ż�������
	{
		//return &_node->_data;
		return &(operator*());//ȡ��ַ
	}

	//++it; -->it.operator++()
	Self& operator++()//ǰ��++����++֮���
	{
		_node = _node->_next;//ָ����һ��λ��
		return *this;//���ص�����һ��λ�õĵ�����
	}

	//it++;
	Self operator++(int)//����++����++֮ǰ��,�������������ˣ����Բ��ܷ�������
	{
		Self tmp(*this);//����֮ǰ�ĵ�����
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

	//�������������бȽϵ�ʱ��Ƚϵ��ǽڵ��ָ�룬����ָ��ָ�����ͬһ��λ��˵�����������
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	//~ListIterator()
	//����Ҫд����Ϊ�ڵ�����������Ǹ��������ߵģ����������˽ڵ�Ż�����
	//���������ǹ���һ���ڵ㣬���Ƿ�װ����ڵ�֮����������ͬ���ķ�ʽȥ�����������������¶����Ķ���
	//���ǿ������Ϊ������������һ������㣬����������ʵ�ֵĶ��������������ʹ�ö���һ����
};

//����
template <class T>
class List
{
	typedef ListNode<T> Node;//�ڵ�
public:
	typedef ListIterator<T, T&, T*> iterator;//������
	typedef ListIterator<T, const T&, const T*> const_iterator;//const������

	List()//���캯��
	{
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;
	}

	//begin�ǵ�һ��λ�õĵ��������нڵ��ָ����ܹ����������ֻ��������нڵ��ָ��
	//begin��end��������ʵ�ֵģ����������Ҵ���ȥһ���ڵ㣬������һ��ListIterator�Ķ���
	iterator begin()
	{
		//���������ǽڵ��ָ�룬����һ��ListIterator���Զ�������
		//ListIterator�����ýڵ��ָ�빹��һ������
		return iterator(_head->_next);//�����Ĺ��캯��
	}
	iterator end()
	{
		return iterator(_head);//����ҿ�����
	}
	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}

	List(const List<T>& l)//�������죨��������Ҫ֧�����������������ʱ��������⣩
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

	//�ִ�д��
	List<int>& operator=(List<int> l)
	{
		//����l1 = l2
		//l����l2������������ģ���˽���this��l���������ͷ�ڵ㼴��
		//��������l1ԭ����ֵ����l�l������������Զ��ͷţ���ʱ����
		swap(this->_head, l._head);
		return *this;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	void Clear()//���������
	{
		Node* cur = _head->_next;//�ӵ�һ���ڵ㿪ʼɾ��
		while(cur != _head)
		{
			Node* next = cur->_next;//ɾ������ڵ�֮ǰҪ������һ���ڵ�
			delete cur;

			cur = next;
		}

		//��ɾ��ͷ�ڵ㣬���Ҫ��ͷ�ڵ����Ӻ�
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(const T& x)
	{
		//����һ
		//Node* tail = _head->_prev;
		//Node* newnode = new Node(x);
		//tail->_next = newnode;
		//newnode->_prev = tail;
		//_head->_prev = newnode;
		//newnode->_next = _head;

		//������
		Insert(end(), x);//��end()��ǰ�����
	}
	void PopBack()
	{
		Erase(--end());//end()ָ��������һ������һ�������βɾ����--end()
	}
	void PushFront(const T& x)
	{
		Insert(begin(), x);//��begin()��ǰ�����
	}
	void PopFront()
	{
		Erase(begin());//begin()��ͷ�ڵ����һ����ͷɾ����ɾ������ڵ�
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

		return iterator(next);//������һ��λ�õĵ�����
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

