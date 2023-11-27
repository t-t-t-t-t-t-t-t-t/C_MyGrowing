#include <cstring>
#include<iostream>
using namespace std;
int ma(int m, int x)
{
	if (m > x)
	{
		return m;
	}
	else { return x; }
}
int main()
{
	int n,m=0,num=0;
	cin >> n;
	int a[1000],b[10000000];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (b[a[i]])
		{
			continue;
		}
		m = ma(a[i], m);
		b[a[i]]++;
		num++;
	}
	cout << num << '\n';
	for (int i = 0; i <= m; i++)
	{
		if (b[i]) { cout << i<<' '; }
	}
	return 0;
}