#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const long long N = 2e6 + 9;
long long sumv[N], num[N], w[N], v[N], l[N], r[N];
long long n, m, s;
long long check(long long x) {
	memset(num, 0, sizeof(num));
	memset(sumv, 0, sizeof(sumv));
	for (long long i = 1; i <= n; i++)
	{
		if (w[i] >= x) {
			num[i] = num[i - 1] + 1;
			sumv[i] = sumv[i - 1] + v[i];
		}
		else {
			num[i] = num[i - 1];
			sumv[i] = sumv[i - 1];
		}
	}
	long long y = 0;
	for (long long i = 1; i <= m; i++)
	{
		y += (num[r[i]] - num[l[i] - 1]) * (sumv[r[i]] - sumv[l[i] - 1]);
	}
	return y;
}
int main()
{

	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
	}
	long long left = 0, right = 1e8, mid;
	long long ans = 1e13;
	while (left < right)
	{
		mid = right + left >> 1;
		if (check(mid) > s)
		{
			left = mid + 1;
		}
		else {
			right = mid;
		}
		ans = min(abs(check(mid) - s), ans);
	}
	cout << ans;
	return 0;
}