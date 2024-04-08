#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
struct point {
	long long x, y;
}a[50009];
long long dis(point m, point n) {
	return (m.x - n.x) * (m.x - n.x) + (m.y - n.y) * (m.y - n.y);
}
int main() {
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	long long mi = 0x7fffffff;
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n ; j++) {
			mi = min(dis(a[i], a[j]), mi);
		}
	}
	cout << fixed << setprecision(4) << (double)sqrt(mi);

	return 0;
}