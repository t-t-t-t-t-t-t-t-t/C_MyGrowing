#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
const int N = 2e5;
struct guo {
	int po, val;
}a[N];
int main() {
	int n; cin >> n;
	n = pow(2, n);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].val;
		a[i].po = i;
	}
	while (n > 2) {
		int po = 1;
		for (int i = 1; i <= n; i+=2) {
			a[po++] = (a[i].val > a[i + 1].val ? a[i] : a[i + 1]);
		}
		n /= 2;
	}
	cout << (a[1].val > a[2].val ? a[2].po : a[1].po);
	return 0;
}