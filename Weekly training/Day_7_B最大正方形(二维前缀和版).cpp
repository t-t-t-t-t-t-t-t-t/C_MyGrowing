//https://www.luogu.com.cn/problem/P1387
// 动态规划，二分法都可以，（不会）
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[105][105];
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k <= min(m - i, n - j); k++)
			{
				if (a[i + k-1][j + k-1] - a[i + k-1][j - 1] - a[i - 1][j + k-1] + a[i - 1][j - 1] == k * k && k > ans)
				{
					ans = k;
				}
			}
		}
	}
	cout << ans;

	return 0;
}
