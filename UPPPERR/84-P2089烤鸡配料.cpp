#include<iostream>
using namespace std;
int n;
int ans[100];
int all = 0;
int ans1[100][10];
void dfs(int sum, int nth) {
	if (nth == 10) {
		if (sum == n) {
			for (int i = 0; i < 10; i++) {
				ans1[all][i] = ans[i];
			}
			all++;
			return;
		}
	}
	else if (sum > n || nth > 10)return;
	else {
		for (int i = 1; i <= 3; i++) {
			ans[nth] = i;
			dfs(sum + i, nth + 1);
		}
	}
}

int main() {
	cin >> n;
	if (n < 10)
	{
		cout << 0 << '\n';
		return 0;
	}
	dfs(0, 0);
	cout << all << '\n';

	for (int i = 0; i < all; i++) {
		for (int j = 0; j < 10; j++) {
			cout << ans1[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}