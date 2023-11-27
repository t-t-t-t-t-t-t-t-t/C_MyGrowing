#include<iostream>
using namespace std;
int a[100000];
int main()
{
	int len, m,l,r;
	cin >> len >> m;
	len++;// 坐标轴包含 0 ；多加上一棵；
	int t = len;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		if (l == r) { continue; }
		a[l] ++;
		a[r + 1] --;
	}
	for (int i = 1; i <= t; i++)//判定到t；if (a[i-1]) 才可以判定完；
	{
		a[i] += a[i - 1];
		if (a[i-1])//  判定到i=t=len+1 ； (a[i-1]) 才可以判定完； 0到len-1为树 共len棵树 （正确）
		{
			len--;
		}
	}
	cout << len;
	return 0;
}