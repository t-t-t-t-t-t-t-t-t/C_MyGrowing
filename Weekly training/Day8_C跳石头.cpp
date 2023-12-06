#include<iostream>
using namespace std;
long long l, m, n;
long long a[50010];
bool check(long long x)
{
	long long num = 0;
	long long pr = a[0];
	for (long long i = 1; i <= m+1; i++){
		if (a[i] - pr < x)num++;///////////
		else pr = a[i];
	}
	if (num > n)
	{
		return 0;
	}
	return 1;
}
int main()
{
	cin >> l >> m >> n;
	if (m == 0)
	{
		cout << l;/////////////////////
		return 0;
	}
	for (long long i = 1; i <= m; i++)cin >> a[i];
	a[m + 1] = l;
	long long r = l;
	long long l = 1;
	long long mid;
	while (l + 1 != r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid;
		}
		else { r = mid; }
	}
	cout << l;
	return 0;
}