#include<iostream>
using namespace std;
const long long N = 1e5 + 9;
int dp[N];
int a[N];
int main() {
	long long m, n, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
		dp[0]= 1;//��ʾ���ʼ���Ǹ�����һ����Ʒ����0Ԫ�ķ���Ϊ1��
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j >= a[i]) {
				dp[j] += dp[j - a[i]];
			}
		}
	}
	cout << dp[m];
	return 0;
}