#include<iostream>
using namespace std;
const long long N = 1e5 + 9;
int dp[1000][1000];
int a[N];
int main() {
	long long m, n,ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= a[i]) {
				dp[i][j] += dp[i - 1][j - a[i]];
			}
			dp[i][j] += dp[i - 1][j];
		}
	}
	cout << dp[n][m];
	return 0;
}