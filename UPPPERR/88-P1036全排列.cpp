#include<iostream>
#include<cstdio>
using namespace std;
int a[1000];
bool zi(int x)
{
	if (x == 1) { return 0; }
	if (x == 2) { return 1; }
	for (int i = 2; i * i <= x; i++) {
		if (!(x % i)) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int U = 1 << n;
	int num = 0;
	int ans = 0;
	
	for (int i = 0; i < U; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) {
				num++;
			}
		}
		if (num == m)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j)) {
					sum += a[j];
				}
			}
			if (zi(sum)) {
				ans++;
			}
		}
		num = 0;
	}
	cout << ans;
	return 0;
}