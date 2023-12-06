#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const long long N = 1e7 + 9;
long long sum=0, n, m,a[N];
long long score;
long long find(long long x)
{
	long long l=1, r=m, mid;/////////////
	long long ans = 1e9;////////////
	while (l <= r)////
	{
		mid = l + r >> 1;/////////////
		if (a[mid] >= x)
		{
			r = mid-1;
			ans = min(abs(score - a[mid]), ans);
		}
		else {
			l = mid + 1;
			ans = min(abs(score - a[mid]), ans);
		}
	}
	return ans;
}
int main()
{
	cin >> m >> n;
	for (long long i = 1; i <= m; i++)cin >> a[i];
	sort(a+1, a + m+1);
	while (n--)
	{
		cin >> score;
		sum +=find(score);
	}
	cout << sum;
	return 0;
}