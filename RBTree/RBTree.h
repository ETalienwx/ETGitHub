#pragma once

#include <iostream>
using namespace std;

enum Color
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
    pair<K, V> _kv;
	Color _col;

	RBTreeNode(const pair<K, V> kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		//空树情况
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		//不是空树的情况
		Node* parent = nullptr;
		Node* cur = _root;
		//找到位置
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
		//新开节点，连接起来
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//进行调整树
		while(parent && parent->_col == RED)//parent存在且为红色
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)//父亲在左边，叔叔在右边
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)//叔叔存在且为红
				{
					//变色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//叔叔不存在或者为黑
				{
					//先处理双旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//单旋+变色
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else//grandfather->right == parent  父亲在右边，叔叔在左边
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)//叔叔存在且为红
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//叔叔不存在或者为黑
				{
					//先处理双旋
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					//单旋+变色
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;
		if (_root == parent)
		{
			_root = subR;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subR;
			else
				ppnode->_right = subR;
		}
		subR->_parent = ppnode;
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subL;
			else
				ppnode->_right = subL;
		}
		subL->_parent = ppnode;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};

void TestRBTree()
{
	RBTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	t.Inorder();
}