#pragma once

#include <iostream>

using std::cout;
using std::endl;

template<class K,class V>
struct BSTreeNode//定义节点，节点有指向左节点的指针，指向右节点的指针，kv的pair
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	std::pair<K, V> _kv;

	BSTreeNode(const std::pair<K, V>& kv)//构造函数
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

template<class K, class V>
class BSTree//定义搜索二叉树，根节点
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V> &kv)//插入
	{
		//空树情况
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		//不为空树的情况
		Node* cur = _root;
		Node* parent = nullptr;
		//找到要插入的位置cur
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
		//进行连接节点
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
		//先找这个节点和它的父亲
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
				//找到了开始删除
				Node* del = cur;
				//1.cur的左为空，父亲指向cur的右子树，删除cur
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)//删的是根节点
					{
						_root = cur->_right;//根等于根的左子树
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
				//2.cur右为空，父亲指向cur的左子树，删除cur
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
				//3.cur左右都不为空，找个节点来替代cur
				else
				{
					//方法1：找一个右树的最左节点来代替它
					//右树的最左节点就是左为空的那个节点
					Node* preplace = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						preplace = replace;
						replace = replace->_left;
					}
					cur->_kv = replace->_kv;
					del = replace;
					//删除代替的最左节点（父亲指向它的右）
					if (preplace->_left == replace)
					{
						preplace->_left = replace->_right;
					}
					else
					{
						preplace->_right = replace->_right;
					}

					//方法2：找一个左树的最右节点来代替它
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
	void Inorder()//中序遍历
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