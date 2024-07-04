#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const long long N = 2e5;
long long a[N], t[N];
int main() {
	long long n; cin >> n;
	for (long long i = 1; i <= n; i++)cin >> a[i];
	for (long long i = 1; i <= n; i++) {
		t[i] = a[i] - a[i - 1];
	}

	long long num1 = 0, num2 = 0;
	for (long long i = 2; i <= n; i++) {
		if (t[i] < 0) {
			num1 -= t[i];// 
		}
		else {
			num2 += t[i];
		}
	}
	long long ans1 = max(num1, num2);
	long long ans2 = abs(num1 - num2) + 1; // 修改区间 ， 多出来的那一步可以顺便修改第一位
	cout << ans1 << '\n' << ans2;
	return 0;
}