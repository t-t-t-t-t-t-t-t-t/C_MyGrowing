#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e3 + 9;
int a[20000], w[20000];
int dp[30][20000];
int main() {
	int v, n;
	cin >> v >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		w[i] = a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + a[i]);
			}
		}
	}
	cout <<v- dp[n][v];
	return 0;
}