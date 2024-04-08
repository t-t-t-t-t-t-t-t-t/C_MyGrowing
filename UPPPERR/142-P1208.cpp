#include<iostream>
#include<algorithm>
using namespace std;

struct pe {
	long long num, v;
}a[200009];
bool cmp(pe a, pe b) {
	return a.v < b.v;
}
int main() {
	long long sum, n;
	cin >> sum >> n;
	for (long long i = 0; i < n; i++) 	cin >> a[i].v>>a[i].num;
	sort(a, a + n, cmp);
	long long nowv = 0,noww=0;
	long long i = 0;
	while (noww < sum) {
		noww += a[i].num;
		nowv += a[i].v * a[i].num;
		i++;
	}
	if (noww > sum) {
		nowv -= (noww - sum) * a[--i].v;
	}
	cout << nowv;

	return 0;
}