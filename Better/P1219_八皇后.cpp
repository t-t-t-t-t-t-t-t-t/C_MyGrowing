#include<iostream>
using namespace std;
const int N = 5500;
int ans = 0, a[N], yi[N], rtob[N], rtot[N];
int n;
void in(int x, int y) {
	yi[y] = 1;
	rtob[x - y + n] = 1;
	rtot[x + y] = 1;
	a[x] = y;
}
void out(int x, int y) {
	yi[y] = 0;
	rtob[x - y + n] = 0;
	rtot[x + y] = 0;
}
void dfs(int num = 1) {
	if (num > n) {
		if (ans >= 3) {
			ans++;
		}
		else {
			ans++;
			for (int i = 1; i <= n; i++) {
				cout << a[i] << ' ';
			}
			cout << '\n';
		}
	}
	else {

		for (int i = 1; i <= n; i++) {
			if (yi[i] == 0 && rtob[num - i + n] == 0 && rtot[num + i] == 0) {
				in(num, i);// 占位
				dfs(num + 1); // 放下一个皇后
				out(num, i);  // 回溯,再后面所有可以运行的
			}
		}
	}
}
int main() {
	cin >> n;
	dfs();
	cout << ans;
	return 0;
}