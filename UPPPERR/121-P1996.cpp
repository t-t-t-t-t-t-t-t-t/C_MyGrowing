#include<iostream>
using namespace std;
long long a[1000];
int main() {
	long long n, k;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++)a[i] = i;
	long long cnt = 0,po = 0,num = 0;
	while (cnt != n) {
		po++;
		if (po > n)po = 1;
		if (a[po]) {
			num++;
			if (num > k)num = 1;
			if (num == k) { 
				cout << po << ' ';
				a[po] = 0; 
				cnt++;
			}

		}
	}
	return 0;
}