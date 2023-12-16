#include<iostream>
#include<vector>
using namespace std;
const int N = 2e5 + 9;
vector<int>X;
int n;
int a[N], t[N],td[N],tdi[N];
int lowbit(int x){return -x & x;}
void update(int k, int x)
{
	for (int i = k; i <= n; i+=lowbit(i))td[i] += x,tdi[i]+=x*k;
}
int getsum(int x)
{
	int sum = 0;
	for (int i = x; i >0; i-=lowbit(i))
	{
		sum += (x + 1) * td[i] - tdi[i];
	}
	return sum;
}

int main()
{
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)update(i, a[i]), update(i + 1, -a[i]);
	while (m--) {
		int p; cin >> p;
		if (p == 1)
		{
			int l, r,k; cin >> l>> r>>k;
			update(l, k);
			update(r + 1, -k);
		}
		else {
			int l, r; cin >> l >> r;
			cout << getsum(r) - getsum(l - 1)<<'\n';
		}
	}
	return 0;
}