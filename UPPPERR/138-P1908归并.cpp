#include<iostream>
using namespace std;
const long long N = 5e5 + 9;
long long ans = 0;
long long a[N],save[N];
void mysort(long long l, long long r) {
	if (l >= r)return;
	long long mid = l + r >> 1;
	mysort(l, mid );
	mysort(mid+1, r);
	long long begin1 = l, begin2 = mid+1, end1 = mid , end2 = r;
	long long num = l;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] > a[begin2]) {
			ans += mid - begin1+1;
			save[num++] = a[begin2++];
		}
		else {
			save[num++] = a[begin1++];
		}
	}
	while (begin1 <= end1) {
		save[num++] = a[begin1++];
	}
	while (begin2 <= end2) {
		save[num++] = a[begin2++];
	}
	for (long long i = l; i <= r; i++) {
		a[i] = save[i];
	}
}

int main() {
	long long n; cin >> n;
	for (long long i = 0; i < n; i++) 	cin >> a[i];
	mysort(0, n - 1);
	cout << ans;
	return 0;
}