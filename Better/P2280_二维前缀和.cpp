#include<iostream>
#include<algorithm>
using namespace std;
const long long N = 5100;
long long a[N][N];
int main() {
	long long n, m; 
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		long long x, y, v;
		cin >> x >> y >> v;
		a[x+1][y+1] += v;
	}
	for (long long i = 1; i < N; i++) {
		for (long long j = 1; j < N; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	if(m>N){
		cout << a[N - 1][N - 1];
		return 0;
	}
	long long ma = 0;
	for (long long i = m; i < N; i++) {
		for (long long j = m; j < N; j++) {
			ma = max(ma, a[i][j] - a[i - m][j] - a[i][j - m] + a[i - m][j - m]);
		}
	}
	cout << ma;
	return 0;
}