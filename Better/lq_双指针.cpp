#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n; cin >> n;
	int s; cin >> s;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 0;
	int sum = 0;
	int mi = n;
	while (r < n) {
		if (sum < s) {
			sum += a[r++];
		}
		else if (sum >= s && l < r) {
			sum -= a[l++];
			mi = min(mi, r - l + 1);
		}
	}
	if (mi == n) { cout << 0; }
	else {
		cout << mi;
	}
	delete[]a;
	return 0;
}