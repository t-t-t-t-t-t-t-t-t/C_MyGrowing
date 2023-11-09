//https://www.luogu.com.cn/problem/P2670
#include<iostream>
using namespace std;
int main()
{
	char  a[1000][1000];
	int n, m, b[1000][1000] = { 0 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '*')
			{
				b[i + 1][j + 1]++;
				b[i + 1][j - 1]++;
				b[i + 1][j]++;
				b[i][j + 1]++;
				b[i][j - 1]++;
				b[i - 1][j]++;
				b[i - 1][j + 1]++;
				b[i - 1][j - 1]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '*')
			{
				cout << "*";
			}
			else
			{
				cout << b[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}