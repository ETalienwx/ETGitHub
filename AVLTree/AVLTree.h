#pragma once

#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	std::pair<K, V> _kv;

	int _bf;//平衡因子

	AVLTreeNode(std::pair<K, V> &kv)//构造函数
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	bool Insert(std::pair<K, V> &kv)
	{
		//空树的情况
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return 0;
		}
		//不为空树
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)//找到插入的位置
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
		cur = new Node(kv);//新开一个节点
		//连接起来
		if (parent->_kv.first  > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		//更新平衡因子
		while (parent)
		{
			//如果在左边插入，平衡因子--
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			//如果在右边插入，平衡因子++
			else
			{
				parent->_bf++;
			}

			//判断平衡因子
			if (parent->_bf == 0)//平衡
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//继续更新，向上走
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//旋转
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				//抛异常
				assert(false);
			}
		}
		return true;
	}
	void RotateL(Node* parent)//左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;
		if (parent == _root)
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
		subR->_bf = parent->_bf = 0;
	}
	void RotateR(Node* parent)//右单旋
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
		subL->_bf = parent->_bf = 0;
	}
	void RotateLR(Node* parent)//左右双旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)
		{
			subL->_bf = parent->_bf = 0;
		}
	}
	void RotateRL(Node* parent)//右左双旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->_right);
		RotateL(parent);
		subRL->_bf = 0;
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			subR->_bf = parent->_bf = 0;
		}
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int LeftHeight = Height(root->_left);
		int RightHeight = Height(root->_right);
		return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	bool _IsBalance(Node *root)
	{
		if (root == nullptr)
			return true;
		int LeftHeight = Height(root->_left);
		int RightHeight = Height(root->_right);
		//每棵子树的都应该是平衡的（所以需要递归左子树和右子树）
		return abs(LeftHeight - RightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}
private:
	Node* _root;
};

void TestAVLTree()
{
	AVLTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	t.Inorder();
	cout << t.IsBalance() << endl;
}