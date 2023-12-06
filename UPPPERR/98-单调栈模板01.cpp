#include<iostream>
#include<stack>
using namespace std;
stack<int>b;
const int N = 2e5 + 9;
int a[N],c[N];
int main()
{
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		while ( b.size()&&a[i] <= a[b.top()])
		{
			b.pop();
		}
		if (b.empty()) { c[i] = -1; }
		else { c[i] = a[b.top()]; }
		b.push(i);
	}
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << ' ';
	}
	return 0;
}