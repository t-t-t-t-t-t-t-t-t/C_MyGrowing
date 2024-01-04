#include<iostream>
using namespace std;
long long a[100009];
const long long M = 998244353;
int main() {
	long long n; cin >> n;
	for (long long i = 0; i < n; i++) cin >> a[i];
	long long U = 1 << n;
	long long sum = 0;
	for (long long i = 0; i < U; i++) {
		long long k = 0;
		for (long long j = 0; j < n; j++) {
			if (i & (1 << j)) { k++; }
		}
		if (k == 4) {
			long long m[5]; long long o = 0;
			for (long long j = 0; j < n; j++) {
				if (i & (1 << j))
				{
					m[o++] = a[n-j-1];
				}
			}
			sum += ((m[0] ^ m[1]) + (m[2] ^ m[3]))%M;
		}
	}
	cout << sum%M;
	return 0;
}