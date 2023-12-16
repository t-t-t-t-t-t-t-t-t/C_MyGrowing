#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const long long N = 2e5 + 9;
vector<long long>X;
long long l[N], r[N], d[N];
long long po(long long x)
{
	return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}
int main()
{
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		X.push_back(l[i]);
		X.push_back(r[i]);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for (long long i = 1; i <= n; i++)
	{
		d[po(l[i])]++;
		d[po(r[i])]--;
	}
	for (long long i = 1; i <= X.size(); i++)
	{
		d[i] += d[i - 1];
	}
	long long ans = 0; long long l = 0, r = X.size();
	for (long long i = 1; i <= X.size(); i++)
	{
		if (d[i] != 0 && d[i - 1] == 0) { l = i - 1; }
		if (d[i] == 0 && d[i - 1] != 0) { r = i - 1; ans += X[r] - X[l]; }
	}
	cout << ans;
	return 0;
}