#pragma once

#include <iostream>

using std::cout;
using std::endl;

template<class K,class V>
struct BSTreeNode//����ڵ㣬�ڵ���ָ����ڵ��ָ�룬ָ���ҽڵ��ָ�룬kv��pair
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	std::pair<K, V> _kv;

	BSTreeNode(const std::pair<K, V>& kv)//���캯��
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

template<class K, class V>
class BSTree//�������������������ڵ�
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V> &kv)//����
	{
		//�������
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		//��Ϊ���������
		Node* cur = _root;
		Node* parent = nullptr;
		//�ҵ�Ҫ�����λ��cur
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		//�������ӽڵ�
		cur = new Node(kv);
		if (parent->_kv.first > cur->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}

	Node* Find(const K &k)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > k)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < k)
			{
				cur = cur->_right;
			}
			else
				return cur;
		}
		return nullptr;
	}

	bool Erase(const K &k)
	{
		//��������ڵ�����ĸ���
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//�ҵ��˿�ʼɾ��
				Node* del = cur;
				//1.cur����Ϊ�գ�����ָ��cur����������ɾ��cur
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)//ɾ���Ǹ��ڵ�
					{
						_root = cur->_right;//�����ڸ���������
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				//2.cur��Ϊ�գ�����ָ��cur����������ɾ��cur
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				//3.cur���Ҷ���Ϊ�գ��Ҹ��ڵ������cur
				else
				{
					//����1����һ������������ڵ���������
					//����������ڵ������Ϊ�յ��Ǹ��ڵ�
					Node* preplace = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						preplace = replace;
						replace = replace->_left;
					}
					cur->_kv = replace->_kv;
					del = replace;
					//ɾ�����������ڵ㣨����ָ�������ң�
					if (preplace->_left == replace)
					{
						preplace->_left = replace->_right;
					}
					else
					{
						preplace->_right = replace->_right;
					}

					//����2����һ�����������ҽڵ���������
					//Node* preplace = cur;
					//Node* replace = cur->_left;
					//while (replace->_right)
					//{
					//	preplace = replace;
					//	replace = replace->_right;
					//}
					//cur->_kv = replace->_kv;
					//del = replace;
					//if (preplace->_left == replace)
					//{
					//	preplace->_left = replace->_left;
					//}
					//else
					//{
					//	preplace->_right = replace->_left;
					//}
				}
				delete del;
				return true;
			}
		}
		return false;
	}
	void Inorder()//�������
	{
		_Inorder(_root);
		cout << endl;
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << " ";
		_Inorder(root->_right);
	}
private:
	Node* _root;
};

void TestBSTree()
{
	BSTree<int, int> bs;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };

	for (auto e : a)
	{
		bs.Insert(std::make_pair(e, e));
	}

	bs.Inorder();

	bs.Erase(2);
	bs.Erase(8);
	bs.Erase(2);
	bs.Erase(1);
	bs.Erase(5);
	bs.Erase(7);

	bs.Inorder();

	for (auto e : a)
	{
		bs.Erase(e);
	}
	bs.Inorder();
}