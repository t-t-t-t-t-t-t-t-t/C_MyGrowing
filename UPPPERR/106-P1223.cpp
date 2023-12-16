#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
long long n;
struct s {
	long long ti, po;
}a[1005];

bool cmp(s a, s b)
{
	return a.ti < b.ti;
}
long long b = 0, sum = 0;
int main()
{
	long long ma = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i].ti;
		a[i].po = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (long long i = 1; i <= n; i++)
	{
		cout << a[i].po << ' ';
	}
	cout << '\n';
	for (long long i = 1; i < n; i++)//为什么不等于n，应为题目求的是排队等的时间；
	{
		b += a[i].ti;
		sum += b;
	}
	double ans = sum * 1.0 / n;
	cout << fixed << setprecision(2) << ans;
	return 0;
}