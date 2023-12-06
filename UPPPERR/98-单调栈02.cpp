#include<iostream>
using namespace std;
const int N = 2e5+9;
int a[N], b[N],c[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int top = 0;
	for (int i = 0; i < n; i++)
	{
		while (top && a[b[top]] >= a[i])
		{
			top--;
		}
		if (!top) { c[i] = -1; }
		else { c[i] = a[b[top]]; }
		b[++top] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << ' ';
	}
	return 0;
}