#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct coin {
	double w, v;
}a[10005];
bool cmp(coin a,coin b)
{
	return a.v*1.0/a.w*1.0 > b.v*1.0/b.w*1.0;
}
int main()
{
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].w >> a[i].v;
	}
	sort(a , a + m,cmp);
	int sum = 0;
	double ans = 0;
	for (int i = 0; i < m; i++) {
		if (sum < n) {
			ans += a[i].v;
			sum += a[i].w;
		}
		else {
			ans-= (sum - n) * (a[i-1].v * 1.0 / a[i-1].w * 1.0);
			break;
		}
	}
	cout <<fixed<<setprecision(2)<< ans;
	return 0;
}