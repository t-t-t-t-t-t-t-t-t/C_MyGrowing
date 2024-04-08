#include<iostream>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int cnt[N];
int main() {
	int m, n;
	cin >> m >> n;
	int p = 1, all = 0; int l = 1, r = 1;
	for (int i = 1; i <= n; i++) {
		int va; cin >> va;
		if (!cnt[va]) {	
			cnt[va] = 1;
			if (r - l + 1 > m) {
				cnt[a[l]] = 0;
				l++;
			}
			a[r] = va;
			r++;
			all++;
		}
	}
	cout << all;
	return 0;
}