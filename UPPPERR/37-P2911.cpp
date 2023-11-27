#include<iostream>
#include<algorithm>
using namespace std;
int a[40], b[40], c[40],t[100000];
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	for (int i = 1; i <= x; i++)
	{
		a[i] = i;
	}
	for (int i = 1; i <= y; i++)
	{
		b[i] = i;
	}
	for (int i = 1; i <= z; i++)
	{
		c[i] = i;
	}
	int m = 0;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			for (int k = 1; k <= z; k++)
			{
				t[a[i] + b[j] + c[k]]++;
				m = max(a[i] + b[j] + c[k], m);
			}
		}
	}
	int n=0,num;
	for (int i = 3; i <= m; i++)
	{
		if (t[i] > n)
		{
			n = t[i];
			num = i;
		}
	}
	cout << num;
	return 0;
}