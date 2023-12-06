#include<iostream>
#include<algorithm>
using namespace std;
int a[50050];
const int mod = 1e9 + 7;
int main()
{
	int n;
	cin >> n;
	int m;
	int ma = -1e9;
	int mi = 1e9;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a[m]++;
		ma = max(ma, m);
		mi = min(mi, m);
	}
	 long long ans = 0;
	for (int i = mi; i <= ma; i++)
	{
		if (a[i] >= 2)
		{
			for (int j = mi=1; j <= i/2; j++)
			{
				if (a[i - j] && a[j]) {
					if (i - j == j && a[j] >= 2) {
						ans += (a[i] * (a[i] - 1) / 2 * a[j] * (a[j] - 1) / 2) % mod;
					}
					if (i - j != j) {
						ans +=( a[i] * (a[i] - 1) / 2 * a[i - j] * a[j]) % mod;
					}
				}
			}
		}
	}
	cout << ans % mod;
	return 0;
}