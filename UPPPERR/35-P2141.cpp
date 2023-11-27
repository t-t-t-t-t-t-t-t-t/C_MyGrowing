#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[105],c[1000000],t[1000000];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		c[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1;j<n; j++)
		{
			t[a[i] + a[j]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 20005; i++)
	{
		if (c[i] &&t[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}