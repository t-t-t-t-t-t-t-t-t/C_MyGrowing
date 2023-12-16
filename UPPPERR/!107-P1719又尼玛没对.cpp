#include<iostream>
#include<algorithm>
using namespace std;
int a[150][125];
int main()
{
	int n;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	int ma = -1000000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = i; j <= n; k++)
			{
				for (int l = j; l <= n; l++)
				{
					ma = max(ma, a[k][l] - a[k][j - 1] - a[i - 1][l] + a[i - 1][j - 1]);
				}
			}
		}
	}
	cout << ma;
	return 0;
}