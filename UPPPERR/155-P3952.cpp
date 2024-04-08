#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1009;
int m, n;
int map[N][N];
int wmap[N][N];
int dx[5] = { 0,-1,0,1 };
int dy[5] = { -1,0,1,0 };
int ma = -1e9;
struct point {
	int x, y;
};

bool check(int mid) {
	memset(wmap, 0, sizeof(wmap));
	queue<point>b;
	b.push(point{ 1,1 });
	while (b.size()) {
		int x = b.front().x;
		int y = b.front().y;
		b.pop();
		for (int i = 0; i < 4; i++) {
			int afx = x + dx[i], afy = y + dy[i];
			if (afx <= n && afx >= 1 && afy <= m && afy >= 1) {
				if (!wmap[afx][afy] && map[afx][afy] <= mid)
				{
					b.push(point{ afx,afy });
					wmap[afx][afy] = 1;
					if (afx == n) { return 1; }
				}
			}
		}
	}
	return 0;
}
int main() {
	cin >> n >> m;
	int l = 0, r, mid;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			r = max(map[i][j], r);
		}
	}
	while (l + 1 != r) {
		mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r;
	return 0;
}