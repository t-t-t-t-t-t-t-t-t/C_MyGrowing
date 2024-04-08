#include<iostream>
using namespace std;
int f[300000],a[300000];
int main() {
	int n,ma=-1e6;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	f[0] = a[0];
	for (int i = 1; i < n; i++) {
		f[i] = max(f[i - 1] + a[i], a[i]);
		ma = max(f[i], ma);
	}
	cout << ma;
	return 0;

}