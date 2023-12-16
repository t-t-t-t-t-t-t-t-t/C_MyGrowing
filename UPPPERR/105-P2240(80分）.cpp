#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct coin {
	double w, v, p;
}a[10005];
bool cmp(coin a,coin b)

{
	return a.p > b.p;
}
int main()
{
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].w >> a[i].v;
		a[i].p =  a[i].v /a[i].w;
	}
	sort(a , a + m,cmp);
	int sum = 0;
	double ans = 0;
	int po = 0;
	while (sum < n)
	{
		ans += a[po].p * a[po].w;
		sum += a[po].w;
		po++;
	}
	po--;
	if (sum > n)
	{
		ans -= (sum - n) * a[po].p;
	}
	cout <<fixed<<setprecision(2)<< ans;
	return 0;
}