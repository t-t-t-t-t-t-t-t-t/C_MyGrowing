#include<iostream>
using namespace std;
const int N = 5500;
int n;
int a[N][N];
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
void dfs(int x = 0, int y = 0) {
	if (x < n && x >= 0 && y < n && y >= 0 && a[x][y] == 0) {
		a[x][y] = 2;//圈外的填充
		for (int i = 0; i < 4; i++) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {// 搜索四个边界
		if (a[0][i] != 1) { dfs(0, i); }
		if (a[n][i] != 1) { dfs(n - 1, i); }
		if (a[i][0] != 1) { dfs(i, 0); }
		if (a[i][n] != 1) { dfs(i, n - 1); }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				cout << "2 ";
			}
			else if (a[i][j] == 1) {
				cout << "1 ";
			}
			else if (a[i][j] == 2) {
				cout << "0 ";
			}
		}
		cout << '\n';
	}
	return 0;
}