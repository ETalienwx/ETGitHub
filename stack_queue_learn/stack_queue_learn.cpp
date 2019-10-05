#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void test_stack()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.size() << endl;

	stack<int> ss(s);
	//while (!ss.empty())
	//{
	//	cout << ss.top() << endl;
	//	ss.pop();
	//}

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	st.swap(ss);
	while (!ss.empty())
	{
		cout << ss.top() << endl;
		ss.pop();
	}
}
void test_queue()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	queue<int> qq;
	qq.push(1);
	qq.push(2);
	qq.push(3);
	qq.push(4);
	qq.push(5);

	qq.swap(q);

	cout << qq.size() << endl;
	cout << qq.front() << endl;
	cout << qq.back() << endl;

	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
}
int main()
{
	//test_stack();
	test_queue();
	system("pause");
	return 0;
}