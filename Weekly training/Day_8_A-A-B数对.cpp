#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const long long N = 2e5 + 9;
long long a[N];
int main()
{
	long long n, c;
	cin >> n >> c;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (upper_bound(a, a + n, a[i] + c) - a - (lower_bound(a, a + n, a[i] + c) - a));
	}
	cout << sum;
	return 0;
}