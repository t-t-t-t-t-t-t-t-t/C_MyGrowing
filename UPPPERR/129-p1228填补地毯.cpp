#include<iostream>
#include<cmath>
using namespace std;
#define f(a,b,c) cout<<a<<' '<<b<<' '<<c<<'\n';
void dfs(long long x1, long long y1, long long x2, long long y2, long long kx, long long ky) {
	if (x2 - x1 + 1 == 2 && y2 - y1 + 1 == 2) {
		if (x1 == kx && y1 == ky) {
			f(x2, y2, 1);
		}
		if (x1 == kx && y2 == ky) {
			f(x2, y1, 2);
		}
		if (x2 == kx && y1 == ky) {
			f(x1, y2, 3);
		}
		if (x2 == kx && y2 == ky) {
			f(x1, y1, 4);
		}
		return;
	}
	long long x = (x2 - x1 + 1) / 2 + x1 - 1;
	long long y = (y2 - y1 + 1) / 2 + y1 - 1;
	if (x >= kx && y >= ky) {
		f(x + 1, y + 1, 1);
		dfs(x1, y1, x, y, kx, ky);
		dfs(x1, y + 1, x, y2, x, y + 1);
		dfs(x + 1, y1, x2, y, x + 1, y);
		dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);
	}
	if (x >= kx && y < ky) {
		f(x + 1, y, 2);
		dfs(x1, y1, x, y, x, y);
		dfs(x1, y + 1, x, y2, kx, ky);
		dfs(x + 1, y1, x2, y, x + 1, y);
		dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);
	}
	if (x < kx && y >= ky) {
		f(x, y + 1, 3);
		dfs(x1, y1, x, y, x, y);
		dfs(x1, y + 1, x, y2, x, y + 1);
		dfs(x + 1, y1, x2, y, kx, ky);
		dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);
	}
	if (x < kx && y < ky) {
		f(x, y, 4);
		dfs(x1, y1, x, y, x, y);
		dfs(x1, y + 1, x, y2, x, y + 1);
		dfs(x + 1, y1, x2, y, x + 1, y);
		dfs(x + 1, y + 1, x2, y2, kx, ky);
	}

}

int main() {
	long long n; long long kx, ky;
	cin >> n >> kx >> ky;
	long long m = pow(2, n);
	dfs(1, 1, m, m, kx, ky);
	return 0;
}