#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 2e5 + 9;
vector<int>X;
struct p {
	int l, r;
}m[N];
int po(int x) {
	return lower_bound(X.begin(), X.end(), x) - X.begin();
}
int a[N];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i].l >> m[i].r;
		X.push_back(m[i].l);
		X.push_back(m[i].r);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for (int i = 0; i < n; i++) {
		a[po(m[i].r)]--;
		a[po(m[i].l)]++;
	}
	for (int i = 1; i < X.size(); i++) {
		a[i] += a[i - 1];
	}
	int all = 0; int le, ri;
	for (int i = 0; i < X.size(); i++) {
		if (a[i] != 0 && a[i - 1] == 0) { le = i; }
		if (a[i] == 0 && a[i - 1] != 0) { ri = i; all += X[ri] - X[le]; }
	}
	cout << all;

	return 0;
}
