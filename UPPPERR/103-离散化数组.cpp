#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const long long N = 2e6 + 9;
long long a[N];
vector<long long>X;
struct mm {
	long long a, b;
}add[N], dis[N];
long long po(long long x)
{
	return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}
int main()
{
	long long m, n, p, w;
	cin >> m >> n;
	for (long long i = 1; i <= m; i++)
	{
		cin >> p >> w;
		add[i] = { p,w };
		X.push_back(p);
	}
	long long l, r;
	for (long long i = 1; i <= n; i++)
	{
		cin >> l >> r;
		dis[i] = { l,r };
		X.push_back(l);
		X.push_back(r);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for (long long i = 1; i <=m; i++)
	{
		a[po(add[i].a)]+=add[i].b;
	}
	for (long long i = 1; i <= X.size(); i++)a[i] += a[i - 1];
	for (long long i = 1; i <= n; i++)
	{
		cout << a[po(dis[i].b)] - a[po(dis[i].a)-1]<<'\n';
	}
	return 0;
}