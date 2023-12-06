#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005],dp[1005][1005];
int main()
{
	int r;
	cin >> r;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		dp[r - 1][i] = a[r - 1][i];
	}
	for (int i = r - 2; i >= 0; i--)
	{
		for (int j = 0; j < i + 1; j++)
		{
			dp[i][j] = max(dp[i + 1][j + 1] , dp[i + 1][j]) + a[i][j];
		}
	}
	cout << dp[0][0];
	return 0;
}