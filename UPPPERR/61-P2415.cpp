#include<iostream>
#include<cmath>
using namespace std;
long long a[10000];
int main()
{
	int t=0;
	long long sum = 0;
	while (cin >> a[t]) {
		sum += a[t]; t++;
	}
	long long m;
	m = pow(2, t - 1);
	cout << sum * m;
	return 0;
}