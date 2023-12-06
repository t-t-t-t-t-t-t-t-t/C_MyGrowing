#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int n, num, c;
bool check(int dis) {
	int pr = -1e9;
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - pr < dis)num++;
		else pr = a[i];
	}
	if (num > c)return 0;
	return 1;
}
int main()
{
	cin >> n >> num;
	c = n - num;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	int l = 0, r = a[n - 1];
	int mid;
	while (l + 1 != r) {
		mid = l + r >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}