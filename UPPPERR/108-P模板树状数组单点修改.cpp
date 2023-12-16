#include<iostream>
using namespace std;
const int N= 3e5+9;
long long a[N], t[N];
long long n;
long long lowbit(long long x) { return -x & x; }
void update(long long po, long long x)
{
	for (long long i = po; i <= n; i+=lowbit(i))t[i] += x;
}
long long sum(long long x)
{
	long long all = 0;
	for (long long i = x; i >0; i -= lowbit(i))
	{
		all += t[i];
	}
	return all;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long m;
     cin >> n>>m;
	 for (long long i = 1; i <= n; i++)
	 {
		 cin >> a[i];
		 update(i, a[i]);
	 }
	while(m--)
	{
		long long cnt;
		cin >> cnt;
		if (cnt == 1) {
			long long po, x;
			cin >> po >> x;
			update(po, x);
		}
		else {
			long long l, r;
			cin >> l >> r;
			cout << sum(r) - sum(l - 1)<<'\n';
		}
	}
	return 0;
}