//https://www.luogu.com.cn/problem/P3397
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;int t;
	cin >> n;	
	cin >> t;
	vector<int>a(n+2),b(n+2);
	a[0] = 0,b[0]=0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i] - a[i - 1];
	}

	for (int i = 0; i < t; i++)
	{
		int l, r, c;
		cin >> l >> r >> c;
		b[l] += c;
		b[r + 1] -= c;//可能越界
	}
	int min = 100000;
	for (int i = 1; i <= n; i++)
	{
		b[i] += b[i - 1];
		if (min > b[i])
		{
			min = b[i];
		}
	}
	cout << min;
	return 0;

}
