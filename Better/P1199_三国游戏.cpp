#include<iostream>
#include<algorithm>
using namespace std;
const int N = 550;
int a[N][N];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sort(a[i] + 1, a[i] + 1 + n);
		ans = (ans > a[i][n - 1] ? ans : a[i][n - 1]);
	}
	cout << 1 << '\n' << ans;
	return 0;
}