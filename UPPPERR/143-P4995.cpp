#include<iostream>
#include<algorithm>
using namespace std;
long long a[400];
int main() {
	long long n; cin >> n;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 1);
	long long p1 = 0, p2 = n;
	long long sum = 0;
	while(p1<p2){
		sum += (a[p2] - a[p1]) * (a[p2] - a[p1]);
		p1++;
		sum += (a[p2] - a[p1]) * (a[p2] - a[p1]);
		p2--;
	}
	cout << sum;
	return 0;
}