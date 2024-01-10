#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][1005];
int dp[1005];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) dp[i] = a[n][i];
	

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			{
				dp[j] = a[i][j] + max(dp[j], dp[j + 1]);
			}
		}
	}
	cout << dp[1];
	return 0;
}