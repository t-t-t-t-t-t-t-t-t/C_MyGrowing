#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const long long M = 998244353;
const int N = 1e5 + 9;
long long a[N], b[N], c[N], d[N];
int main() {
	long long n; cin >> n;
	long long p = 0, q = 0;
	for (long long j = 0; j < n; j++)
	{
		cin >> a[j]; a[j] %= M;
	}
	for (long long j = 0; j < n; j++)
	{
		cin >> b[j]; b[j] %= M;
	}
	for (long long j = 0; j < n; j++)
	{
		cin >> c[j]; c[j] %= M;
	}
	for (long long j = 0; j < n; j++)
	{
		cin >> d[j]; d[j] %= M;
	}
	long double P=0;
	for (long long i = 0; i < n; i++) {
		p = (b[i] * c[i] % M + a[i] * d[i] % M - 2 * a[i]  * c[i] % M) % M;
		q = (b[i]* d[i]) % M;
		P += (p*1.0 / q*1.0);
	}
	cout << int(n * P)%M;
	return 0;
}